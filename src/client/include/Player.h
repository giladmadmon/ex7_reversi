/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#ifndef TASK_02_BASEPLAYER_H
#define TASK_02_BASEPLAYER_H

#include <iostream>
#include "Player.h"
#include "Printer.h"
using namespace std;
class Player {
 public:
  /**
   * Asks the player to make a move.
   *
   * @param possible_moves the player possible moves.
   * @param printer the printer in order to communicate with the player.
   * @return the chosen position of the player.
   */
  virtual Position MakeAMove(vector<Position> &possible_moves, Printer &printer, PlayerColor color) = 0;

};

#endif //TASK_02_BASEPLAYER_H
