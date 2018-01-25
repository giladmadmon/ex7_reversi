/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#ifndef TASK_02_CLASSICLOGIC_H
#define TASK_02_CLASSICLOGIC_H

#include "Logic.h"
class ClassicLogic : public Logic {
 public:
  /**
   * Constructor.
   *
   * @param board
   */
  ClassicLogic() {}
  /**
   * @return the color of the starting player.
   */
  virtual PlayerColor StartingPlayer();
  /**
   * @param board the board of the game.
   * @return the winner based on the board state.
   */
  virtual PlayerColor GetWinner(Board &board);
  /**
   * @param new_game true if it is the first turn in the game, false otherwise.
   * @param board the board of the game.
   * @return the color of the next player.
   */
  virtual PlayerColor NextTurn(bool new_game, Board &board);
  /**
   * Checks the possible moves of a player.
   *
   * @param player the color of the player whom we check his possible moves.
   * @param board the board of the game.
   * @return the possible moves of a player.
   */
  virtual vector<Position> PossibleMoves(PlayerColor player, Board &board);

  /**
   * Checks if the game ended.
   *
   * @param board the board of the game.
   * @return true if the game ended, false otherwise.
   */
  bool GameOver(Board &board);
  /**
   * Place a token of a player and flips the rival tokens.
   *
   * @param color the color of the player.
   * @param row the row to place the token.
   * @param col the column to place the token.
   * @param board the board of the game.
   */
  virtual void PlaceAToken(PlayerColor color, int row, int col, Board &board);
 private:

  /**
   * Checks if there will be a flip in all the directions of a position.
   *
   * @param rival_color the rival color.
   * @param row the row of the position.
   * @param col the column of the position,
   * @param board the board of the game.
   * @return the direction which should be flipped in case a token is placed at the given position.
   */
  vector<vector<int> > CheckAllDirections(PlayerColor rival_color, int row, int col, Board &board);
  /**
   * Checks if there will be a flip in one direction of a position.
   *
   * @param rival_color the rival color.
   * @param row the row of the position.
   * @param col the column of the position,
   * @param row_change the row change of every step in order to know the direction.
   * @param col_change the column change of every step in order to know the direction.
   * @param board the board of the game.
   * @return true if there will be a flip, false otherwise.
   */
  bool CheckOneDirection(PlayerColor rival_color,
                         int row,
                         int col,
                         int row_change,
                         int col_change,
                         Board &board);
};

#endif //TASK_02_CLASSICLOGIC_H
