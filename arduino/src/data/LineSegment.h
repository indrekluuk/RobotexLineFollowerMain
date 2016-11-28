//
// Created by indrek on 27.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_LINESEGMENT_H
#define ROBOTEXLINEFOLLOWERMAIN_LINESEGMENT_H


#include "Arduino.h"


struct LineSegment {

    int16_t range;
    int16_t x1;
    int16_t y1;
    int16_t x2;
    int16_t y2;

    LineSegment(int16_t range, int16_t x1, int16_t y1, int16_t x2, int16_t y2) :
        range(range),
        x1(x1),
        y1(y1),
        x2(x2),
        y2(y2)
    {}

};



#endif //ROBOTEXLINEFOLLOWERMAIN_LINESEGMENT_H
