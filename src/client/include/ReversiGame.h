/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#ifndef TASK_02_REVERSIGAME_H
#define TASK_02_REVERSIGAME_H

#include "Player.h"
#include "Logic.h"
#include "Printer.h"
#include "Client.h"
class ReversiGame {
 private:
  Player &white_player_;
  Player &black_player_;
  Logic &logic_;
  Board &board_;
  Printer &printer_;
  Client *client_;
  bool new_game_;
  bool game_closed_;
 public:
  /**
   * Constructor.
   *
   * @param black_player the player which plays the black color.
   * @param white_player the player which plays the white color.
   * @param logic the logic of the game.
   * @param board the board of the game.
   * @param printer the printer of the game.
   */
  ReversiGame(Player &black_player,
              Player &white_player,
              Logic &logic,
              Board &board,
              Printer &printer,
              Client *client);
/**
 * Resets the state of the game in order to start a new game.
 */
  void NewGame();
  /**
   * Play one turn of a player.
   */
  void PlayOneTurn();
  /**
   * Play the game till it ends.
   */
  void PlayGame();
  /**
   * Perform an action at the end of the game.
   */
  void EndTurn();
  /**
   * Get the player according to its color.
   *
   * @param color the color of the player.
   * @return the player whom color is the given color.
   */
  Player *GetPlayer(PlayerColor color);
};

#endif //TASK_02_REVERSIGAME_H
