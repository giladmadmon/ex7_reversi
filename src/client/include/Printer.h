/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/
#ifndef ASS2_PRINTER_H
#define ASS2_PRINTER_H

#define GAMES_DELIMITER ' '

#include <vector>
#include "Board.h"
#include "Position.h"
using namespace std;

//interface

class Printer {
 public:

  /**
   * Prints a board.
   *
   * @param board the board to be printed.
   */
  virtual void PrintBoard(Board &board) = 0;

  /**
   * Print the possible moves.
   *
   * @param possible_moves the possible moves.
   */
  virtual void PrintPossibleMoves(vector<Position> &possible_moves) = 0;

  /**
   * Print that there are no moves.
   *
   * @param color the color of the player whom has bo moves.
   */
  virtual void PrintNoMoves(PlayerColor color) = 0;

  /**
   * Print the current turn.
   *
   * @param color the color of the player whom is his turn.
   */
  virtual void PrintCurrentTurn(PlayerColor color) = 0;

  /**
   * Ask from a player to enter a row.
   */
  virtual void PrintEnterRow() = 0;

  /**
   * Ask from a player to enter a column.
   */
  virtual void PrintEnterCol() = 0;

  /**
   * Tell the player he chose a wrong move.
   */
  virtual void PrintWrongMove() = 0;

  /**
   * Announce the winner.
   *
   * @param color the color of the winner.
   */
  virtual void PrintWinner(PlayerColor color) = 0;

  /**
   * Prints the scores of both players.
   *
   * @param black_score the black score.
   * @param white_score the white score.
   */
  virtual void PrintScore(int black_score, int white_score) = 0;

  /**
   * Tell the player he did not enter a number.
   */
  virtual void PrintNotANumber() = 0;

  /**
   * Prints the move the Player did.
   */
  virtual void PrintMove(Position &position, PlayerColor color) = 0;

  /**
   * Prints the move the AIPlayer did.
   * @param position the move the was played
   * @param color the player who did the move
   */
  virtual void PrintAINoMove(PlayerColor color) = 0;
  /**
    * Prints that we are waiting for other player's move
    */
  virtual void PrintWaiting() = 0;

  /**
    * Prints that we are connected
    */
  virtual void PrintConnected() = 0;

  /**
    * Prints that we are  waiting for other player's to connect
    */
  virtual void PrintWaitingOtherConnection() = 0;

  /**
    * Prints that the client disconnected to server
    */
  virtual void PrintMainMenu() = 0;

  /**
    * Prints that the client disconnected to server
    */
  virtual void PrintWrongMenuInput() = 0;

  /**
    * Prints the available games.
    * @param games the available games.
    */
  virtual void PrintAvailableGames(vector<string> games) = 0;

  /**
    * Prints no available games message.
    */
  virtual void PrintNoAvailableGames() = 0;

  /**
   * Prints online game options.
   */
  virtual void PrintOnlineMenu() = 0;

  /**
   * Prints the player to enter the name of the game he wants to open.
   */
  virtual void PrintChooseGameName() = 0;

  /**
   * Prints an error occurred during operation.
   */
  virtual void PrintOperationError() = 0;

  /**
   * Prints that the server was disconnected.
   */
  virtual void PrintServerDisconnected() = 0;
};

#endif //ASS2_PRINTER_H