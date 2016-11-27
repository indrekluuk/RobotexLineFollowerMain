//
// Created by indrek on 26.11.2016.
//

#include "Message.h"





Message::Message(FnLineSegmentCallback fnLineSegmentReceived) :
    fnLineSegmentReceived(fnLineSegmentReceived)
{

}



void Message::waitForMessage() {
  if (receiver.readMessage()) {
    if (isLineSegmentReceived()) {
      fnLineSegmentReceived(LineSegment(
          receiver.getMessageBuffer()[1],
          receiver.getMessageBuffer()[0],
          receiver.getMessageBuffer()[3],
          receiver.getMessageBuffer()[2]));
    }
  }
}



bool Message::isLineSegmentReceived() {
  return receiver.getReceivedMessageLength() == 4
         && receiver.getReceivedCommandCode() == COMMAND_LINE_SEGMENT;
}






