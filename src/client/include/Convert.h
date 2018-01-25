/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#ifndef TASK_05_COMMONFUNCTIONS_H
#define TASK_05_COMMONFUNCTIONS_H

#define STRING_END -1

#include <iostream>
using namespace std;

class Convert {
 public:
  static int ConvertStringToInt(string str, int startIndex = 0, int endIndex = STRING_END);
  string ConvertIntToString(int num);
};

#endif //TASK_05_COMMONFUNCTIONS_H
