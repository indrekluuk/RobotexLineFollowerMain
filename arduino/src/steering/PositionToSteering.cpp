//
// Created by indrek on 27.11.2016.
//

#include "PositionToSteering.h"


PositionToSteering::PositionToSteering(LineSegment & lineOnScreen) :
    line(lineOnScreen)
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
  int16_t centeredX = line.lineOnScreen.x2 - (12*currentSteering/100);
  int16_t range = getSteeringRangeForY(line.lineOnScreen.y2);
  int delta = centeredX * (range) / (line.lineOnScreen.range);
  return delta;
}




/*

int16_t PositionToSteering::getSteeringDelta(int16_t currentSteering) {
  int16_t trackingWorldX = getTrackingWorldX()
                           - (50*currentSteering/100); // todo replace 50 with some calculation;

  int16_t rangeForWorldX = line.getRangeInWorldForScreenY(trackingScreenY);
  int16_t steeringRange = getSteeringRangeForY(trackingScreenY);
  int delta = trackingWorldX  * steeringRange / (rangeForWorldX);
  return delta;
}




int16_t PositionToSteering::getTrackingWorldX() {
  int16_t trackingWorldY = line.getWorldY(trackingScreenY);
  int16_t trackingWorldX = (line.lineInWorld.x2-line.lineInWorld.x1)
                           *(trackingWorldY - line.lineInWorld.y1)
                           /(line.lineInWorld.y2 - line.lineInWorld.y1)
                           +line.lineInWorld.x1;
  return trackingWorldX;
}
*/
 
 

int16_t PositionToSteering::getSteeringRangeForY(int16_t screenY) {
  /*
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
  return range * 0.7;
   */
  return 60;
}



