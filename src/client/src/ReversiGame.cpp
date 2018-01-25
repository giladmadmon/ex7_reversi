/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#include <cstdio>
#include "../include/ReversiGame.h"

using namespace std;
void ReversiGame::PlayGame() {
  while (!logic_.GameOver(board_) && !game_closed_) {
    PlayOneTurn();
  }

  if (!game_closed_) {
    printer_.PrintBoard(board_);

    printer_.PrintScore(board_.CountColor(Black), board_.CountColor(White));
    printer_.PrintWinner(logic_.GetWinner(board_));

    EndTurn();
  } else {
    printer_.PrintServerDisconnected();
  }
}

void ReversiGame::PlayOneTurn() {
  PlayerColor current_turn = logic_.NextTurn(new_game_, board_);
  vector<Position> possible_moves = logic_.PossibleMoves(current_turn, board_);
  Player *current_player = GetPlayer(current_turn);

  printer_.PrintBoard(board_);

  if (possible_moves.empty()) {
    current_player->MakeAMove(possible_moves, printer_, current_turn);
  } else {
    Position chosen_position = current_player->MakeAMove(possible_moves, printer_, current_turn);

    if (chosen_position.GetColumn() <= 0 || chosen_position.GetRow() <= 0) {
      game_closed_ = true;
      return;
    }

    printer_.PrintMove(chosen_position, current_turn);

    logic_.PlaceAToken(current_turn, chosen_position.GetRow(), chosen_position.GetColumn(), board_);
  }

  new_game_ = false;
}

void ReversiGame::EndTurn() {
  if (client_ != NULL && !game_closed_) {
    client_->SendMsg(END_GAME_MSG);
  }
}

Player *ReversiGame::GetPlayer(PlayerColor color) {
  if (color == Black) {
    return &black_player_;
  } else {
    return &white_player_;
  }
}

ReversiGame::ReversiGame(Player &black_player,
                         Player &white_player,
                         Logic &logic,
                         Board &board,
                         Printer &printer,
                         Client *client)
    : black_player_(black_player),
      white_player_(white_player),
      logic_(logic),
      board_(board),
      printer_(printer),
      client_(client),
      game_closed_(false) {
  this->NewGame();
}

void ReversiGame::NewGame() {
  this->board_.Reset();
  new_game_ = true;
}
