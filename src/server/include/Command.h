/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#ifndef TASK_05_COMMAND_H
#define TASK_05_COMMAND_H

#include <iostream>
#include <vector>

#define ARGS_DELIMITER ' '
#define COMMAND_FAILURE_MSG "-1"
#define COMMAND_SUCCESS_MSG "1"
#define JOIN_GAME_COMMAND "join"
#define START_GAME_COMMAND "start"
#define LIST_GAMES_COMMAND "list_games"

using namespace std;

class Command {

 public:

  /**
  * Constructor.
  * @param server
  */
  Command() {}

  /**
  * execute the specific command.
  * @param args needed for the execution.
  */
  virtual void execute(vector<string> args) = 0;

  /**
   * Destructor.
   *
   */
  virtual ~Command() {}
};

#endif //TASK_05_COMMAND_H
