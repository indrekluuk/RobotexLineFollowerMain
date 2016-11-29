//
// Created by indrek on 26.11.2016.
//

#include "Message.h"
#include "messagebuffer/LineSegmentMessageBuffer.h"





Message::Message(FnLineSegmentCallback *fnLineSegmentReceived) :
    fnLineSegmentReceived(fnLineSegmentReceived)
{

}



void Message::waitForMessage() {
  if (receiver.readMessage()) {
    if (isLineSegmentReceived()) {
      LineSegmentMessageBuffer &buffer = *((LineSegmentMessageBuffer*)receiver.getMessageBuffer());
      LineSegment lineSegment(
          lineSegmentCenter,
          buffer.lineBottomPosition - lineSegmentCenter,
          buffer.lineBottomIndex,
          buffer.lineTopPosition - lineSegmentCenter,
          buffer.lineTopIndex,
          buffer.isEndOfLine,
          buffer.isSharpTurn,
          buffer.sharpTurnDirection
      );
      fnLineSegmentReceived(lineSegment);
    }
  }
}



bool Message::isLineSegmentReceived() {
  return receiver.getReceivedMessageLength() == 4
         && receiver.getReceivedCommandCode() == COMMAND_LINE_SEGMENT;
}






