//
// Created by indrek on 20.09.2016.
//


#include "engine/Engine.h"
#include "steering/FrontWheels.h"
#include "steering/Steering.h"
#include "cameramessages/Message.h"


#define DISABLE_CONTROLS 1



int PIN_FORWARD = 6;
int PIN_REVERSE = 5;
int PIN_FRONT_WHEELS = 3;



Engine engine(PIN_FORWARD, PIN_REVERSE);
FrontWheels frontWheels;
Steering steering(frontWheels);



void lineSegmentReceived(const LineSegment & line);
void angleTest();


void run() {
#if DISABLE_CONTROLS == 0
  frontWheels.init(PIN_FRONT_WHEELS);
  //angleTest();

  steering.center();

  Serial.begin(250000);
  Serial.println("Waiting...");
  delay(5000);
  Serial.println("Start");

  Message message(lineSegmentReceived);
  while(1) {
    message.waitForMessage();
  }
#endif
}


void angleTest() {
  /*
  frontWheels.setPositionRange(100);

  while(true) {
    frontWheels.set(0);
    delay(3000);
    frontWheels.set(-100);
    delay(3000);
    frontWheels.set(-90);
    delay(3000);
    frontWheels.set(-80);
    delay(3000);
    frontWheels.set(-70);
    delay(3000);
  }

  */
}




void lineSegmentReceived(const LineSegment & line) {
  steering.steer(line);

  Serial.print("x1=");
  Serial.print((int)line.x1);

  Serial.print("; y1=");
  Serial.print((int)line.y1);

  Serial.print("; x2=");
  Serial.print((int)line.x2);

  Serial.print("; y2=");
  Serial.print((int)line.y2);

  Serial.println("\n");
  engine.drive(70);
}








