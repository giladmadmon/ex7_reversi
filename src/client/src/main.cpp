/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#include  <iostream>

#include "../include/ClassicLogic.h"
#include "../include/ClientConfigParser.h"
#include "../include/LocalPlayer.h"
#include "../include/AIPlayer.h"
#include "../include/HumanPlayer.h"
#include "../include/ReversiGame.h"
#include "../include/ConsolePrinter.h"
#include "../include/RemotePlayer.h"

#include <limits>
#include <algorithm>
#include <signal.h>

#define MAIN_MAX_OPTION 3
#define MAIN_MIN_OPTION 1
#define ONLINE_MAX_OPTION 2
#define ONLINE_MIN_OPTION 1
#define GAMES_MIN_OPTION 0
#define BLACK_TURN "1"
#define WHITE_TURN "2"
#define JOIN_GAME_COMMAND "join "
#define START_GAME_COMMAND "start "
#define LIST_GAMES_COMMAND "list_games"
#define ONLINE_OPERATION_ERROR "-1"

void StartGame(Player &black, Player &white, Logic &logic, Board &board, Printer &printer, Client *client = NULL);
void OnlineChoice(Player &this_player, Printer &printer, Logic &logic, Board &board);
void OnlineGameRequest(Client &client, Printer &printer);
int HandleMenu(Printer &printer, int min_opt, int max_opt);

void BrokenPipeHandle(int sig_num) {
  signal(SIGPIPE, BrokenPipeHandle);
}

int main() {
  // handle SIG_PIPE error
  signal(SIGPIPE, BrokenPipeHandle);

  Board board;
  ClassicLogic logic;
  ConsolePrinter printer;
  //HumanPlayer this_player;
  AIPlayer this_player(board,logic);
  int option;

  printer.PrintMainMenu();
  option = HandleMenu(printer, MAIN_MIN_OPTION, MAIN_MAX_OPTION);

  switch (option) {
    case 1: {
      HumanPlayer other_human_player = HumanPlayer();
      StartGame(this_player, other_human_player, logic, board, printer);
      break;
    }
    case 2: {
      AIPlayer other_AI_player = AIPlayer(board, logic);
      StartGame(this_player, other_AI_player, logic, board, printer);
      break;
    }
    case 3: {
      try {
        OnlineChoice(this_player, printer, logic, board);
      }
      catch (const char *msg){
        cout << msg << endl;
      }

      break;
    }
  }
}

int HandleMenu(Printer &printer, int min_opt, int max_opt) {
  int option;
  bool valid;

  do {
    cin >> option;

    if (option < min_opt || option > max_opt) {
      printer.PrintWrongMenuInput();
    }

    if (cin.good()) {
      valid = true;
    } else {
      cin.clear();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  } while (!valid || (option < min_opt || option > max_opt));

  return option;
}

void StartGame(Player &black, Player &white, Logic &logic, Board &board, Printer &printer, Client *client) {
  ReversiGame game(black, white, logic, board, printer, client);

  game.PlayGame();
}

void OnlineChoice(Player &this_player, Printer &printer, Logic &logic, Board &board) {
  string turn;
  int n;

  ClientConfigParser config_parser(CLIENT_CONFIG_FILE_NAME);
  Client client(config_parser.GetIP().c_str(), config_parser.GetPort());
  LocalPlayer local_player(client, this_player);
  RemotePlayer remote_player(client);

  OnlineGameRequest(client, printer);

  n = client.ReadMsg(turn);
  if (n < 0 || (turn != BLACK_TURN && turn != WHITE_TURN)) {
    printer.PrintServerDisconnected();
    return;
  }

  if (turn == BLACK_TURN) {
    StartGame(local_player, remote_player, logic, board, printer, &client);
  } else {
    StartGame(remote_player, local_player, logic, board, printer, &client);
  }
}

void OnlineGameRequest(Client &client, Printer &printer) {
  int choice;
  string msg = ONLINE_OPERATION_ERROR;

  while (msg == ONLINE_OPERATION_ERROR) {
    printer.PrintOnlineMenu();
    choice = HandleMenu(printer, ONLINE_MIN_OPTION, ONLINE_MAX_OPTION);

    switch (choice) {
      case 1:
        printer.PrintChooseGameName();
        cin >> msg;
        client.connectToServer();
        client.SendMsg(START_GAME_COMMAND + msg);
        client.ReadMsg(msg);
        if (msg != ONLINE_OPERATION_ERROR)
          printer.PrintWaitingOtherConnection();
        break;

      case 2:
        client.connectToServer();
        client.SendMsg(LIST_GAMES_COMMAND);
        client.ReadMsg(msg);
        if (msg == "") {
          printer.PrintNoAvailableGames();
          msg = ONLINE_OPERATION_ERROR;
          continue;
        } else {
          vector<string> games;
          int prv_delimiter_pos = 0, counter = 1;
          int delimiter_pos = msg.find(GAMES_DELIMITER);

          while (delimiter_pos != string::npos) {
            games.push_back(msg.substr(prv_delimiter_pos, delimiter_pos - prv_delimiter_pos));
            prv_delimiter_pos = delimiter_pos + 1;
            delimiter_pos = msg.find(GAMES_DELIMITER, delimiter_pos + 1);
          }
          games.push_back(msg.substr(prv_delimiter_pos));

          printer.PrintAvailableGames(games);
          choice = HandleMenu(printer, GAMES_MIN_OPTION, games.size());
          if (choice == 0) {
            msg = ONLINE_OPERATION_ERROR;
            continue;
          }
          client.connectToServer();
          client.SendMsg(JOIN_GAME_COMMAND + games[choice - 1]);
          client.ReadMsg(msg);
        }
        break;
    }

    if (msg == ONLINE_OPERATION_ERROR)
      printer.PrintOperationError();
  }
}