/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#ifndef TASK_05_COMMANDJOIN_H
#define TASK_05_COMMANDJOIN_H
#include "Command.h"
#include "GameManager.h"

class CommandJoin : public Command {
 private:
  GameManager *game_manager_;

 public:

  /**
  * Constructor.
  * @param client
  */
  CommandJoin();

  /**
  * execute the specific command.
  * @param args needed for the execution.
  */
  virtual void execute(vector<string> args);

  /**
   * Destructor.
   *
   */
  virtual ~CommandJoin() {}
};

#endif //TASK_05_COMMANDJOIN_H
