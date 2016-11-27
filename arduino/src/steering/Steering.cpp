//
// Created by indrek on 26.11.2016.
//

#include "Steering.h"




Steering::Steering(int steeringPin) {
  steeringServo.attach(steeringPin);
}




int8_t steeringLinePos = 0;

int getSteering(int8_t linePos) {
  //70 .. 140
  /*
  if (RowLinePosition::isInRange(linePos)) {
    if (abs(linePos - steeringLinePos) > 2) {
      steeringLinePos = linePos;
    }

    int steering = map((int)steeringLinePos, -RowLinePosition::getRowRange(), RowLinePosition::getRowRange(), 150, 45); // 155, 40
    if (steering < steeringMin) steering = steeringMin;
    if (steering > steeringMax) steering = steeringMax;
    return steering;
  } else {
    return 100;
  }
   */
  return 0;
}


