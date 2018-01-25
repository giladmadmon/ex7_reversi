/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/
#include  <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include "../include/ServerConfigParser.h"

using namespace std;

#define PORT_DEF "port:"

ServerConfigParser::ServerConfigParser(string file_name) {
  file_name_ = file_name;
  port_ = -1;

  ParseFile();
}

int ServerConfigParser::ParseFile() {
  string line;

  ifstream config_file((file_name_).c_str());
  if (config_file == NULL) {
    throw "Configuration file does not exist.";
  }

  while (getline(config_file, line)) {
    ParseLine(line);
  }
}

void ServerConfigParser::ParseLine(const string &line) {
  ParseDefinition(PORT_DEF, line, port_);
}

void ServerConfigParser::ParseDefinition(const string def, const string &line, string &variable) {
  if (line.find(def) != -1) {
    variable = line.substr(strlen(def.c_str()));
  }
}

void ServerConfigParser::ParseDefinition(const string def, const string &line, int &variable) {
  if (line.find(def) != -1) {
    variable = atoi(line.substr(def.size()).c_str());
  }
}
int ServerConfigParser::GetPort() {
  return port_;
}
