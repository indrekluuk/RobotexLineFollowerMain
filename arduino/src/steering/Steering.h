//
// Created by indrek on 27.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_STEERING_H
#define ROBOTEXLINEFOLLOWERMAIN_STEERING_H

#include "FrontWheels.h"
#include "../cameramessages/LineSegment.h"


class Steering {


    static const int16_t minX = 0;
    static const int16_t maxX = 30;
    static const int16_t centerX = minX + (maxX - minX) / 2;
    FrontWheels &frontWheels;


public:
    Steering(FrontWheels & frontWheels);

    void steer(const LineSegment & line);

};


#endif //ROBOTEXLINEFOLLOWERMAIN_STEERING_H
