//
// Created by indrek on 27.11.2016.
//

#include "Steering.h"



Steering::Steering(FrontWheels & frontWheels) :
    frontWheels(frontWheels)
{
  frontWheels.setPositionRange(fullSteeringRange);
  currentSteering = 0;
}


void Steering::center() {
  frontWheels.set(0);
  currentSteering = 0;
}


void Steering::steer(LineSegment & screenLine) {

  int16_t newSteering = getNewSteering(screenLine, currentSteering);
  if (abs(newSteering) < abs(currentSteering) || abs(newSteering - currentSteering) > 5) {
    frontWheels.set(-newSteering);
    currentSteering = newSteering;
  }
}




int16_t Steering::getNewSteering(LineSegment & line, int16_t currentSteering) {
  if (isOffLine(line)) {
    if (previouslyProcessedLine.x2 > 0) {
      return fullSteeringRange;
    }
    if (previouslyProcessedLine.x2 < 0) {
      return -fullSteeringRange;
    }
  }

  int16_t steeringDelta = getSteeringDelta(line, currentSteering);
  int16_t newSteering = currentSteering + steeringDelta;

  if (newSteering > fullSteeringRange) newSteering = fullSteeringRange;
  if (newSteering < -fullSteeringRange) newSteering = -fullSteeringRange;

  previouslyProcessedLine = line;
  return newSteering;
}




int16_t Steering::getSteeringDelta(LineSegment & line, int16_t currentSteering) {
  int16_t centeredX = line.x2 - (12*currentSteering/100);
  int16_t range = getSteeringRangeForY(line.y2);
  int delta = centeredX * (range) / (line.range);
  return delta;
}



int16_t Steering::getSteeringRangeForY(int16_t screenY) {
  int16_t range;
  if (screenY < 24) {
    range = 100;
  } else if (screenY < 30) {
    range = 95;
  } else if (screenY < 47) {
    range = 90;
  } else  if (screenY < 54) {
    range = 85;
  } else if (screenY < 60) {
    range = 80;
  } else {
    range = 75;
  }
  return range >> 1;
}




bool Steering::isOffLine(LineSegment & line) {
  return line.y1 > 30;
}



