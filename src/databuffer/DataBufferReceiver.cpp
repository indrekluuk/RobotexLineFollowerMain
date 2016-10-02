//
// Created by indrek on 20.09.2016.
//

#include "DataBufferReceiver.h"
#include <SPI.h>


extern SPIClass SPI;
static SPISettings settings;



DataBufferReceiver::DataBufferReceiver() {
  settings = SPISettings(8000000, MSBFIRST, SPI_MODE1);
  pinMode(PIN_DATA_READY, INPUT);
  pinMode(PIN_POP_FIFO, OUTPUT);
  pinMode(PIN_CLOCK_ENABLE, OUTPUT);

  digitalWrite(PIN_CLOCK_ENABLE, HIGH);

  //digitalWrite(PIN_POP_FIFO, HIGH);
  digitalWrite(PIN_POP_FIFO, LOW);
}




bool DataBufferReceiver::isDataRead() {
  return digitalRead(PIN_DATA_READY);
}



uint8_t DataBufferReceiver::read() {
  //digitalWrite(PIN_POP_FIFO, HIGH);
  //digitalWrite(PIN_POP_FIFO, LOW);

  digitalWrite(PIN_POP_FIFO, HIGH);
  digitalWrite(PIN_CLOCK_ENABLE, LOW);
  SPI.beginTransaction(settings);
  uint8_t data = SPI.transfer(0);
  SPI.endTransaction();
  digitalWrite(PIN_CLOCK_ENABLE, HIGH);
  digitalWrite(PIN_POP_FIFO, LOW);


  return data;
  //return 0;
}





