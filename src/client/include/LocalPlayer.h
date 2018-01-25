/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#ifndef TASK_04_ALL_ONLINEPLAYER_H
#define TASK_04_ALL_ONLINEPLAYER_H
#include "Player.h"
#include <limits.h>
#include <math.h>
#include "Player.h"
#include "Logic.h"
#include "Client.h"

class LocalPlayer : public Player {
 public:
  /**
   * Constructor.
   * @param name the name of the player.
   */
  LocalPlayer(Client &client,Player &player);
  /**
   * Asks the player to make a move.
   *
   * @param possible_moves the player possible moves.
   * @param printer the printer in order to communicate with the player.
   * @return the chosen position of the player.
   */
  virtual Position MakeAMove(vector<Position> &possible_moves, Printer &printer, PlayerColor color);

 private:
  Player &player_;
  Client &client_;
};

#endif //TASK_04_ALL_ONLINEPLAYER_H
