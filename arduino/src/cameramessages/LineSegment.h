//
// Created by indrek on 27.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_LINESEGMENT_H
#define ROBOTEXLINEFOLLOWERMAIN_LINESEGMENT_H




struct LineSegment {
    uint8_t x1;
    uint8_t y1;
    uint8_t x2;
    uint8_t y2;
    LineSegment(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
        : x1(x1), y1(y1), x2(x2), y2(y2) {}
};



#endif //ROBOTEXLINEFOLLOWERMAIN_LINESEGMENT_H
