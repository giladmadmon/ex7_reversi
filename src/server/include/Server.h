/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#ifndef TASK_05_GAMEMANAGER_H
#define TASK_05_GAMEMANAGER_H

#define MAX_CONNECTED_CLIENTS 30

#include <string>
#include "ServerPrinter.h"
#include "ClientHandler.h"
#include "ThreadPool.h"

class Server {
 public:
  /**
   * constructor
   * @param port the port of the server
   */
  Server(int port);
  /**
   * start the server. open it for accepting clients
   */
  void Start();
  /**
   * accepts client connections
   */
  void AcceptConnections();
  /**
   * stop the server operations
   */
  void Stop();
  /**
   * wait for new client connection
   * @return the client socket
   */
  int WaitForConnection();

 private:
  int is_closed_;
  int port_;
  int server_socket_; // the socket's file descriptor
  ClientHandler client_handler_;
  ThreadPool thread_pool_;

};

#endif //TASK_05_GAMEMANAGER_H
