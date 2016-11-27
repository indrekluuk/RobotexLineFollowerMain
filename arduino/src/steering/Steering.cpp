//
// Created by indrek on 27.11.2016.
//

#include "Steering.h"



Steering::Steering() :
    frontWheels(rangeX)
{
}


void Steering::init(int frontWheelsPin) {
  frontWheels.init(frontWheelsPin);
}


void Steering::steer(const LineSegment & line) {
  int16_t centeredX = line.x2 - centerX;
  frontWheels.set(centeredX, 10);
}


