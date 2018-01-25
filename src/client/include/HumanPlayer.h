/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#ifndef TASK_02_HUMANPLAYER_H
#define TASK_02_HUMANPLAYER_H

#include <vector>
#include "Player.h"
#include "Position.h"
#include "Printer.h"
using namespace std;

class HumanPlayer : public Player {
 public:
  /**
   * Constructor.
   *
   * @param name the name of the player.
   */
  HumanPlayer() {}

  /**
   * Asks the player to make a move.
   *
   * @param possible_moves the player possible moves.
   * @param printer the printer in order to communicate with the player.
   * @return the chosen position of the player.
   */
  virtual Position MakeAMove(vector<Position> &possible_moves, Printer &printer, PlayerColor color);

 private:
  int KeyboardHit();
};

#endif //TASK_02_HUMANPLAYER_H
