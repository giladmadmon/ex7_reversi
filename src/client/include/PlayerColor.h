/**************
* Student name: Gilad Madmon
* Student name: Dafna Magid
* Exercise name: Exercise 7
**************/

#ifndef TASK_02_PLAYERCOLOR_H
#define TASK_02_PLAYERCOLOR_H

enum PlayerColor { Black = 'X', White = 'O', NoColor = ' ' };
/**
 * switches colors between black and white.
 * @param color the given color
 * @return the other color.
 */
static PlayerColor OtherColor(PlayerColor color) {
  if (color == NoColor) {
    return NoColor;
  }
  return color == Black ? White : Black;
}

#endif //TASK_02_PLAYERCOLOR_H
