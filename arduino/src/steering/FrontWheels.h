//
// Created by indrek on 26.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_FRONT_WHEELS_H
#define ROBOTEXLINEFOLLOWERMAIN_FRONT_WHEELS_H


#include <Servo.h>
#include "Arduino.h"




class FrontWheels {

public:
    static const int16_t steeringMin = 45;
    static const int16_t steeringMax = 150;
    static const int16_t steeringCenter = (int16_t)((steeringMax+steeringMin)/2);
    static const int16_t steeringRange = steeringMax - steeringCenter;

private:
    Servo frontWheelsServo;
    int16_t positionRange;


public:
    FrontWheels();
    FrontWheels(int16_t positionRange);
    void init(int frontWheelsPin);
    const Servo & getServo();

    void setPositionRange(int16_t positionRange);
    void set(int16_t position);

    int16_t getSteeringMin() {return steeringMin; };
    int16_t getSteeringMax() {return steeringMax; };
    int16_t getSteeringCenter() {return steeringCenter; };

private:
    int positionToSteering(int16_t position);

};


#endif //ROBOTEXLINEFOLLOWERMAIN_FRONT_WHEELS_H
