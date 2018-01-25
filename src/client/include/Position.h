/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#ifndef TASK_02_POSITION_H
#define TASK_02_POSITION_H

#define POSITION_DELIMITER " "

#include <iostream>
using namespace std;

class Position {
 public:
  /**
     * Constructor.
     *
     * @param row the row of the position. Default is 0.
     * @param col the column of the position. Default is 0.
     */
  Position(int row = 0, int col = 0);
  /**
   * @return the row of the position.
   */
  int GetRow() const;
  /**
   * @return the column of the position.
   */
  int GetColumn() const;

  /**
   * override '==' operator.
   *
   * @param position the position to compare with.
   * @return true if both positions are equal, false otherwise.
   */
  bool operator==(const Position &position) const;

  friend ostream& operator<<(ostream& os, const Position& pos);
 private:
  int row_;
  int column_;

};

#endif //TASK_02_POSITION_H
