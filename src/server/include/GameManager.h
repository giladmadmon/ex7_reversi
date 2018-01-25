/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#ifndef TASK_05_GAMEMANGER_H
#define TASK_05_GAMEMANGER_H

#include "Game.h"

#include <map>
#include <vector>
#include <thread_db.h>

using namespace std;

class GameManager {

 public:
  /**
   *
   * @return the instance of the GameManager
   */
  static GameManager *Instance();

  /**
   * start a new game
   *
   * @param client_socket the black player in the game
   * @param name the name of the game
   * @return the status of the opening
   */
  int Start(int client_socket, string name);
  /**
   * @return the list of pending games
   */
  vector<string> GameList();
  /**
   * join client as the white player of a pending game
   *
   * @param client the white player of the game
   * @param name the name of the game
   * @return the status of joining
   */
  int Join(int client, string name);
  /**
   * removes a game from the games list
   * @param game the game to remove
   */
  void GameEnded(Game *game);
  /**
    * cancel all the games and delete their allocated data
    */
  void FinishAllGames();
  /**
   * delete pending game game.
   */
  void CloseWaitingGames();

 private:
  static GameManager *instance;

  map<Game *, thread_t> games_list_;
  map<string, Game *> available_game_list_;
  pthread_mutex_t available_games_mutex_;
  bool games_closing_;

  /**
   * constructor
   */
  GameManager() : games_closing_(false) {
    pthread_mutex_init(&available_games_mutex_, NULL);
  }
  /**
   * (empty) copy constructor
   */
  GameManager(GameManager &) {};
  /**
   * (empty) = operator
   * @return nothing
   */
  GameManager &operator=(GameManager &) {};
};

#endif //TASK_05_GAMEMANGER_H
