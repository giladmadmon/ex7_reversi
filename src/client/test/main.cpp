/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 5
**************/

#include <gtest/gtest.h>

using namespace testing;
using namespace std;

int main(int argc, char *argv[]) {
  cout.rdbuf(NULL);
  InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  return 0;
}