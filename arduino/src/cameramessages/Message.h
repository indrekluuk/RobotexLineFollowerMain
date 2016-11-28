//
// Created by indrek on 26.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_MESSAGE_H
#define ROBOTEXLINEFOLLOWERMAIN_MESSAGE_H


#include "DataBufferReceiver.h"
#include "../data/LineSegment.h"




class Message {
    using FnLineSegmentCallback = void(LineSegment & line);


    const static uint8_t COMMAND_LINE_SEGMENT = 0x10;
    const static int16_t lineSegmentMax = 30;
    const static int16_t lineSegmentCenter = lineSegmentMax/2;

    DataBufferReceiver receiver;

    FnLineSegmentCallback *fnLineSegmentReceived;

public:
    Message(FnLineSegmentCallback *fnLineSegmentReceived);

    void waitForMessage();

private:
    bool isLineSegmentReceived();

};


#endif //ROBOTEXLINEFOLLOWERMAIN_MESSAGE_H
