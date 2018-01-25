/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#include "../include/ConsoleServerPrinter.h"

#include <iostream>
using namespace std;

ConsoleServerPrinter::ConsoleServerPrinter() {}

void ConsoleServerPrinter::PrintServer() {
  cout << "server" << endl;
}

void ConsoleServerPrinter::PrintWaitingServer() {
  cout << "Waiting for clients connections..." << endl;
}

void ConsoleServerPrinter::PrintErrorServerTurns() {
  cout << "Error writing to socket who's turn it is." << endl;
}

void ConsoleServerPrinter::PrintFirstConnection() {
  cout << "First client connected" << endl;
}

void ConsoleServerPrinter::PrintSecondConnection() {
  cout << "Second client connected" << endl;
}

void ConsoleServerPrinter::PrintErrorReadMsg() {
  cout << "Error reading message" << endl;
}

void ConsoleServerPrinter::PrintClientDisconnected() {
  cout << "Client disconnected" << endl;
}




