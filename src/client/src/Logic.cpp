/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#include "../include/Logic.h"

PlayerColor Logic::CurrentTurn() {
  return current_turn_;
}
Logic::Logic() {
  current_turn_ = NoColor;
}
