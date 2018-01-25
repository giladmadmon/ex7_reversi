/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#ifndef TASK_04_FINAL_CONSOLESERVERPRINTER_H
#define TASK_04_FINAL_CONSOLESERVERPRINTER_H

#include "ServerPrinter.h"

class ConsoleServerPrinter : public ServerPrinter {
 public:

  /**
   * Constructor.
   */
  ConsoleServerPrinter();

  /**
   * Prints that the server in on air
   */
  virtual void PrintServer();

  /**
   * Prints that the server is waiting for connection
   */
  virtual void PrintWaitingServer();

  /**
   * Prints that the server had an error telling the clients who turn it is
   */
  virtual void PrintErrorServerTurns();

  /**
   * Prints that the first client connected to server
   */
  virtual void PrintFirstConnection();

  /**
   * Prints that the second client connected to server
   */
  virtual void PrintSecondConnection();

  /**
   * Prints that there was an error reading the message
   */
  virtual void PrintErrorReadMsg();

  /**
   * Prints that the client disconnected to server
   */
  virtual void PrintClientDisconnected();

};

#endif //TASK_04_FINAL_CONSOLESERVERPRINTER_H
