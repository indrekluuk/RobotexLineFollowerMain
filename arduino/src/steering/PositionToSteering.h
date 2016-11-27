//
// Created by indrek on 27.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_POSITIONTOSTEERING_H
#define ROBOTEXLINEFOLLOWERMAIN_POSITIONTOSTEERING_H


#include "Arduino.h"
#include "../cameramessages/LineSegment.h"


class PositionToSteering {

    static const int16_t minX = 0;
    static const int16_t maxX = 30;
    static const int16_t centerX = minX + (maxX - minX) / 2;
    static const int16_t rangeX = maxX - centerX;

    static const int16_t fullSteeringRange = 100;

    const LineSegment & line;


public:
    PositionToSteering(const LineSegment & line);

    static int16_t getSteeringRange() {return fullSteeringRange;};


    int16_t getNewSteering(int16_t currentSteering);

private:
    int16_t getSteeringDelta(int16_t currentSteering);
    int16_t getSteeringRangeForY(int16_t y);


};


#endif //ROBOTEXLINEFOLLOWERMAIN_POSITIONTOSTEERING_H
