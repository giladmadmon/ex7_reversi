/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#include "../include/ConsoleServerPrinter.h"
#include "../include/ServerConfigParser.h"
#include "../include/Server.h"
#include <stdlib.h>
#include <signal.h>

using namespace std;

void *StartServer(void *server_pointer) {
  try {
    Server *server = (Server *) server_pointer;
    server->Start();
    cout << "Enter 'exit' to exit." << endl;
    server->AcceptConnections();
  } catch (const char *msg) {
    cout << msg << endl;
    exit(1);
  }
}

void BrokenPipeHandle(int sig_num) {
  signal(SIGPIPE, BrokenPipeHandle);
}

int main() {
  // handle SIG_PIPE error
  signal(SIGPIPE, BrokenPipeHandle);

  ServerConfigParser config_parser(SERVER_CONFIG_FILE_NAME);
  ConsoleServerPrinter printer;
  pthread_t pthread;
  string input;

  try {
    Server server(config_parser.GetPort());
    pthread_create(&pthread, NULL, StartServer, &server);

    do {
      cin >> input;
    } while (input != "exit");
    pthread_cancel(pthread);
    pthread_join(pthread, NULL);
    server.Stop();
  } catch (...) {}
}
