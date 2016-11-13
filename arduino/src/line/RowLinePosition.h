//
// Created by indrek on 13.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_ROWLINEPOSITION_H
#define ROBOTEXLINEFOLLOWERMAIN_ROWLINEPOSITION_H


#include "Arduino.h"



class RowLinePosition {

    static const int8_t rowRange = 13;
    static const int8_t lineNotFound = rowRange + 2;


    uint16_t rowBitMap;

public:
    RowLinePosition(uint16_t rowBitMap);

    static int8_t getRowRange();
    static bool isInRange(int8_t linePos);
    static bool isLineNotFound(int8_t linePos);

    int8_t getLinePosition(int8_t seekPos);
    int8_t processLineSegment(int8_t seekPos, int8_t preLinePos, int8_t lineStart, int8_t lineEnd);


};


#endif //ROBOTEXLINEFOLLOWERMAIN_ROWLINEPOSITION_H
