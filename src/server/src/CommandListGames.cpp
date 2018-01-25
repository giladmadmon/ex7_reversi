/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#include <unistd.h>
#include "../include/CommandListGames.h"
#include "../include/Convert.h"
#include "../include/Communication.h"

void CommandListGames::execute(vector<string> args) {
  ostringstream result;
  int args_size = args.size();

  if (args_size >= 1) {
    vector<string> game_names = game_manager_->GameList();
    int games_size = game_names.size();
    int client_socket = Convert::ConvertStringToInt(args[args_size - 1]);

    if (games_size > 0) {
      result << game_names[0];
      for (int i = 1; i < games_size; i++) {
        result << ARGS_DELIMITER << game_names[i];
      }
    }

    Communication::SendMsg(client_socket, result.str());
    close(client_socket);
  }
}
CommandListGames::CommandListGames() {
  game_manager_ = GameManager::Instance();
}
