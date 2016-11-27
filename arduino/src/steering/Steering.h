//
// Created by indrek on 27.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_STEERING_H
#define ROBOTEXLINEFOLLOWERMAIN_STEERING_H

#include "FrontWheels.h"
#include "../cameramessages/LineSegment.h"


class Steering {

    FrontWheels &frontWheels;


public:
    Steering(FrontWheels & frontWheels);

    void steer(const LineSegment & line);

};


#endif //ROBOTEXLINEFOLLOWERMAIN_STEERING_H
