/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "BoardStates.h"
#include "../include/ClassicLogic.h"

using namespace std;

class ClassicLogicTest : public testing::Test {
 public:
  virtual void SetUp() {
    ClassicLogicTest::logic_ = ClassicLogic();
    board_states_ = BoardStates();
    board_ = new Board();
  }

  virtual void TearDown() {
  }

 protected:
  Board *board_;
  BoardStates board_states_;
  ClassicLogic logic_;
  virtual bool CheckMoves(vector<Position> &wanted_moves, PlayerColor player_color, Board &board);
};

bool ClassicLogicTest::CheckMoves(vector<Position> &wanted_moves, PlayerColor player_color, Board &board) {
  vector<Position> possible_moves = logic_.PossibleMoves(player_color, board);
  bool is_good = wanted_moves.size() == possible_moves.size();

  for (vector<Position>::iterator it = wanted_moves.begin(); it != wanted_moves.end(); ++it) {
    is_good = is_good && (std::find(possible_moves.begin(), possible_moves.end(), *it) != possible_moves.end());
  }

  return is_good;
}

// tests the possible moves of the Black player and the White player in the start of the game
TEST_F(ClassicLogicTest, PossibleMovesStart) {
  vector<Position> wanted_moves;

  wanted_moves.push_back(Position(4, 3));
  wanted_moves.push_back(Position(3, 4));
  wanted_moves.push_back(Position(5, 6));
  wanted_moves.push_back(Position(6, 5));

  EXPECT_TRUE(CheckMoves(wanted_moves, Black, *board_));

  wanted_moves.clear();
  wanted_moves.push_back(Position(3, 5));
  wanted_moves.push_back(Position(4, 6));
  wanted_moves.push_back(Position(5, 3));
  wanted_moves.push_back(Position(6, 4));

  EXPECT_TRUE(CheckMoves(wanted_moves, White, *board_));
}

// tests the possible moves of the Black player and the White player when both have no moves
TEST_F(ClassicLogicTest, PossibleMovesNoMoves) {
  board_states_.EmptyBoard(*board_);
  vector<Position> wanted_moves;

  EXPECT_TRUE(CheckMoves(wanted_moves, Black, *board_));
  EXPECT_TRUE(CheckMoves(wanted_moves, White, *board_));
}

// tests the possible moves of the Black player and the White player in a certain situation of the game
TEST_F(ClassicLogicTest, PossibleMovesMidGame) {
  board_states_.MidGameBoard(*board_);
  vector<Position> wanted_moves = board_states_.BlackMidGamePossibleMoves();

  EXPECT_TRUE(CheckMoves(wanted_moves, Black, *board_));

  wanted_moves = board_states_.WhiteMidGamePossibleMoves();

  EXPECT_TRUE(CheckMoves(wanted_moves, White, *board_));
}

// tests the GetWInner function
TEST_F(ClassicLogicTest, GetWinnerNoTie) {
  board_states_.EmptyBoard(*board_);
  EXPECT_EQ(NoColor, logic_.GetWinner(*board_));

  board_states_.WhiteLeadsBoard(*board_);
  EXPECT_EQ(White, logic_.GetWinner(*board_));

  board_states_.BlackLeadsBoard(*board_);
  EXPECT_EQ((int) Black, logic_.GetWinner(*board_));
}


// tests the StartingPlayer function at the start of the game
TEST_F(ClassicLogicTest, StartingPlayer) {
  EXPECT_EQ((int) Black, logic_.StartingPlayer());
}



// tests the GameOver function at the middle of the game
TEST_F(ClassicLogicTest, GameOverMidGame) {
  Board board;

  // game should not end
  board.Reset();
  EXPECT_FALSE(logic_.GameOver(board));

  board_states_.MidGameBoard(board);
  EXPECT_FALSE(logic_.GameOver(board));

  board_states_.BlackNoMovesBoard(board);
  EXPECT_FALSE(logic_.GameOver(board));

  board_states_.WhiteNoMovesBoard(board);
  EXPECT_FALSE(logic_.GameOver(board));

  // game should end
  board_states_.EmptyBoard(board);
  EXPECT_TRUE(logic_.GameOver(board));

  board_states_.NoMoreMoves(board);
  EXPECT_TRUE(logic_.GameOver(board));

}

// tests the PlaceAToken function
TEST_F(ClassicLogicTest, PlaceAToken) {
  Board board;

  board_states_.MidGameBoard(*board_);
  logic_.PlaceAToken(Black, 5, 8, *board_); // will flip 5,5 5,6 5,7
  board_states_.MidGameBoardBlack(board);

  EXPECT_EQ(*board_, board);

  board_states_.MidGameBoard(*board_);
  EXPECT_NE(*board_, board);

  logic_.PlaceAToken(White, 2, 3, *board_); // will flip 2,4 3,4
  board_states_.MidGameBoardWhite(board);

  EXPECT_EQ(*board_, board);

  board_states_.MidGameBoard(*board_);
  EXPECT_NE(*board_, board);
}
