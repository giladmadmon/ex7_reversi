/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#ifndef TASK_05_COMMUNICATION_H
#define TASK_05_COMMUNICATION_H

#include <unistd.h>
#include <sstream>

#define SUCCESS 1
#define FAILURE -1

using namespace std;

class Communication {
 public:
  /**
   * sends a message to a client socket
   * @param client_socket the client socket to send to message to
   * @param msg the message to sent
   * @return the status of the sent
   */
  static int SendMsg(int client_socket, const string &msg);
  /**
   * gets a message from a client socket
   * @param client_socket the client socket to receive the message from
   * @param msg contains the msg sent
   * @return the status of the sent
   */
  static int ReadMsg(int client_socket, string &msg);
};

#endif //TASK_05_COMMUNICATION_H
