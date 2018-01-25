/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#include <limits>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termio.h>
#include <sstream>
#include "../include/HumanPlayer.h"

using namespace std;

int HumanPlayer::KeyboardHit() {
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if (ch != EOF) {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}

int GetIntFromUser(Printer &printer) {
  int input = -1;
  bool valid = false;
  do {
    cin >> input;
    if (cin.good()) {
      valid = true;
    } else {
      // reset the buffer's state
      cin.clear();
      // empty the buffer
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      // print a message to the player
      printer.PrintNotANumber();
    }
  } while (!valid);

  return input;
}

Position HumanPlayer::MakeAMove(vector<Position> &possible_moves, Printer &printer, PlayerColor color) {
  int chosen_row, chosen_column;
  bool valid = false;

  if (possible_moves.size() > 0) {
    printer.PrintCurrentTurn(color);

    do {
      Position position(0, 0);

      printer.PrintPossibleMoves(possible_moves);

      printer.PrintEnterRow();
      chosen_row = GetIntFromUser(printer);

      printer.PrintEnterCol();
      chosen_column = GetIntFromUser(printer);

      position = Position(chosen_row, chosen_column);
      if (std::find(possible_moves.begin(), possible_moves.end(), position) != possible_moves.end()) {
        valid = true;
      } else {
        printer.PrintWrongMove();
      }
    } while (!valid);

    cin.ignore(1);
    return Position(chosen_row, chosen_column);
  }

    printer.PrintNoMoves(color);

    while (!KeyboardHit());
    cin.ignore(1);

  return Position(-1, -1);
}

