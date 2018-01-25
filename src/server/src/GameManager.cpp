/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#include <sstream>
#include "../include/GameManager.h"
#include "../include/Communication.h"

GameManager *GameManager::instance = NULL;

void *JoinGame(void *args) {
  Game *game = (Game *) args;

  game->Play();
}

int GameManager::Start(int client_socket, string name) {
  pthread_mutex_lock(&available_games_mutex_);
  if (available_game_list_.count(name)) {
    pthread_mutex_unlock(&available_games_mutex_);
    return FAILURE;
  }

  pair<string, Game *> new_game(name, new Game(client_socket));
  available_game_list_.insert(new_game);
  pthread_mutex_unlock(&available_games_mutex_);

  return SUCCESS;
}

vector<string> GameManager::GameList() {
  vector<string> games_name;

  pthread_mutex_lock(&available_games_mutex_);
  for (map<string, Game *>::iterator it = available_game_list_.begin(); it != available_game_list_.end(); ++it) {
    games_name.push_back(it->first);
  }
  pthread_mutex_unlock(&available_games_mutex_);

  return games_name;
}

int GameManager::Join(int client_socket, string name) {
  pthread_mutex_lock(&available_games_mutex_);
  if (available_game_list_.count(name)) {
    pthread_t thread;

    map<string, Game *>::iterator game = available_game_list_.find(name);

    game->second->AddClient(client_socket);

    pthread_create(&thread, NULL, JoinGame, game->second);
    pair<Game *, pthread_t> wanted_game(game->second, thread);
    games_list_.insert(wanted_game);

    available_game_list_.erase(name);
    pthread_mutex_unlock(&available_games_mutex_);

    return SUCCESS;
  }
  pthread_mutex_unlock(&available_games_mutex_);
  return FAILURE;
}

GameManager *GameManager::Instance() {
  if (!instance)
    instance = new GameManager();
  return instance;
}

void GameManager::FinishAllGames() {
  pthread_mutex_lock(&available_games_mutex_);
  games_closing_ = true;
  pthread_mutex_unlock(&available_games_mutex_);

  for (map<Game *, thread_t>::iterator it = games_list_.begin(); it != games_list_.end(); it++) {
    it->first->CloseGame();
    pthread_cancel(it->second);
  }

  for (map<Game *, thread_t>::iterator it = games_list_.begin(); it != games_list_.end(); it++) {
    delete it->first;
  }

  games_list_.clear();
}
void GameManager::GameEnded(Game *game) {
  pthread_mutex_lock(&available_games_mutex_);
  if (!games_closing_) {
    games_list_.erase(game);
    delete game;
  }
  pthread_mutex_unlock(&available_games_mutex_);
}
void GameManager::CloseWaitingGames() {
  pthread_mutex_lock(&available_games_mutex_);
  for (map<string, Game *>::iterator it = available_game_list_.begin(); it != available_game_list_.end(); it++) {
    delete it->second;
  }
  available_game_list_.clear();
  pthread_mutex_unlock(&available_games_mutex_);
}
