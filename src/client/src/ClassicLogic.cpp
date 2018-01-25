/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#include <iostream>
#include <vector>
#include "../include/ClassicLogic.h"

using namespace std;

PlayerColor ClassicLogic::StartingPlayer() {
  return Black;
}
PlayerColor ClassicLogic::NextTurn(bool new_game, Board &board) {
  if (GameOver(board)) {
    return NoColor;
  }

  if (new_game) {
    current_turn_ = Black;
    return current_turn_;
  }

  current_turn_ = OtherColor(current_turn_);
  return current_turn_;
}
PlayerColor ClassicLogic::GetWinner(Board &board) {
  int black_num = board.CountColor(Black);
  int white_num = board.CountColor(White);

  if (black_num > white_num) {
    return Black;
  } else if (white_num > black_num) {
    return White;
  } else {
    return NoColor;
  }
}
vector<Position> ClassicLogic::PossibleMoves(PlayerColor player, Board &board) {
  vector<Position> possible_positions;
  for (int i = 1; i <= board.GetSize(); ++i) {
    for (int j = 1; j <= board.GetSize(); ++j) {
      if (board.GetColorAtPosition(i, j) == NoColor && !CheckAllDirections(OtherColor(player), i, j, board).empty()) {
        possible_positions.push_back(Position(i, j));
      }
    }
  }
  return possible_positions;
}

vector<vector<int> > ClassicLogic::CheckAllDirections(PlayerColor rival_color, int row, int col, Board &board) {
  vector<vector<int> > possible_directions;

  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i != 0 || j != 0) {
        if (CheckOneDirection(rival_color, row, col, i, j, board)) {
          vector<int> direction;
          direction.push_back(i);
          direction.push_back(j);

          possible_directions.push_back(direction);
        }
      }
    }
  }

  return possible_directions;
}

bool ClassicLogic::GameOver(Board &board) {
  vector<Position> black_moves = PossibleMoves(Black, board);
  vector<Position> white_moves = PossibleMoves(White, board);

  return black_moves.empty() && white_moves.empty();
}

bool ClassicLogic::CheckOneDirection(PlayerColor rival_color,
                                     int row,
                                     int col,
                                     int row_change,
                                     int col_change,
                                     Board &board) {
  int first_row_check = row + row_change, first_col_check = col + col_change;

  for (int next_row = first_row_check, next_column = first_col_check;;
       next_row += row_change, next_column += col_change) {
    if (next_column <= 0 || next_column > board.GetSize() || next_row <= 0 || next_row > board.GetSize()) {
      return false;
    }

    PlayerColor next_color = board.GetColorAtPosition(next_row, next_column);

    if (next_color == NoColor) {
      return false;
    }

    if (next_color == OtherColor(rival_color)) {
      // is it the nearest position to the check cell?
      return next_row != first_row_check || next_column != first_col_check;
    }

  }
}

void ClassicLogic::PlaceAToken(PlayerColor color, int row, int col, Board &board) {
  vector<vector<int> > directions = CheckAllDirections(OtherColor(color), row, col, board);

  for (vector<vector<int> >::iterator it = directions.begin(); it != directions.end(); ++it) {
    int row_change = it.base()->at(0), col_change = it.base()->at(1);

    for (int next_row = row, next_column = col;;
         next_row += row_change, next_column += col_change) {
      PlayerColor next_color = board.GetColorAtPosition(next_row, next_column);

      if (next_color == color && (next_row != row || next_column != col)) {
        break;
      }

      board.SetColorAtPosition(next_row, next_column, color);
    }
  }
}
