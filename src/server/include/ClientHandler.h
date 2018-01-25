/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#ifndef TASK_05_CLIENTHANDLER_H
#define TASK_05_CLIENTHANDLER_H

#include "CommandManager.h"

class ClientHandler {
 public:
 /**
  * Constructor
  */
  ClientHandler();
  /**
   * Destructor
   */
  ~ClientHandler();
  /**
   * adds client socket to the socket queue
   * @param client_socket the socket to be added
   */
  void AddSocketToQueue(int client_socket);
  /**
   * closes the the games created and free their memory
   */
  void CloseAll();
  /**
   * handle one client request
   */
  void Handle();
 private:
  CommandManager *command_manager_;
  vector<int> sockets_queue_;
  pthread_mutex_t socket_queue_mutex_;
  /**
   * removes a client socket from the queue and return it
   * @return the client socket removed from the sockets queue
   */
  int RemoveSocketFromQueue();
};

#endif //TASK_05_CLIENTHANDLER_H
