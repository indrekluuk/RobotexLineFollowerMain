//
// Created by indrek on 20.09.2016.
//

#include "databuffer/DataBufferReceiver.h"
#include <Arduino.h>


DataBufferReceiver dataBufferReceiver;


void run() {

  Serial.begin(9600);

  Serial.println("START");


  while(1) {
    if (dataBufferReceiver.readMessage()) {
      Serial.println((char *)dataBufferReceiver.getMessageBuffer());
    }
  }
}



