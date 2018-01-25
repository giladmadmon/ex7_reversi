/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#ifndef TASK_07_THREADPOOL_H
#define TASK_07_THREADPOOL_H

#include "Task.h"
#include <queue>
#include <pthread.h>
using namespace std;
class ThreadPool {
 public:
  /**
   * constructor
   *
   * @param threads_num the number of threads to create in the pool.
   */
  ThreadPool(int threads_num);
  /**
   * add a task for the thread pool to execute.
   *
   * @param task the task to execute.
   */
  void addTask(Task *task);
  /**
   * terminate the thread pool by canceling the threads.
   */
  void terminate();
  /**
   * destructor
   *
   * destruct all the unfinished tasks.
   */
  virtual ~ThreadPool();
 private:
  int threads_num_;
  queue<Task *> tasksQueue;
  pthread_t *threads;
  /**
   * make each thread execute a task in its turn.
   */
  void executeTasks();
  bool stopped;
  pthread_mutex_t lock;
  /**
   * the operation of each thread in the thread pool.
   */
  static void *execute(void *arg);
};

#endif //TASK_07_THREADPOOL_H
