//
// Created by indrek on 20.09.2016.
//

#include "databuffer/DataBufferReceiver.h"
#include "line/Line.h"
#include <Arduino.h>
#include <Servo.h>


DataBufferReceiver dataBufferReceiver;
Line line;

int PIN_FRONT_WHEELS = 3;
int PIN_FORWARD = 6;
int PIN_REVERSE = 5;


int steeringMin = 45;
int steeringMax = 150;


Servo frontWheels;



int getSteering(int8_t line);



void run() {

  Serial.begin(250000);

  pinMode(PIN_FORWARD, OUTPUT);
  pinMode(PIN_REVERSE, OUTPUT);
  digitalWrite(PIN_REVERSE, LOW);
  digitalWrite(PIN_FORWARD, LOW);

  frontWheels.attach(PIN_FRONT_WHEELS);

  Serial.println("START");
  bool newFrame = true;

  while(1) {
    if (millis() > 5000) {
      //analogWrite(PIN_FORWARD, 70);
    }

    uint8_t length = dataBufferReceiver.readMessage();
    if (length == 3) {
      line.setRowBitmap(
          dataBufferReceiver.getMessageBuffer()[0],
          dataBufferReceiver.getMessageBuffer()[1],
          dataBufferReceiver.getMessageBuffer()[2]);

      Serial.println((int)(dataBufferReceiver.getMessageBuffer()[0]));

      if (dataBufferReceiver.getMessageBuffer()[0] == 0) {
        newFrame = true;
      }

/*
      if (dataBufferReceiver.getMessageBuffer()[0] == 30) {
        Serial.print((int)dataBufferReceiver.getMessageBuffer()[1]);
        Serial.print("_");
        Serial.print((int)dataBufferReceiver.getMessageBuffer()[2]);
        Serial.println();
      }
*/


      if (line.isLineFound() && newFrame) {
        newFrame = false;
        int8_t linePos = line.getLinePosition();
        int8_t rowStart = line.getLineStartRow();
        int8_t rowEnd = line.getLineEndRow();
        //frontWheels.write(getSteering(linePos));

        Serial.print((int)linePos);
        Serial.print("_");
        Serial.print((int)rowStart);
        Serial.print("_");
        Serial.print((int)rowEnd);
        Serial.println("");
      }

    }
  }
}



int8_t steeringLinePos = 0;

int getSteering(int8_t linePos) {
  //70 .. 140
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
}





