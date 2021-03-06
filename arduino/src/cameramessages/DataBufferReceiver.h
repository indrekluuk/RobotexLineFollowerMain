//
// Created by indrek on 20.09.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_DATABUFFERRECEIVER_H
#define ROBOTEXLINEFOLLOWERMAIN_DATABUFFERRECEIVER_H


#include <Arduino.h>
#include <SPI.h>


/*
  PINB/PORTB (digital pin 8 to 13)
  PIND/PORTD (digital pins 0 to 7)
 */

#define DATA_READY_PORT PIND
#define DATA_READY_MASK 0b10000000
#define POP_FIFO_PORT PORTB
#define POP_FIFO_MASK 0b00000001
#define CLOCK_ENABLE_PORT PORTB
#define CLOCK_ENABLE_MASK 0b00000010

#define MESSAGE_BUFFER_LENGTH 16
#define MESSAGE_START 0x80
#define MESSAGE_COMMAND_MASK 0x70
#define MESSAGE_COUNT_MASK 0x0F




class DataBufferReceiver {

private:

    static const int PIN_DATA_READY = 7;
    static const int PIN_POP_FIFO = 8;
    static const int PIN_CLOCK_ENABLE = 9;

    static uint8_t messageBuffer[];
    static uint8_t messageIndex;
    static uint8_t messageLength;
    static uint8_t messageCommandCode;

public:
    DataBufferReceiver();

    inline bool isDataReady() __attribute__((always_inline));
    uint8_t readByte();
    uint8_t readMessage();
    uint8_t * getMessageBuffer() {return messageBuffer;};
    uint8_t getReceivedMessageLength() {return messageLength;};
    uint8_t getReceivedCommandCode() {return messageCommandCode;};


private:
    inline uint8_t getNextByte() __attribute__((always_inline));


};



bool DataBufferReceiver::isDataReady() {
  return DATA_READY_PORT & DATA_READY_MASK;
}

uint8_t DataBufferReceiver::getNextByte() {
  POP_FIFO_PORT = POP_FIFO_PORT | POP_FIFO_MASK; //digitalWrite(PIN_POP_FIFO, HIGH);

  //uint8_t byte = SPI.transfer(0);


  SPDR = 0;
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");

  POP_FIFO_PORT = POP_FIFO_PORT & ~POP_FIFO_MASK; //digitalWrite(PIN_POP_FIFO, LOW);
  return SPDR;
}



#endif //ROBOTEXLINEFOLLOWERMAIN_DATABUFFERRECEIVER_H
