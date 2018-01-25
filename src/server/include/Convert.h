/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#ifndef TASK_05_COMMONFUNCTIONS_H
#define TASK_05_COMMONFUNCTIONS_H

#include <iostream>
using namespace std;

class Convert {
 public:
  /**
   * convert string to int
   * @param str to str to be converted
   * @param startIndex the start index of the conversion
   * @param endIndex the last index of the conversion
   * @return the int after conversion
   */
  static int ConvertStringToInt(string str, int startIndex, int endIndex);
  /**
   * convert string to int
   * @return the int after conversion
   */
  static int ConvertStringToInt(string str);
  /**
   * convert int to string
   * @return the number as string
   */
  static string ConvertIntToString(int num);
};

#endif //TASK_05_COMMONFUNCTIONS_H
