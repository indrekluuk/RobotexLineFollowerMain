//
// Created by indrek on 26.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_ENGINE_H
#define ROBOTEXLINEFOLLOWERMAIN_ENGINE_H


#include <Arduino.h>



class Engine {


    int forwardPin;
    int reversePin;

public:
    Engine(int forwardPin, int reversePin);


    void stop();
    void drive(int power);

};


#endif //ROBOTEXLINEFOLLOWERMAIN_ENGINE_H
