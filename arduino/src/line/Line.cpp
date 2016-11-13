//
// Created by indrek on 12.11.2016.
//

#include "Line.h"





Line::Line() {

}




void Line::setRowBitmap(uint8_t rowIndex, uint8_t bitmapHigh, uint8_t bitmapLow) {
  if (rowIndex < rowCount) {
    lineBitmap[rowIndex] = ((((uint16_t)bitmapHigh) << 8) | ((uint16_t)bitmapLow)) & (uint16_t)0x7FFE;
  }

  lineFound = (rowIndex == 30);
}


bool Line::isLineFound() {
  return lineFound;
}


int8_t Line::getLinePosition() {
  RowLinePosition position(lineBitmap[30]);
  return position.getLinePosition(0);
}









