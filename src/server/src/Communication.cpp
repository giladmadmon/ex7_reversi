/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#include "../include/Communication.h"

int Communication::SendMsg(int client_socket, const string &msg) {
  int n;

  n = write(client_socket, &msg[0], sizeof(char));
  for (int i = 0; i < msg.size(); ++i) {
    if (n == FAILURE) {
      return FAILURE;
    }

    n = write(client_socket, &msg[i + 1], sizeof(char));
  }
  return SUCCESS;
}

int Communication::ReadMsg(int client_socket, string &msg) {
  ostringstream convert;
  char readChar= '\0';
  int n;

  n = read(client_socket, &readChar, sizeof(char));
  while (readChar != '\0') {
    if (n == FAILURE) {
      return FAILURE;
    }
    convert << readChar;
    n = read(client_socket, &readChar, sizeof(char));
  }

  msg = convert.str();

  return SUCCESS;
}

