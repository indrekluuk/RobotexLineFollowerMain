//
// Created by indrek on 20.09.2016.
//

#include "databuffer/DataBufferReceiver.h"
#include <arduino.h>


DataBufferReceiver dataBufferReceiver;


void run() {

  Serial.begin(9600);

  Serial.println("START");
  uint8_t data[2];
  data[1] = 0;


  while(1) {
    if (dataBufferReceiver.isDataRead()) {

      for (int i=0; i<100; i++) {
        asm volatile("nop");
      }

      data[0] = dataBufferReceiver.read();
      if (data[0] & 0b10000000) {
        Serial.println("--------");
      }
      Serial.println(data[0]);
      //Serial.print(" ");
      //Serial.println((char *)data);
      //Serial.println((char *)data);

      //if (data[0] & 0b10000000) {
      //  data[0] = data[0] & 0b01111111;
      //  Serial.println();
      //}
      //Serial.print((char *)data);
      //delay(50);
    }

    //delay(11000);
  }
}



