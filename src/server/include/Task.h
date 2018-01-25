/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#ifndef TASK_07_TASK_H
#define TASK_07_TASK_H

class Task {
 public:
  /**
  * constructor
  * @param func
   * @param arg
  */
  Task(void *(*func)(void *arg), void* arg) :
      func(func), arg(arg) {}
  void execute() {
    func(arg);
  }
  virtual ~Task() {}
 private:
  void *(*func)(void *arg);
  void *arg;
};
#endif //TASK_07_TASK_H
