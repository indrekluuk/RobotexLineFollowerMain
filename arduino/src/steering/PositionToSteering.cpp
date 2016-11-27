//
// Created by indrek on 27.11.2016.
//

#include "PositionToSteering.h"


PositionToSteering::PositionToSteering(const LineSegment & line) :
    line(line)
{
}



int16_t PositionToSteering::getNewSteering(int16_t currentSteering) {
  int16_t steeringDelta = getSteeringDelta();
  int16_t newSteering = currentSteering + steeringDelta;
  if (newSteering > fullSteeringRange) newSteering = fullSteeringRange;
  if (newSteering < -fullSteeringRange) newSteering = -fullSteeringRange;
  return newSteering;
}



int16_t PositionToSteering::getSteeringDelta() {
  int16_t centeredX = line.x2 - centerX;
  int16_t range = getSteeringRangeForY(line.y2);
  int delta = centeredX * (range) / (rangeX);
  return delta;
}


int16_t PositionToSteering::getSteeringRangeForY(int16_t y) {
  return 30; // todo
}



