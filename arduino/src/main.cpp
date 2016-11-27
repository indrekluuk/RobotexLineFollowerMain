//
// Created by indrek on 20.09.2016.
//


#include "engine/Engine.h"
#include "steering/Steering.h"
#include "cameramessages/Message.h"




int PIN_FORWARD = 6;
int PIN_REVERSE = 5;
int PIN_FRONT_WHEELS = 3;



Engine engine(PIN_FORWARD, PIN_REVERSE);
Steering steering(PIN_FRONT_WHEELS);



void lineSegmentReceived(const LineSegment & line);



void run() {

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








