//
// Created by indrek on 20.09.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_DATABUFFERRECEIVER_H
#define ROBOTEXLINEFOLLOWERMAIN_DATABUFFERRECEIVER_H


#include <arduino.h>



class DataBufferReceiver {

private:
    static const int PIN_DATA_READY = 7;
    static const int PIN_POP_FIFO = 8;
    static const int PIN_CLOCK_ENABLE = 4;


public:
    DataBufferReceiver();

    bool isDataRead();
    uint8_t read();


private:


};


#endif //ROBOTEXLINEFOLLOWERMAIN_DATABUFFERRECEIVER_H
