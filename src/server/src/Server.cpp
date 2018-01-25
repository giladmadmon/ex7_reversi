/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#include <sys/socket.h>
#include <netinet/in.h>
#include <memory.h>
#include <unistd.h>
#include "../include/Server.h"
#include "../include/GameManager.h"

#define DEFAULT_THREADS_NUM 5

Server::Server(int port)
    : is_closed_(0),
      port_(port),
      server_socket_(0),
      client_handler_(ClientHandler()),
      thread_pool_(ThreadPool(DEFAULT_THREADS_NUM)) {
}

void Server::Start() {
  // Create a socket point
  server_socket_ = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket_ == -1) {
    throw "Error opening socket";
  }
  // Assign a local address to the socket
  struct sockaddr_in serverAddress;
  bzero((void *) &serverAddress,
        sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  serverAddress.sin_port = htons(port_);
  if (bind(server_socket_, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
    throw "Error on binding";
  }
  // Start listening to incoming connections
  listen(server_socket_, MAX_CONNECTED_CLIENTS);
}

void Server::Stop() {
  is_closed_ = 1;
  GameManager *game_manager = GameManager::Instance();
  game_manager->FinishAllGames();
  game_manager->CloseWaitingGames();
  thread_pool_.terminate();
  close(server_socket_);
}
int Server::WaitForConnection() {
  int client;
  // Define the client socket's structures
  struct sockaddr_in clientAddress;
  socklen_t clientAddressLen = 0;

  // Accept a new client connection
  client = accept(server_socket_, (struct sockaddr *) &clientAddress, &clientAddressLen);

  return client;
}

void *HandleClient(void *args) {
  ClientHandler *client_handler = (ClientHandler *) args;

  client_handler->Handle();
}

void Server::AcceptConnections() {
  while (!is_closed_) {

    client_handler_.AddSocketToQueue(WaitForConnection());

    Task *task = new Task(HandleClient, &client_handler_);
    thread_pool_.addTask(task);
  }
}
