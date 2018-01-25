/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#include "../include/Game.h"
#include "../include/Communication.h"
#include "../include/GameManager.h"

using namespace std;
#define FIRST_TURN "1"
#define SECOND_TURN "2"

typedef struct {
  pthread_t thread;
  Game *game;
} EndGameArgs;

static void *DeleteGame(void *args) {
  EndGameArgs *end_game_args = (EndGameArgs *) args;

  pthread_join(end_game_args->thread, NULL);
  GameManager::Instance()->GameEnded(end_game_args->game);

  delete end_game_args;
}

void Game::Play() {
  int n;

  n = TellTurn(first_client_socket_, second_client_socket_);
  if (n == 0) {
    return;
  }

  GameStatus status = PLAYING;
  int currentClient = first_client_socket_, otherClient = second_client_socket_;
  while (status != GAME_ENDED && status != CLIENT_DISCONNECTED) {
    status = PlayOneTurn(currentClient, otherClient);

    switch (status) {
      case ERROR: return;
      case NO_MOVE:
      case PLAYING:SwapClients(currentClient, otherClient);
        break;
      case CLIENT_DISCONNECTED:
      case GAME_ENDED:break;
    }

  }

  // Close communication with the client
  close(first_client_socket_);
  close(second_client_socket_);

  thread_t thread;
  EndGameArgs *args = new EndGameArgs;
  args->thread = pthread_self();
  args->game = this;
  pthread_create(&thread, NULL, DeleteGame, args);
}

void Game::SwapClients(int &currentClient, int &otherClient) {
  int tempClient = currentClient;
  currentClient = otherClient;
  otherClient = tempClient;
}

int Game::TellTurn(int firstClientSocket, int secondClientSocket) {
  int n;
  n = Communication::SendMsg(firstClientSocket, FIRST_TURN);
  if (n == -1) {
    return 0;
  }

  n = Communication::SendMsg(secondClientSocket, SECOND_TURN);
  if (n == -1) {
    return 0;
  }

  return 1;
}

GameStatus Game::PlayOneTurn(int currentClient, int otherClient) {
  int n;
  string msg;
  GameStatus status;

  n = Communication::ReadMsg(currentClient, msg);
  if (n == -1) {
    return ERROR;
  }
  if (n == 0) {
    return CLIENT_DISCONNECTED;
  }

  if (msg == "NoMove") {
    status = NO_MOVE;
  } else if (msg == "End") {
    return GAME_ENDED;
  } else {
    status = PLAYING;
  }

  n = Communication::SendMsg(otherClient, msg);
  if (n == -1) {
    return ERROR;
  } else if (n == 0) {
    return CLIENT_DISCONNECTED;
  }

  return status;
}

Game::Game(int first_client) : first_client_socket_(first_client), second_client_socket_(0), is_closed_(0) {}

void Game::AddClient(int second_client) {
  if (second_client_socket_ != 0) {
    return;
  }

  second_client_socket_ = second_client;
}
void Game::CloseGame() {
  close(first_client_socket_);
  close(second_client_socket_);
}
