//
// Created by indrek on 12.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_LINE_H
#define ROBOTEXLINEFOLLOWERMAIN_LINE_H


#include "RowLinePosition.h"
#include <Arduino.h>




class Line {

    static const int16_t rowCount = 120;

    uint16_t lineBitmap[rowCount];
    int16_t firstLine = -1;

    bool lineFound = false;



public:
    Line();

    void setRowBitmap(uint8_t rowIndex, uint8_t bitmapHigh, uint8_t bitmapLow);

    bool isLineFound();
    int8_t getLinePosition();



};


#endif //ROBOTEXLINEFOLLOWERMAIN_LINE_H
