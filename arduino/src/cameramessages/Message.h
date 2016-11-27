//
// Created by indrek on 26.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_MESSAGE_H
#define ROBOTEXLINEFOLLOWERMAIN_MESSAGE_H


#include "DataBufferReceiver.h"



struct LineSegment {
    uint8_t x1;
    uint8_t y1;
    uint8_t x2;
    uint8_t y2;
    LineSegment(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
        : x1(x1), y1(y1), x2(x2), y2(y2) {}
};




class Message {
    using FnLineSegmentCallback = void (*)(const LineSegment & line);


    const static uint8_t COMMAND_LINE_SEGMENT = 0x10;
    DataBufferReceiver receiver;

    FnLineSegmentCallback fnLineSegmentReceived;

public:
    Message(FnLineSegmentCallback fnLineSegmentReceived);

    void waitForMessage();

private:
    bool isLineSegmentReceived();

};


#endif //ROBOTEXLINEFOLLOWERMAIN_MESSAGE_H
