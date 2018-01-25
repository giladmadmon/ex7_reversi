/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#ifndef TASK_05_START_H
#define TASK_05_START_H
#include "Command.h"
#include "GameManager.h"
class CommandStart : public Command {
 private:
  GameManager *game_manager_;

 public:

  /**
  * Constructor.
  * @param client
  */
  CommandStart();
  virtual void execute(vector<string> args);

  /**
   * Destructor.
   *
   */
  virtual ~CommandStart() {}
};

#endif //TASK_05_START_H
