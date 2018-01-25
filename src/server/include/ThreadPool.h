/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#ifndef TASK_07_THREADPOOL_H
#define TASK_07_THREADPOOL_H

#include "Task.h"
#include <queue>
#include <pthread.h>
using namespace std;
class ThreadPool {
 public:
  ThreadPool(int threads_num);
  void addTask(Task *task);
  void terminate();
  virtual ~ThreadPool();
 private:
  int threads_num_;
  queue<Task *> tasksQueue;
  pthread_t* threads;
  void executeTasks();
  bool stopped;
  pthread_mutex_t lock;
  static void *execute(void *arg);
};

#endif //TASK_07_THREADPOOL_H
