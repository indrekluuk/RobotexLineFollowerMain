//
// Created by indrek on 26.11.2016.
//

#include "FrontWheels.h"




FrontWheels::FrontWheels() :
    positionRange(1)
{
}

FrontWheels::FrontWheels(int16_t positionRange) : positionRange(positionRange) {
}


void FrontWheels::init(int frontWheelsPin) {
  frontWheelsServo.attach(frontWheelsPin);
}


const Servo & FrontWheels::getServo() {
  return frontWheelsServo;
}


void FrontWheels::setPositionRange(int16_t range) {
  positionRange = range;
}


void FrontWheels::set(int16_t position) {
  int steering = positionToSteering(position);
  if (steering < steeringMin) steering = steeringMin;
  if (steering > steeringMax) steering = steeringMax;
  frontWheelsServo.write(steering);
}



int FrontWheels::positionToSteering(int16_t position) {
  int fullSteeringRange = position * (steeringRange) / (positionRange);
  return fullSteeringRange + steeringCenter;
}

