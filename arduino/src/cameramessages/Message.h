//
// Created by indrek on 26.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_MESSAGE_H
#define ROBOTEXLINEFOLLOWERMAIN_MESSAGE_H


#include "DataBufferReceiver.h"
#include "LineSegment.h"




class Message {
    using FnLineSegmentCallback = void(const LineSegment & line);


    const static uint8_t COMMAND_LINE_SEGMENT = 0x10;
    DataBufferReceiver receiver;

    FnLineSegmentCallback *fnLineSegmentReceived;

public:
    Message(FnLineSegmentCallback *fnLineSegmentReceived);

    void waitForMessage();

private:
    bool isLineSegmentReceived();

};


#endif //ROBOTEXLINEFOLLOWERMAIN_MESSAGE_H
