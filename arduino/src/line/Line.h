//
// Created by indrek on 12.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_LINE_H
#define ROBOTEXLINEFOLLOWERMAIN_LINE_H


#include "RowLinePosition.h"
#include <Arduino.h>




class Line {

    static const int8_t rowCount = 120;
    static const int16_t turnCoefficient = 1001;

    uint16_t rowBitmaps[rowCount];
    int8_t rowLinePositions[rowCount];
    int16_t rowLineSlantCoefficient[rowCount];

    int8_t lineStartRow;
    int8_t lineEndRow;
    bool lineFound;



public:
    Line();

    static int8_t getRowCount();

    void setRowBitmap(uint8_t rowIndex, uint8_t bitmapHigh, uint8_t bitmapLow);

    bool isLineFound();
    int8_t getLinePosition();


private:
    void resetLine();
    int8_t getPreviousLineLinePosition(uint8_t rowIndex);
    void setLinePosition(uint8_t rowIndex, int8_t linePos);
    void setLineLastRow(uint8_t rowIndex);
    bool isTurnOnRow(uint8_t rowIndex);


};


#endif //ROBOTEXLINEFOLLOWERMAIN_LINE_H
