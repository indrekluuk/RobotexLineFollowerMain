//
// Created by indrek on 26.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_FRONT_WHEELS_H
#define ROBOTEXLINEFOLLOWERMAIN_FRONT_WHEELS_H


#include <Servo.h>
#include "Arduino.h"




class FrontWheels {

public:
    const int16_t steeringMin = 45;
    const int16_t steeringMax = 150;
    const int16_t steeringCenter = (int16_t)((steeringMax+steeringMin)/2);
    const int16_t steeringRange = steeringMax - steeringCenter;

private:
    Servo frontWheelsServo;
    int16_t positionRange;


public:
    FrontWheels(int16_t positionRange);
    void init(int frontWheelsPin);
    const Servo & getServo();

    void set(int16_t position, int16_t rangeInPercentage);

private:
    int steeringToPosition(int16_t position, int16_t rangeInPercentage);

};


#endif //ROBOTEXLINEFOLLOWERMAIN_FRONT_WHEELS_H
