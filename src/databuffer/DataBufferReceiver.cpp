//
// Created by indrek on 20.09.2016.
//

#include "DataBufferReceiver.h"



uint8_t DataBufferReceiver::messageIndex = 0;
uint8_t DataBufferReceiver::messageLength = 0;
uint8_t DataBufferReceiver::messageBuffer[MESSAGE_BUFFER_LENGTH + 1]; // + 1 for null terminated string


DataBufferReceiver::DataBufferReceiver() {
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV2);
  pinMode(PIN_DATA_READY, INPUT);
  pinMode(PIN_POP_FIFO, OUTPUT);
  pinMode(PIN_CLOCK_ENABLE, OUTPUT);
  digitalWrite(PIN_CLOCK_ENABLE, HIGH);
  digitalWrite(PIN_POP_FIFO, LOW);
}



uint8_t DataBufferReceiver::readByte() {
  CLOCK_ENABLE_PORT = CLOCK_ENABLE_PORT & ~CLOCK_ENABLE_MASK; //digitalWrite(PIN_CLOCK_ENABLE, LOW);
  uint8_t byte = getNextByte();
  CLOCK_ENABLE_PORT = CLOCK_ENABLE_PORT | CLOCK_ENABLE_MASK; //digitalWrite(PIN_CLOCK_ENABLE, HIGH);
  return byte;
}




uint8_t DataBufferReceiver::readMessage() {

  if (isDataReady()) {
    CLOCK_ENABLE_PORT = CLOCK_ENABLE_PORT & ~CLOCK_ENABLE_MASK; //digitalWrite(PIN_CLOCK_ENABLE, LOW);

    do {
      uint8_t byte = getNextByte();
      if (byte >= MESSAGE_START) {
        messageIndex = 0;
        messageLength = byte & ~MESSAGE_START;
      } else if (messageIndex < MESSAGE_BUFFER_LENGTH) {
        messageBuffer[messageIndex] = byte;
        messageIndex++;
      }
    } while (isDataReady());

    CLOCK_ENABLE_PORT = CLOCK_ENABLE_PORT | CLOCK_ENABLE_MASK; //digitalWrite(PIN_CLOCK_ENABLE, HIGH);
  }

  if (messageIndex == messageLength) {
    messageBuffer[messageLength] = 0;
    messageIndex = 0;
    return messageLength;
  } else {
    return 0;
  }
}

/*
uint8_t DataBufferReceiver::readMessage() {
  digitalWrite(PIN_POP_FIFO, HIGH);
  digitalWrite(PIN_CLOCK_ENABLE, LOW);

  SPI.beginTransaction(settings);
  uint8_t data = SPI.transfer(0);
  SPI.endTransaction();

  digitalWrite(PIN_CLOCK_ENABLE, HIGH);
  digitalWrite(PIN_POP_FIFO, LOW);

  return data;
}
*/


