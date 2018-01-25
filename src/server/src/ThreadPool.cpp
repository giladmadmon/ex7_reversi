/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/
#include "../include/ThreadPool.h"

#include <unistd.h>
ThreadPool::ThreadPool(int threads_num) :
    stopped(false),threads_num_(threads_num){
  threads = new pthread_t[threads_num];
  pthread_mutex_init(&lock, NULL);
  for (int i = 0; i < threads_num; i++) {
    pthread_create(threads + i, NULL, execute,
                   this);
  }
}

void* ThreadPool::execute(void *arg) {
  ThreadPool *pool = (ThreadPool *)arg;
  pool->executeTasks();
}
void ThreadPool::addTask(Task *task) {
  tasksQueue.push(task);
}
void ThreadPool::executeTasks() {
  while (!stopped) {
    pthread_mutex_lock(&lock);
    if (!tasksQueue.empty()) {
      Task* task = tasksQueue.front();
      tasksQueue.pop();
      pthread_mutex_unlock(&lock);
      task->execute();
      delete task;
    }
    else {
      pthread_mutex_unlock(&lock);
      sleep(1);
    }
  }
}
void ThreadPool::terminate() {
  stopped = true;
  for (int i = 0; i < threads_num_; ++i) {
    pthread_cancel(threads[i]);
  }
  pthread_mutex_destroy(&lock);
}
ThreadPool::~ThreadPool() {
  Task *task;
  while (!tasksQueue.empty()){
    task = tasksQueue.front();
    tasksQueue.pop();
    delete task;
  }
  delete[] threads;
}