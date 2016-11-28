//
// Created by indrek on 26.11.2016.
//

#include "Message.h"





Message::Message(FnLineSegmentCallback *fnLineSegmentReceived) :
    fnLineSegmentReceived(fnLineSegmentReceived)
{

}



void Message::waitForMessage() {
  if (receiver.readMessage()) {
    if (isLineSegmentReceived()) {
      fnLineSegmentReceived(LineSegment(
          lineSegmentCenter,
          ((int16_t)receiver.getMessageBuffer()[1])-lineSegmentCenter,
          ((int16_t)receiver.getMessageBuffer()[0]),
          ((int16_t)receiver.getMessageBuffer()[3])-lineSegmentCenter,
          ((int16_t)receiver.getMessageBuffer()[2])
      ));
    }
  }
}



bool Message::isLineSegmentReceived() {
  return receiver.getReceivedMessageLength() == 4
         && receiver.getReceivedCommandCode() == COMMAND_LINE_SEGMENT;
}






