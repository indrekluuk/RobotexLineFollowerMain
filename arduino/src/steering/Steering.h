//
// Created by indrek on 26.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_STEERING_H
#define ROBOTEXLINEFOLLOWERMAIN_STEERING_H


#include <Servo.h>




class Steering {

    static const int steeringMin = 45;
    static const int steeringMax = 150;


    Servo steeringServo;


public:
    Steering(int steeringPin);

};


#endif //ROBOTEXLINEFOLLOWERMAIN_STEERING_H
