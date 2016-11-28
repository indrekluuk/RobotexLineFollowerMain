//
// Created by indrek on 27.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_POSITIONTOSTEERING_H
#define ROBOTEXLINEFOLLOWERMAIN_POSITIONTOSTEERING_H


#include "Arduino.h"
#include "../data/LineSegment.h"
#include "ScreenToWorld.h"


class PositionToSteering {

    static const int16_t trackingScreenY = 90;
    static const int16_t fullSteeringRange = 100;



public:

    ScreenToWorld line;

    PositionToSteering(LineSegment & lineOnScreen);

    static int16_t getSteeringRange() {return fullSteeringRange;};


    int16_t getNewSteering(int16_t currentSteering);

private:
    int16_t getSteeringDelta(int16_t currentSteering);
    int16_t getSteeringRangeForY(int16_t screenY);
    int16_t getTrackingWorldX();


};


#endif //ROBOTEXLINEFOLLOWERMAIN_POSITIONTOSTEERING_H
