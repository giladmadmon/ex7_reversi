/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#include "../include/CommandManager.h"
#include "../include/CommandStart.h"
#include "../include/CommandListGames.h"
#include "../include/CommandJoin.h"

CommandManager::CommandManager() {
  command_map_[START_GAME_COMMAND] = new CommandStart();
  command_map_[LIST_GAMES_COMMAND] = new CommandListGames();
  command_map_[JOIN_GAME_COMMAND] = new CommandJoin();
}

CommandManager::~CommandManager() {
  for (map<string, Command *>::iterator it = command_map_.begin(); it != command_map_.end(); it++) {
    delete it->second;
  }
}
void CommandManager::ExecuteCommand(string command, vector<string> args) {
  Command *command_obj = command_map_[command];
  if (command_obj != NULL) {
    command_obj->execute(args);
  }
}
