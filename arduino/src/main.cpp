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



Servo frontWheels;



int getSteering(int8_t line);



void run() {

  Serial.begin(9600);

  pinMode(PIN_FORWARD, OUTPUT);
  pinMode(PIN_REVERSE, OUTPUT);
  digitalWrite(PIN_REVERSE, LOW);
  digitalWrite(PIN_FORWARD, LOW);

  frontWheels.attach(PIN_FRONT_WHEELS);
  //frontWheels.write(45); // min
  //frontWheels.write(150); // max


  Serial.println("START");
  int currentSteering = 100;
  int targetSteering = currentSteering;

  //digitalWrite(PIN_FORWARD, HIGH);
  //analogWrite(PIN_FORWARD, 70);
  //frontWheels.write(45);

  int startCounter = 0;
  while(1) {
    uint8_t length = dataBufferReceiver.readMessage();
    if (length == 3 && dataBufferReceiver.getMessageBuffer()[0] == 30) {

      startCounter++;
      if (startCounter == 50) {
        analogWrite(PIN_FORWARD, 100);
      }

      int8_t linePos = line.getLine(
          dataBufferReceiver.getMessageBuffer()[0],
          dataBufferReceiver.getMessageBuffer()[1],
          dataBufferReceiver.getMessageBuffer()[2]);

      frontWheels.write(getSteering(linePos));

      for (uint8_t i=0; i<length; i++) {
        Serial.print(dataBufferReceiver.getMessageBuffer()[i]);
        Serial.print("___");
      }
      Serial.print((int)linePos);
      Serial.println("n");
    }

    if (currentSteering > targetSteering) currentSteering--;
    if (currentSteering < targetSteering) currentSteering++;
    //frontWheels.write(currentSteering);
    //delay(1);

  }



  //pinMode(13, OUTPUT);

  //digitalWrite(PIN_REVERSE, 1);

  //frontWheels.write(100);
  while(1) {

    //digitalWrite(13, 1);
    //digitalWrite(13, 0);


    /*
    delay(3000);
    digitalWrite(PIN_REVERSE, 1);
    delay(3000);
    digitalWrite(PIN_REVERSE, 0);
    */

/*
    frontWheels.write(70);
    delay(2300);
    frontWheels.write(140);
    delay(2300);
*/
  }
}



int8_t steeringLinePos = 0;

int getSteering(int8_t linePos) {
  //70 .. 140
  if (abs(linePos) <= line.getLineRange()) {
    if (abs(linePos - steeringLinePos) > 2) {
      steeringLinePos = linePos;
    }

    int steering = map((int)steeringLinePos, -line.getLineRange(), line.getLineRange(), 150, 45); // 155, 40
    if (steering < 45) steering = 45;
    if (steering > 150) steering = 150;
    return steering;
  } else {
    return 100;
  }
}





