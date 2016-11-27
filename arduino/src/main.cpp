//
// Created by indrek on 20.09.2016.
//


#include "engine/Engine.h"
#include "steering/FrontWheels.h"
#include "steering/Steering.h"
#include "cameramessages/Message.h"




int PIN_FORWARD = 6;
int PIN_REVERSE = 5;
int PIN_FRONT_WHEELS = 3;



Engine engine(PIN_FORWARD, PIN_REVERSE);
FrontWheels frontWheels;
Steering steering(frontWheels);



void lineSegmentReceived(const LineSegment & line);



void run() {
  frontWheels.init(PIN_FRONT_WHEELS);

  Serial.begin(250000);
  Serial.println("Waiting...");
  delay(5000);
  Serial.println("Start");

  Message message(lineSegmentReceived);
  while(1) {
    message.waitForMessage();
  }
}




void lineSegmentReceived(const LineSegment & line) {
  //steering.steer(line);

  Serial.print("x1=");
  Serial.print((int)line.x1);

  Serial.print("; y1=");
  Serial.print((int)line.y1);

  Serial.print("; x2=");
  Serial.print((int)line.x2);

  Serial.print("; y2=");
  Serial.print((int)line.y2);

  Serial.println("\n");
}








