/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#include "../include/Position.h"

Position::Position(int row, int col) {
  this->row_ = row;
  this->column_ = col;
}
int Position::GetRow() const {
  return this->row_;
}
int Position::GetColumn() const {
  return this->column_;
}
bool Position::operator==(const Position &position) const {
  return this->GetRow() == position.GetRow() && this->GetColumn() == position.GetColumn();
}
ostream &operator<<(ostream &os, const Position &pos) {
  os << pos.GetRow() << POSITION_DELIMITER << pos.GetColumn();
  return os;
}
