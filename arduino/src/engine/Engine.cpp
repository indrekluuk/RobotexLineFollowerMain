//
// Created by indrek on 26.11.2016.
//

#include "Engine.h"



Engine::Engine(int forwardPin, int reversePin) :
    forwardPin(forwardPin),
    reversePin(reversePin)
{
  pinMode(forwardPin, OUTPUT);
  pinMode(reversePin, OUTPUT);
  stop();
}



void Engine::stop() {
  digitalWrite(forwardPin, LOW);
  digitalWrite(reversePin, LOW);
}



void Engine::drive(int power) {
  analogWrite(forwardPin, power);
}






