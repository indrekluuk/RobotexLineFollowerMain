//
// Created by indrek on 28.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_SCREENTOWORLD_H
#define ROBOTEXLINEFOLLOWERMAIN_SCREENTOWORLD_H


#include "../data/LineSegment.h"


class ScreenToWorld {

public:

    static const int16_t lineCount = 120;
    static const int16_t screenToWorldYTable[120];


    const LineSegment &lineOnScreen;
    LineSegment lineInWorld;


    ScreenToWorld(const LineSegment &lineOnScreen);


private:
    int16_t getWorldX(int16_t screenX, int16_t screenY);
    int16_t getRangeInWorldForScreenY(int16_t y);

};


#endif //ROBOTEXLINEFOLLOWERMAIN_SCREENTOWORLD_H
