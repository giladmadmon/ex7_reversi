/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#include "../include/ClientHandler.h"
#include "../include/Communication.h"
#include "../include/Convert.h"
#include "../include/GameManager.h"
ClientHandler::ClientHandler() {
  command_manager_ = new CommandManager();
  pthread_mutex_init(&socket_queue_mutex_, NULL);
}

void ClientHandler::Handle() {
  string msg, command;
  int delimiter_pos, prv_delimiter_pos = 0;
  vector<string> args;
  int client_socket = RemoveSocketFromQueue();

  Communication::ReadMsg(client_socket, msg);

  delimiter_pos = msg.find(ARGS_DELIMITER);
  while (delimiter_pos != string::npos) {
    args.push_back(msg.substr(prv_delimiter_pos, delimiter_pos - prv_delimiter_pos));
    prv_delimiter_pos = delimiter_pos + 1;
    delimiter_pos = msg.find(ARGS_DELIMITER, delimiter_pos + 1);
  }
  args.push_back(msg.substr(prv_delimiter_pos));
  args.push_back(Convert::ConvertIntToString(client_socket));

  command = args[0];
  args.erase(args.begin());

  command_manager_->ExecuteCommand(command, args);
}
void ClientHandler::CloseAll() {
  GameManager *game_manager = GameManager::Instance();
}
ClientHandler::~ClientHandler() {
  delete command_manager_;
}
void ClientHandler::AddSocketToQueue(int client_socket) {
  pthread_mutex_lock(&socket_queue_mutex_);
  sockets_queue_.push_back(client_socket);
  pthread_mutex_unlock(&socket_queue_mutex_);
}
int ClientHandler::RemoveSocketFromQueue() {
  int client_socket = 0;
  pthread_mutex_lock(&socket_queue_mutex_);
  if (sockets_queue_.size() > 0) {
    client_socket = sockets_queue_.at(0);
    sockets_queue_.erase(sockets_queue_.begin());
  }
  pthread_mutex_unlock(&socket_queue_mutex_);
  return client_socket;
}
