//
// Created by indrek on 13.11.2016.
//

#include "RowLinePosition.h"




RowLinePosition::RowLinePosition(uint16_t rowBitMap) : rowBitMap(rowBitMap) {
}



int8_t RowLinePosition::getRowRange() {
  return rowRange;
}


bool RowLinePosition::isInRange(int8_t linePos) {
  return abs(linePos) <= rowRange;
}


bool RowLinePosition::isLineNotFound(int8_t linePos) {
  return linePos == lineNotFound;
}


int8_t RowLinePosition::getLinePosition(int8_t seekPos) {
  int8_t line = lineNotFound;
  int8_t start = lineNotFound;

  uint16_t mask = 0x00002;
  for (int8_t index = -rowRange; index <= rowRange; index += 2) {
    if (rowBitMap & mask) {
      if (start == lineNotFound) start = index;
    } else {
      if (start != lineNotFound) {
        line = processLineSegment(seekPos, line, start, index - 2);
      }
      start = lineNotFound;
    }
    mask <<= 1;
  }
  if (start != lineNotFound) {
    line = processLineSegment(seekPos, line, start, rowRange);
  }

  return line;
}




int8_t RowLinePosition::processLineSegment(int8_t seekPos, int8_t preLinePos, int8_t lineStart, int8_t lineEnd) {
  int8_t newLinePos = (int8_t)((lineEnd + lineStart) / 2);
  if (abs(seekPos-newLinePos) < abs(seekPos-preLinePos)) {
    return newLinePos;
  } else {
    return preLinePos;
  }
}





