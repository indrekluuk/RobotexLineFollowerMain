//
// Created by indrek on 27.11.2016.
//

#include "Steering.h"
#include "PositionToSteering.h"



Steering::Steering(FrontWheels & frontWheels) :
    frontWheels(frontWheels)
{
  frontWheels.setPositionRange(PositionToSteering::getSteeringRange());
  currentSteering = 0;
}


void Steering::center() {
  frontWheels.set(0);
  currentSteering = 0;
}


void Steering::steer(const LineSegment & line) {
  PositionToSteering toSteering(line);
  int16_t newSteering = toSteering.getNewSteering(currentSteering);
  if (abs(newSteering) < abs(currentSteering) || abs(newSteering - currentSteering) > 5) {
    frontWheels.set(-newSteering);
    currentSteering = newSteering;
  }
}


