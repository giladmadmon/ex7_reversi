/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#ifndef TASK_02_LOGIC_H
#define TASK_02_LOGIC_H

#include <vector>
#include "Player.h"
#include "Board.h"
#include "Position.h"
class Logic {
 public:
  /**
   * Constructor.
   */
  Logic();

  /**
   * @return the color of the player whom is his current turn.
   */
  virtual PlayerColor CurrentTurn();

  /**
   * @return the color of the starting player.
   */
  virtual PlayerColor StartingPlayer() = 0;
  /**
   * @param board the board of the game.
   * @return the winner based on the board state.
   */
  virtual PlayerColor GetWinner(Board &board) = 0;
  /**
   * @param new_game true if it is the first turn in the game, false otherwise.
   * @param board the board of the game.
   * @return the color of the next player.
   */
  virtual PlayerColor NextTurn(bool new_game, Board &board) = 0;
  /**
   * Checks the possible moves of a player.
   *
   * @param player the color of the player whom we check his possible moves.
   * @param board the board of the game.
   * @return the possible moves of a player.
   */
  virtual vector<Position> PossibleMoves(PlayerColor player, Board &board) = 0;

  /**
   * Checks if the game ended.
   *
   * @param board the board of the game.
   * @return true if the game ended, false otherwise.
   */
  virtual bool GameOver(Board &board) = 0;
  /**
   * Place a token of a player and flips the rival tokens.
   *
   * @param color the color of the player.
   * @param row the row to place the token.
   * @param col the column to place the token.
   * @param board the board of the game.
   */
  virtual void PlaceAToken(PlayerColor color, int row, int col, Board &board) = 0;
 protected:
  PlayerColor current_turn_;
};

#endif //TASK_02_LOGIC_H
