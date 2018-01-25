/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/



#include "../include/LocalPlayer.h"

using namespace std;

Position LocalPlayer::MakeAMove(vector<Position> &possible_moves,
                                Printer &printer,
                                PlayerColor color) {

  Position position = player_.MakeAMove(possible_moves, printer, color);
  if (possible_moves.empty()) {
    if (client_.SendMsg(NO_MOVE_MSG) < 0)
      return Position(FAILURE, FAILURE);
  } else {
    ostringstream convert;
    convert << position;
    if (client_.SendMsg(convert.str()) < 0)
      return Position(FAILURE, FAILURE);
  }

  return position;
}
LocalPlayer::LocalPlayer(Client &client, Player &player) : client_(client), player_(player) {}