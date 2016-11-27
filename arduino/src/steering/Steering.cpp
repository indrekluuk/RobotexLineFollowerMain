//
// Created by indrek on 27.11.2016.
//

#include "Steering.h"



Steering::Steering(FrontWheels & frontWheels) :
    frontWheels(frontWheels)
{
  frontWheels.setPositionRange(rangeX);
}


void Steering::steer(const LineSegment & line) {
  int16_t centeredX = line.x2 - centerX;
  frontWheels.set(-centeredX, 30);
}


