/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#include <vector>
#include "../include/PlayerColor.h"
#include "../include/Board.h"
#include "../include/Position.h"

using namespace ::std;

class BoardStates {
 public:
  void MidGameBoard(Board &board) {
    board.Reset();

    board.SetColorAtPosition(1, 4, Black);
    board.SetColorAtPosition(2, 4, Black);
    board.SetColorAtPosition(3, 4, Black);
    board.SetColorAtPosition(4, 4, Black);
    board.SetColorAtPosition(5, 4, Black);
    board.SetColorAtPosition(3, 6, Black);
    board.SetColorAtPosition(1, 5, White);
    board.SetColorAtPosition(2, 5, White);
    board.SetColorAtPosition(3, 5, White);
    board.SetColorAtPosition(4, 5, White);
    board.SetColorAtPosition(5, 5, White);
    board.SetColorAtPosition(3, 3, White);
    board.SetColorAtPosition(5, 3, White);
    board.SetColorAtPosition(5, 6, White);
    board.SetColorAtPosition(5, 7, White);
    board.SetColorAtPosition(6, 3, White);
    board.SetColorAtPosition(6, 4, White);
    board.SetColorAtPosition(7, 3, White);
  }

  void MidGameBoardBlack(Board &board) {
    board.Reset();
    MidGameBoard(board);

    board.SetColorAtPosition(5, 5, Black);
    board.SetColorAtPosition(5, 6, Black);
    board.SetColorAtPosition(5, 7, Black);
    board.SetColorAtPosition(5, 8, Black);
  }

  void MidGameBoardWhite(Board &board) {
    board.Reset();
    MidGameBoard(board);

    board.SetColorAtPosition(2, 3, White);
    board.SetColorAtPosition(2, 4, White);
    board.SetColorAtPosition(3, 4, White);
  }

  vector<Position> WhiteMidGamePossibleMoves() {
    vector<Position> possible_moves;

    possible_moves.push_back(Position(1, 3));
    possible_moves.push_back(Position(2, 3));
    possible_moves.push_back(Position(2, 7));
    possible_moves.push_back(Position(3, 7));
    possible_moves.push_back(Position(4, 3));
    possible_moves.push_back(Position(4, 7));

    return possible_moves;
  }

  vector<Position> BlackMidGamePossibleMoves() {
    vector<Position> possible_moves;

    possible_moves.push_back(Position(1, 6));
    possible_moves.push_back(Position(2, 2));
    possible_moves.push_back(Position(2, 6));
    possible_moves.push_back(Position(3, 2));
    possible_moves.push_back(Position(4, 2));
    possible_moves.push_back(Position(4, 6));
    possible_moves.push_back(Position(5, 2));
    possible_moves.push_back(Position(5, 8));
    possible_moves.push_back(Position(6, 2));
    possible_moves.push_back(Position(6, 6));
    possible_moves.push_back(Position(6, 7));
    possible_moves.push_back(Position(7, 2));
    possible_moves.push_back(Position(7, 4));

    return possible_moves;
  }

  void WhiteNoMovesBoard(Board &board) {
    EmptyBoard(board);

    board.SetColorAtPosition(1, 1, Black);
    board.SetColorAtPosition(2, 1, White);
  }

  void BlackNoMovesBoard(Board &board) {
    EmptyBoard(board);

    board.SetColorAtPosition(1, 1, White);
    board.SetColorAtPosition(2, 1, Black);
  }

  void NoMoreMoves(Board &board) {
    EmptyBoard(board);

    board.SetColorAtPosition(1, 1, White);
    board.SetColorAtPosition(8, 8, Black);
  }

  void EmptyBoard(Board &board) {
    board.Reset();

    board.SetColorAtPosition(4, 4, NoColor);
    board.SetColorAtPosition(4, 5, NoColor);
    board.SetColorAtPosition(5, 4, NoColor);
    board.SetColorAtPosition(5, 5, NoColor);
  }

  void BlackLeadsBoard(Board &board) {
    board.Reset();

    board.SetColorAtPosition(4, 4, NoColor);
  }

  void WhiteLeadsBoard(Board &board) {
    board.Reset();

    board.SetColorAtPosition(4, 5, NoColor);
  }

};