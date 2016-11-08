//
// Created by indrek on 20.09.2016.
//

#include "databuffer/DataBufferReceiver.h"
#include <Arduino.h>
#include <Servo.h>


DataBufferReceiver dataBufferReceiver;


int PIN_FRONT_WHEELS = 3;
int PIN_FORWARD = 6;
int PIN_REVERSE = 5;



Servo frontWheels;



int getSteeringDirection(int right, int left);
int getSteering(uint8_t line);


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

  int startCounter = 0;
  while(1) {
    uint8_t length = dataBufferReceiver.readMessage();
    if (length) {

      startCounter++;
      if (startCounter == 50) {
        analogWrite(PIN_FORWARD, 70);
      }

      for (uint8_t i=0; i<length; i++) {
        Serial.print(dataBufferReceiver.getMessageBuffer()[i]);
        Serial.print("_");
      }
      Serial.println("n");




      uint16_t line = dataBufferReceiver.getMessageBuffer()[0];
      if (line < 80) {
        if (line <20) {
          targetSteering += 40 - line - 20;
          if (targetSteering > 150) targetSteering = 150;
        }
        if (line >= 60) {
          targetSteering -= line - 40 - 20;
          if (targetSteering < 45) targetSteering = 45;
        }
      }
      frontWheels.write(getSteering(line));
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


int getSteering(uint8_t line) {
  //70 .. 140
  if (line < 80) {
    int steering = map((int)line, 0, 80, 155, 40);
    if (steering < 45) steering = 45;
    if (steering > 150) steering = 150;
    return steering;
  } else {
    return 100;
  }
}





