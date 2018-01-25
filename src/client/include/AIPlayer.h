/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#ifndef TASK_03_ALPLAYER_H
#define TASK_03_ALPLAYER_H
#include <limits.h>
#include <math.h>
#include "Player.h"
#include "Logic.h"

class AIPlayer : public Player {
 public:
  /**
   * Constructor.
   *
   * @param name the name of the player.
   */
  AIPlayer(Board &board, Logic &logic);
  /**
     * The AIPlayer make's the best move according to minimax method.
     *
     * @param possible_moves the player possible moves.
     * @param printer print the chosen move.
     * @return the chosen position of the AIPlayer.
     */
  virtual Position MakeAMove(vector<Position> &possible_moves, Printer &printer, PlayerColor color);

 private:
/**
 * calculates the board grade after placing a token in the given position.
 * @param board the board we need to place the token at.
 * @param position the position we want to place the token at.
 *@return the board grade after doing the placing.
 * */
  int GetGrade(Position &position, Board board, PlayerColor color);
  /**
 * calculates the score difference after placing a token of a 'color' in the given position.
 * @param color this player color.
 * @param board the board we need to calculate the difference at.
 * @param position the position we want to place the token at.
 *@return the difference between this given player to the other.
 * */
  int GetTokensDifference(Position &position, PlayerColor color, Board board);
  Logic &logic_;
  Board &board_;
};

#endif //TASK_03_ALPLAYER_H
