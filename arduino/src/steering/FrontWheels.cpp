//
// Created by indrek on 26.11.2016.
//

#include "FrontWheels.h"




FrontWheels::FrontWheels() {
}


void FrontWheels::init(int frontWheelsPin) {
  frontWheelsServo.attach(frontWheelsPin);
}


const Servo & FrontWheels::getServo() {
  return frontWheelsServo;
}



void FrontWheels::set(int16_t position) {
  int steering = steeringToPosition(position);
  if (steering < steeringMin) steering = steeringMin;
  if (steering > steeringMax) steering = steeringMax;
  frontWheelsServo.write(steering);
}



int FrontWheels::steeringToPosition(int16_t position) {
  return (position - positionMin) * (steeringMax - steeringMin) / (positionMax - positionMin) + steeringMin;
}

