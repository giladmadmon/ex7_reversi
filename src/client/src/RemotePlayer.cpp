/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#include <vector>
#include "../include/Position.h"
#include "../include/Printer.h"
#include "../include/RemotePlayer.h"
#include "../../server/include/Convert.h"

Position RemotePlayer::MakeAMove(vector<Position> &possible_moves, Printer &printer, PlayerColor color) {
  string msg;
  int chosen_row = FAILURE, chosen_column = FAILURE;
  printer.PrintWaiting();
  int n = client_.ReadMsg(msg);

  if (n != FAILURE && msg != END_GAME_MSG){
    if (msg == NO_MOVE_MSG) {
      printer.PrintAINoMove(color);
      return Position();
    } else {
      int delimiter_pos = msg.find(POSITION_DELIMITER);
      chosen_row = Convert::ConvertStringToInt(msg, 0, delimiter_pos);
      chosen_column = Convert::ConvertStringToInt(msg, delimiter_pos + 1, msg.size());
    }
  }

  return Position(chosen_row, chosen_column);
}
RemotePlayer::RemotePlayer(Client &client) : client_(client) {}
