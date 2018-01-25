/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#include "../include/Client.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <cstdlib>

#define SERVER_CLOSING "ServerClosing"
#define STRING_END '\0'

using namespace std;

Client::Client(const char *serverIP, int serverPort)
    : server_IP_(serverIP), server_port_(serverPort), client_socket_(0), color_(NoColor) {}

int Client::SendMsg(const string &msg) {
  int n;

  n = write(client_socket_, &msg[0], sizeof(char));
  for (int i = 0; i < msg.size(); ++i) {
    if (n == FAILURE) {
      return FAILURE;
    }

    n = write(client_socket_, &msg[i + 1], sizeof(char));
  }
  return SUCCESS;
}

int Client::ReadMsg(string &msg) {
  ostringstream convert;
  char readChar = STRING_END;
  int n;

  n = read(client_socket_, &readChar, sizeof(char));
  while (n != FAILURE && readChar != STRING_END) {
    convert << readChar;
    n = read(client_socket_, &readChar, sizeof(char));
  }

  if (n == FAILURE) {
    return FAILURE;
  }

  msg = convert.str();
  /*
  if (msg == SERVER_CLOSING)
    exit(0);
*/
  return SUCCESS;
}

void Client::connectToServer() {
  // Create a socket point
  client_socket_ = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket_ == -1) {
    throw "Error opening socket";
  }
  // Convert the ip string to a network address
  struct in_addr address;
  if (!inet_aton(server_IP_, &address)) {
    throw "Can't parse IP address";
  }
  // Get a hostent structure for the given host address
  struct hostent *server;
  server = gethostbyaddr((const void *) &address, sizeof address, AF_INET);
  if (server == NULL) {
    throw "Host is unreachable";
  }
  // Create a structure for the server address
  struct sockaddr_in serverAddress;
  bzero((char *) &address, sizeof(address));
  serverAddress.sin_family = AF_INET;
  memcpy((char *) &serverAddress.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
  // htons converts values between host and network byte orders
  serverAddress.sin_port = htons(server_port_);
  // Establish a connection with the TCP server
  if (connect(client_socket_, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
    throw "Error connecting to server";
  }
}
