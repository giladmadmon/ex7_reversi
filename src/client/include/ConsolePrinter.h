/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#ifndef ASS2_CONSOLE_PRINTER_H
#define ASS2_CONSOLE_PRINTER_H

#include <vector>
using namespace std;

#include "Printer.h"


class ConsolePrinter : public Printer {
 public:

  /**
   * Constructor.
   */
  ConsolePrinter();

  /**
   * Prints a board.
   *
   * @param board the board to be printed.
   */
  virtual void PrintBoard(Board &board);

  /**
   * Print the possible moves.
   *
   * @param possible_moves the possible moves.
   */
  virtual void PrintPossibleMoves(vector<Position> &possible_moves);

  /**
   * Print that there are no moves.
   *
   * @param color the color of the player whom has bo moves.
   */
  virtual void PrintNoMoves(PlayerColor color);

  /**
   * Print the current turn.
   *
   * @param color the color of the player whom is his turn.
   */
  virtual void PrintCurrentTurn(PlayerColor color);

  /**
   * Ask from a player to enter a row.
   */
  virtual void PrintEnterRow();

  /**
   * Ask from a player to enter a column.
   */
  virtual void PrintEnterCol();

  /**
   * Tell the player he chose a wrong move.
   */
  virtual void PrintWrongMove();

  /**
   * Announce the winner.
   *
   * @param color the color of the winner.
   */
  virtual void PrintWinner(PlayerColor color);

  /**
   * Prints the scores of both players.
   *
   * @param black_score the black score.
   * @param white_score the white score.
   */
  virtual void PrintScore(int black_score, int white_score);

  /**
   * Tell the player he did not enter a number.
   */
  virtual void PrintNotANumber();

  /**
   * Prints the move the given player did.
   * @param position the move the was played
   * @param color the player who did the move.
   */
  virtual void PrintMove(Position &position, PlayerColor color);

  /**
    * Prints the move the AIPlayer did.
    * @param position the move the was played
    * @param color the player who did the move
    */
  virtual void PrintAINoMove(PlayerColor color);

  /**
    * Prints that we are waiting for other player's move
    */
  virtual void PrintWaiting();

  /**
    * Prints that we are connected
    */
  virtual void PrintConnected();

  /**
    * Prints that we are  waiting for other player's to connect
    */
  virtual void PrintWaitingOtherConnection();

  /**
    * Prints that the client disconnected to server
    */
  virtual void PrintMainMenu();

  /**
    * Prints that the client disconnected to server
    */
  virtual void PrintWrongMenuInput();
  /**
  * Prints the available games.
  * @param games the available games.
  */
  virtual void PrintAvailableGames(vector<string> games);

  /**
    * Prints no available games message.
    */
  virtual void PrintNoAvailableGames();

  /**
   * Prints online game options.
   */
  virtual void PrintOnlineMenu();

  /**
   * Prints the player to enter the name of the game he wants to open.
   */
  virtual void PrintChooseGameName();

  /**
   * Prints an error occurred during operation.
   */
  virtual void PrintOperationError();

  /**
   * Prints that the server was disconnected.
   */
  virtual void PrintServerDisconnected();

};
#endif //ASS2_CONSOLE_PRINTER_H