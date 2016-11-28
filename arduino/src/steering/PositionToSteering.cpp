//
// Created by indrek on 27.11.2016.
//

#include "PositionToSteering.h"


PositionToSteering::PositionToSteering(const LineSegment & line) :
    line(line)
{
}



int16_t PositionToSteering::getNewSteering(int16_t currentSteering) {
  int16_t steeringDelta = getSteeringDelta(currentSteering);
  int16_t newSteering = currentSteering + steeringDelta;

  if (newSteering > fullSteeringRange) newSteering = fullSteeringRange;
  if (newSteering < -fullSteeringRange) newSteering = -fullSteeringRange;
  return newSteering;
}



int16_t PositionToSteering::getSteeringDelta(int16_t currentSteering) {
  int16_t centeredX = line.x2 - centerX - (12*currentSteering/100);
  int16_t range = getSteeringRangeForY(line.y2);
  int delta = centeredX * (range) / (rangeX);
  return delta;
}


int16_t PositionToSteering::getSteeringRangeForY(int16_t y) {
  int16_t range;
  if (y < 24) {
    range = 100;
  } else if (y < 30) {
    range = 95;
  } else if (y < 47) {
    range = 90;
  } else  if (y < 54) {
    range = 85;
  } else if (y < 60) {
    range = 80;
  } else {
    range = 75;
  }
  return range * 0.3;
}



