//
// Created by indrek on 30.10.2016.
//


#include <line/Line.h>
#include "gtest/gtest.h"





TEST(LineTest, testLineNotFound) {
  Line line;
  int8_t linePos = line.getLine(0, 0b00000000, 0b00000000);
  ASSERT_EQ(line.getLineNotFound(), linePos);
}


TEST(LineTest, testLineInTheMiddle) {
  Line line;
  int8_t linePos = line.getLine(0, 0b00000001, 0b10000000);
  ASSERT_EQ(0, linePos);
}


TEST(LineTest, testLineOnTheEdge1) {
  Line line;
  int8_t linePos = line.getLine(0, 0b01000000, 0b00000000);
  ASSERT_EQ(13, linePos);
}


TEST(LineTest, testLineOnTheEdge2) {
  Line line;
  int8_t linePos = line.getLine(0, 0b00000000, 0b00000010);
  ASSERT_EQ(-13, linePos);
}


TEST(LineTest, testOhterLineBeforeCenterLine) {
  Line line;
  int8_t linePos = line.getLine(0, 0b00000010, 0b00000110);
  ASSERT_EQ(3, linePos);
}


TEST(LineTest, testOhterLineAfterCenterLine) {
  Line line;
  int8_t linePos = line.getLine(0, 0b00110010, 0b00000000);
  ASSERT_EQ(3, linePos);
}


TEST(LineTest, testWideLine) {
  Line line;
  int8_t linePos = line.getLine(0, 0b00000111, 0b11000000);
  ASSERT_EQ(1, linePos);
}

