/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/
#ifndef TASK_04_SERVER_H
#define TASK_04_SERVER_H

#define NO_MOVE_MSG "NoMove"
#define END_GAME_MSG "End"

#include <memory.h>

enum GameStatus { NO_MOVE, GAME_ENDED, PLAYING, ERROR, CLIENT_DISCONNECTED };

class Game {
 public:
  /**
   * Constructor
   * @param first_client the first client of the game (the black player)
   */
  Game(int first_client);
  /**
   * add the second client to the game (white player)
   * @param second_client the second client
   */
  void AddClient(int second_client);
  /**
   * transfering messages between the clients till the end of the game
   */
  void Play();
  /**
   * close the game
   */
  void CloseGame();

 private:
  /**
   * tell the client who is black and who is white
   *
   * @param firstClientSocket the black player
   * @param secondClientSocket the white player
   * @return the status of the sending
   */
  int TellTurn(int firstClientSocket, int secondClientSocket);
  /**
   * plays one turn of the game
   *
   * @param currentClient the player whom his turn
   * @param otherClient the other player
   * @return the game status according to the transfered message
   */
  GameStatus PlayOneTurn(int currentClient, int otherClient);
  /**
   * get two client and swap their values (change turn)
   *
   * @param currentClient the player whom his turn now
   * @param otherClient the other player
   */
  void SwapClients(int &currentClient, int &otherClient);

  int first_client_socket_;
  int second_client_socket_;
  int is_closed_;
};

#endif //TASK_04_SERVER_H
