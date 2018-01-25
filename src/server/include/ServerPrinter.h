/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#ifndef TASK_04_FINAL_SERVERPRINTER_H
#define TASK_04_FINAL_SERVERPRINTER_H

#include <vector>
using namespace std;

//interface


class ServerPrinter {
 public:

  /**
   * Prints that the server in on air
   */
  virtual void PrintServer() = 0;

  /**
   * Prints that the server is waiting for connection
   */
  virtual void PrintWaitingServer() = 0;

  /**
   * Prints that the server had an error telling the clients who turn it is
   */
  virtual void PrintErrorServerTurns() = 0;

  /**
   * Prints that the first client connected to server
   */
  virtual void PrintFirstConnection() = 0;

  /**
   * Prints that the second client connected to server
   */
  virtual void PrintSecondConnection() = 0;

  /**
   * Prints that there was an error reading the message
   */
  virtual void PrintErrorReadMsg() = 0;

  /**
   * Prints that the client disconnected to server
   */
  virtual void PrintClientDisconnected() = 0;

};

#endif //TASK_04_FINAL_SERVERPRINTER_H
























