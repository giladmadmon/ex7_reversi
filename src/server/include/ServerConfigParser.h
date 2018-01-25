/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#ifndef TASK_04_ALL_CONFIGPARSER_H
#define TASK_04_ALL_CONFIGPARSER_H

#ifndef CLION_RUN
#define CLION_RUN
#define SERVER_CONFIG_FILE_NAME "server_configuration.ini"
#else
#define SERVER_CONFIG_FILE_NAME "../exe/server_configuration.ini"
#endif

#include <iostream>

using namespace std;

class ServerConfigParser {
 public:
  /**
   * Constructor
   * @param file_name the name of the file..
   */
  ServerConfigParser(string file_name);

  /**
   * @return the Port as an int.
   */
  int GetPort();

 private:

  /**
   * Parse a file.
   */
  int ParseFile();

  /**
   * Parse 1 line in the file.
   * @param line the line.
   */
  void ParseLine(const string &line);

  /**
   * Parse definition.
   * @param def the given definition.
   * @param line the line.
   * @param variable the date written in the line as a string.
   */
  void ParseDefinition(string def, const string &line, string &variable);

  /**
   * Parse definition.
   * @param def the given definition.
   * @param line the line.
   * @param variable the date written in the line as an int.
   */
  void ParseDefinition(string def, const string &line, int &variable);

  int port_;
  string file_name_;
};

#endif //TASK_04_ALL_CONFIGPARSER_H
