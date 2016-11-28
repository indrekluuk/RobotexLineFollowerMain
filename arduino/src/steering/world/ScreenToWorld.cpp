//
// Created by indrek on 28.11.2016.
//

#include "ScreenToWorld.h"




ScreenToWorld::ScreenToWorld(LineSegment & lineOnScreen) :
    lineOnScreen(lineOnScreen)
{
  lineInWorld.range = getRangeInWorldForScreenY(lineCount);
  lineInWorld.x1 = getWorldX(lineOnScreen.x1, lineOnScreen.y1);
  lineInWorld.y1 = getWorldY(lineOnScreen.y1);
  lineInWorld.x2 = getWorldX(lineOnScreen.x2, lineOnScreen.y2);
  lineInWorld.y2 = getWorldY(lineOnScreen.y2);
}

ScreenToWorld::ScreenToWorld() {
}


int16_t ScreenToWorld::getWorldX(int16_t screenX, int16_t screenY) const {
  return (screenX * getRangeInWorldForScreenY(screenY)) / lineOnScreen.range;
}

int16_t ScreenToWorld::getWorldY(int16_t screenY) const {
  return screenToWorldYTable[screenY];
}

int16_t ScreenToWorld::getRangeInWorldForScreenY(int16_t y) const {
  // Real world difference between bottom and top screen edge is roughly 5 times.
  // Line range on screen is -15..15
  // Screen has 120 lines
  // One point per line gets to x5 on last line
  // To keep it symmetrical add 2 points every other line
  return lineOnScreen.range + (y >> 1);
}


bool ScreenToWorld::isOffTheLine() {
  return lineOnScreen.y1 > 30;
}




