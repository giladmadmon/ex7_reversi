/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#ifndef TASK_04_FINAL_REMOTEPLAYER_H
#define TASK_04_FINAL_REMOTEPLAYER_H

#include "Player.h"
#include "Client.h"

class RemotePlayer : public Player {
 private:
  Client &client_;
 public:
  RemotePlayer(Client &client);
  virtual Position MakeAMove(vector<Position> &possible_moves, Printer &printer, PlayerColor color);
};

#endif //TASK_04_FINAL_REMOTEPLAYER_H
