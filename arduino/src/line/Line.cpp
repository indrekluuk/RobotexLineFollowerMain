//
// Created by indrek on 12.11.2016.
//

#include "Line.h"





Line::Line() {

}



int8_t Line::getLineRange() {
  return lineRange;
}

int8_t Line::getLineNotFound() {
  return lineNotFound;
}



int8_t Line::getLine(uint8_t lineIndex, uint8_t bitmapHigh, uint8_t bitmapLow) {
  uint16_t lineBitMap = ((((uint16_t)bitmapHigh) << 8) | ((uint16_t)bitmapLow)) & (uint16_t)0x7FFE;

  int8_t line = lineNotFound;
  int8_t start = lineNotFound;


  uint16_t mask = 0x00002;
  for (int8_t index = -lineRange; index <= lineRange; index += 2) {
    if (lineBitMap & mask) {
      if (start == lineNotFound) start = index;
    } else {
      if (start != lineNotFound) {
        line = processLineSegment(line, start, index - 2);
      }
      start = lineNotFound;
    }
    mask <<= 1;
  }
  if (start != lineNotFound) {
    line = processLineSegment(line, start, lineRange);
  }

  return line;
}



int8_t Line::processLineSegment(int8_t previousLine, int8_t lineStart, int8_t lineEnd) {
  int8_t newLine = (int8_t)((lineEnd + lineStart) / 2);
  if (abs(newLine) < abs(previousLine)) {
    return newLine;
  } else {
    return previousLine;
  }
}



