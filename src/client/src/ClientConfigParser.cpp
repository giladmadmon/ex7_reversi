/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/
#include  <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include "../include/ClientConfigParser.h"

using namespace std;

#define IP_DEF "ip:"
#define PORT_DEF "port:"

ClientConfigParser::ClientConfigParser(string file_name) {
  file_name_ = file_name;
  ip_address_ = "";
  port_ = -1;

  ParseFile();
}

int ClientConfigParser::ParseFile() {
  string line;

  ifstream config_file((file_name_).c_str());
  if (config_file == NULL) {
    throw "Configuration file does not exist.";
  }

  while (getline(config_file, line)) {
    ParseLine(line);
  }
}

void ClientConfigParser::ParseLine(const string &line) {
  ParseDefinition(IP_DEF, line, ip_address_);
  ParseDefinition(PORT_DEF, line, port_);
}

void ClientConfigParser::ParseDefinition(const string def, const string &line, string &variable) {
  if (line.find(def) != -1) {
    variable = line.substr(strlen(def.c_str()));
  }
}

void ClientConfigParser::ParseDefinition(const string def, const string &line, int &variable) {
  if (line.find(def) != -1) {
    variable = atoi(line.substr(def.size()).c_str());
  }
}
string ClientConfigParser::GetIP() {
  return ip_address_;
}
int ClientConfigParser::GetPort() {
  return port_;
}
