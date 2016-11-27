//
// Created by indrek on 27.11.2016.
//

#include "Servo.h"





Servo::Servo() {
  writePos = 0;
}


void Servo::attach(int pin) {

}


void Servo::write(int pos) {
  writePos = pos;
}


int Servo::getWrittenPos() const {
  return writePos;
}


