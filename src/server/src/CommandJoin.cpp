/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#include "../include/Convert.h"
#include "../include/Communication.h"
#include "../include/CommandJoin.h"

void CommandJoin::execute(vector<string> args) {
  if (args.size() >= 2) {
    int size = args.size();
    int client_socket = Convert::ConvertStringToInt(args[size - 1]);
    string name = args[0];

    if (game_manager_->Join(client_socket, name) == SUCCESS) {
      Communication::SendMsg(client_socket, COMMAND_SUCCESS_MSG);
    } else {
      Communication::SendMsg(client_socket, COMMAND_FAILURE_MSG);
    }
  }
}
CommandJoin::CommandJoin() {
  game_manager_ = GameManager::Instance();
}
