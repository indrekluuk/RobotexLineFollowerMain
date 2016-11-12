//
// Created by indrek on 12.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_LINE_H
#define ROBOTEXLINEFOLLOWERMAIN_LINE_H


#include <Arduino.h>



class Line {

    const int8_t lineRange = 13;
    const int8_t lineNotFound = lineRange + 1;


public:
    Line();


    int8_t getLineRange();
    int8_t getLineNotFound();

    int8_t getLine(uint8_t lineIndex, uint8_t bitmapHigh, uint8_t bitmapLow);
    int8_t processLineSegment(int8_t currentLine, int8_t lineStart, int8_t lineEnd);


};


#endif //ROBOTEXLINEFOLLOWERMAIN_LINE_H
