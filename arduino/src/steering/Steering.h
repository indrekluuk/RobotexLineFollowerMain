//
// Created by indrek on 27.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_STEERING_H
#define ROBOTEXLINEFOLLOWERMAIN_STEERING_H

#include "FrontWheels.h"
#include "../data/LineSegment.h"


class Steering {
    FrontWheels & frontWheels;

    int16_t currentSteering;

public:
    Steering(FrontWheels & frontWheels);

    void center();
    void steer(LineSegment & line);

};


#endif //ROBOTEXLINEFOLLOWERMAIN_STEERING_H
