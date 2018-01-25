/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#ifndef TASK_07_TASK_H
#define TASK_07_TASK_H

class Task {
 public:
  /**
  * constructor
  * @param func the handler function of the task
   * @param arg the arguments the the function
  */
  Task(void *(*func)(void *arg), void *arg) :
      func(func), arg(arg) {}
  /**
   * execute the task by calling the handler with its arguments.
   */
  void execute() {
    func(arg);
  }
  /**
   * destructor
   */
  virtual ~Task() {}
 private:
  void *(*func)(void *arg);
  void *arg;
};
#endif //TASK_07_TASK_H
