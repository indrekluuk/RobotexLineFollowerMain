//
// Created by indrek on 26.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_FRONT_WHEELS_H
#define ROBOTEXLINEFOLLOWERMAIN_FRONT_WHEELS_H


#include <Servo.h>
#include "Arduino.h"




class FrontWheels {

public:
    const int16_t positionMin = -100;
    const int16_t positionMax = 100;
    const int16_t steeringMin = 45;
    const int16_t steeringMax = 150;

private:
    Servo frontWheelsServo;


public:
    FrontWheels();
    void init(int frontWheelsPin);
    const Servo & getServo();

    // -100 .. 100;
    void set(int16_t position);

private:
    int steeringToPosition(int16_t position);

};


#endif //ROBOTEXLINEFOLLOWERMAIN_FRONT_WHEELS_H
