/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#include "../include/Board.h"

Board::Board(int size) {
  this->size_ = size;
  this->board_ = new PlayerColor *[size];
  for (int i = 0; i < size; ++i) {
    this->board_[i] = new PlayerColor[size];
  }

  Reset();
}

void Board::Reset() {
  int mid_size = size_ / 2;

  for (int i = 0; i < size_; i++) {
    for (int j = 0; j < size_; j++) {
      this->board_[i][j] = NoColor;
    }
  }

  SetColorAtPosition(mid_size, mid_size + 1, Black);
  SetColorAtPosition(mid_size + 1, mid_size, Black);
  SetColorAtPosition(mid_size + 1, mid_size + 1, White);
  SetColorAtPosition(mid_size, mid_size, White);
}

void Board::SetColorAtPosition(int row, int col, PlayerColor color) {
  this->board_[row - 1][col - 1] = color;
}

PlayerColor Board::GetColorAtPosition(int row, int col) {
  return board_[row - 1][col - 1];
}

int Board::CountColor(PlayerColor color) {
  int count = 0;

  for (int i = 0; i < size_; ++i) {
    for (int j = 0; j < size_; ++j) {
      if (board_[i][j] == color) {
        count++;
      }
    }
  }

  return count;
}

Board::~Board() {
  for (int i = 0; i < size_; ++i) {
    delete[] this->board_[i];
  }
  delete[] this->board_;
}

int Board::GetSize() {
  return size_;
}

Board::Board(const Board &old_board) {
  this->size_ = old_board.size_;
  this->board_ = new PlayerColor *[size_];
  for (int i = 0; i < size_; ++i) {
    this->board_[i] = new PlayerColor[size_];
  }

  for (int i = 0; i < size_; ++i) {
    for (int j = 0; j < size_; ++j) {
      board_[i][j] = old_board.board_[i][j];
    }
  }
}

bool Board::operator==(const Board &board) const {
  if (this->size_ != board.size_) {
    return false;
  }

  for (int i = 0; i < this->size_; ++i) {
    for (int j = 0; j < this->size_; ++j) {
      if (this->board_[i][j] != board.board_[i][j]) {
        return false;
      }
    }
  }

  return true;
}

bool Board::operator!=(const Board &board) const {
  return !(*this == board);
}
