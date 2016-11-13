//
// Created by indrek on 30.10.2016.
//


#include <line/RowLinePosition.h>
#include "gtest/gtest.h"





TEST(LineTest, testLineNotFound) {
  //                             7654321001234567
  RowLinePosition linePosition(0b0000000000000000);
  int8_t linePos = linePosition.getLinePosition(0);
  ASSERT_TRUE(linePosition.isLineNotFound(linePos));
}


TEST(LineTest, testLineInTheMiddle) {
  //                             7654321001234567
  RowLinePosition linePosition(0b0000000110000000);
  int8_t linePos = linePosition.getLinePosition(0);
  ASSERT_EQ(0, linePos);
}


TEST(LineTest, testLineOnTheEdge1) {
  //                             7654321001234567
  RowLinePosition linePosition(0b0100000000000000);
  int8_t linePos = linePosition.getLinePosition(0);
  ASSERT_EQ(13, linePos);
}


TEST(LineTest, testLineOnTheEdge2) {
  //                             7654321001234567
  RowLinePosition linePosition(0b0000000000000010);
  int8_t linePos = linePosition.getLinePosition(0);
  ASSERT_EQ(-13, linePos);
}


TEST(LineTest, testOhterLineBeforeCenterLine) {
  //                             7654321001234567
  RowLinePosition linePosition(0b0000001000000110);
  int8_t linePos = linePosition.getLinePosition(0);
  ASSERT_EQ(3, linePos);
}


TEST(LineTest, testOhterLineAfterCenterLine) {
  //                             7654321001234567
  RowLinePosition linePosition(0b0011001000000000);
  int8_t linePos = linePosition.getLinePosition(0);
  ASSERT_EQ(3, linePos);
}


TEST(LineTest, testWideLine) {
  //                             7654321001234567
  RowLinePosition linePosition(0b0000011111000000);
  int8_t linePos = linePosition.getLinePosition(0);
  ASSERT_EQ(1, linePos);
}


TEST(LineTest, testShiftedSeekPoint1) {
  //                             7654321001234567
  RowLinePosition linePosition(0b0001000111000110);
  int8_t linePos = linePosition.getLinePosition(7);
  ASSERT_EQ(9, linePos);
}


TEST(LineTest, testShiftedSeekPoint2) {
  //                             7654321001234567
  RowLinePosition linePosition(0b0001000111000110);
  int8_t linePos = linePosition.getLinePosition(-9);
  ASSERT_EQ(-12, linePos);
}



