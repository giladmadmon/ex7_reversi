/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#include <sstream>
#include "../include/Convert.h"
int Convert::ConvertStringToInt(string str, int startIndex, int endIndex) {

  int number = 0;
  for (int i = startIndex; i < endIndex; i++) {
    number *= 10;
    number += str[i] - '0';
  }
  return number;
}

string Convert::ConvertIntToString(int num) {
  ostringstream convert;
  convert << num;
  return convert.str();
}

