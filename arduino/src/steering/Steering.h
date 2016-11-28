//
// Created by indrek on 27.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_STEERING_H
#define ROBOTEXLINEFOLLOWERMAIN_STEERING_H

#include "FrontWheels.h"
#include "../data/LineSegment.h"




class Steering {

    static const int16_t fullSteeringRange = 100;

    FrontWheels & frontWheels;
    int16_t currentSteering;
    LineSegment previouslyProcessedLine;

public:
    Steering(FrontWheels & frontWheels);

    static int16_t getSteeringRange() {return fullSteeringRange;};

    void center();
    void steer(LineSegment & line);

private:
    int16_t getNewSteering(LineSegment & line, int16_t currentSteering);
    int16_t getSteeringDelta(LineSegment & line, int16_t currentSteering);
    int16_t getSteeringRangeForY(int16_t screenY);
    bool isOffLine(LineSegment & line);

};


#endif //ROBOTEXLINEFOLLOWERMAIN_STEERING_H
