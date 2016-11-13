//
// Created by indrek on 13.11.2016.
//


#include "line/Line.h"
#include "gtest/gtest.h"



TEST(LineTest, testLineNotFound) {
  Line line;
  ASSERT_FALSE(line.isLineFound());
}



TEST(LineTest, testEndOfLineNotFoundYet) {
  Line line;
  line.setRowBitmap(0, 0b00010000, 0b00000000);
  line.setRowBitmap(1, 0b00010000, 0b00000000);
  line.setRowBitmap(2, 0b00010000, 0b00000000);
  ASSERT_FALSE(line.isLineFound());
}



TEST(LineTest, testLineFound) {
  Line line;
  line.setRowBitmap(0, 0b00010000, 0b00000000);
  line.setRowBitmap(1, 0b00010000, 0b00000000);
  line.setRowBitmap(2, 0b00010000, 0b00000000);
  line.setRowBitmap(3, 0b00000000, 0b00000000);
  ASSERT_TRUE(line.isLineFound());
  ASSERT_EQ(9, line.getLinePosition());
}



TEST(LineTest, testLineAcrossTheScreen) {
  Line line;
  for (int i=0; i<Line::getRowCount(); i++) {
    line.setRowBitmap(i, 0b000010000, 0b000000000);
  }
  ASSERT_TRUE(line.isLineFound());
  ASSERT_EQ(9, line.getLinePosition());
}




TEST(LineTest, testSlantedLine) {
  Line line;
  line.setRowBitmap(0, 0b00000010, 0b00000000);
  line.setRowBitmap(1, 0b00000010, 0b00000000);
  line.setRowBitmap(2, 0b00000100, 0b00000000);
  line.setRowBitmap(3, 0b00000100, 0b00000000);
  line.setRowBitmap(4, 0b00000100, 0b00000000);
  line.setRowBitmap(5, 0b00001000, 0b00000000);
  line.setRowBitmap(6, 0b00001000, 0b00000000);
  line.setRowBitmap(7, 0b00000000, 0b00000000);
  ASSERT_TRUE(line.isLineFound());
  ASSERT_EQ(7, line.getLinePosition());
}




TEST(LineTest, testLineTurnsInSlantDirection) {
  Line line;
  line.setRowBitmap(0,  0b00000000, 0b00000100);
  line.setRowBitmap(1,  0b00000000, 0b00000100);
  line.setRowBitmap(2,  0b00000000, 0b00001000);
  line.setRowBitmap(3,  0b00000000, 0b00001000);
  line.setRowBitmap(4,  0b00000000, 0b00001000);
  line.setRowBitmap(5,  0b00000000, 0b00001000);
  line.setRowBitmap(6,  0b00000000, 0b11110000);
  line.setRowBitmap(7,  0b00000111, 0b10000000);
  line.setRowBitmap(8,  0b00111100, 0b00000000);
  line.setRowBitmap(9,  0b11100000, 0b00000000);
  line.setRowBitmap(10, 0b00000000, 0b00000000);
  ASSERT_TRUE(line.isLineFound());
  ASSERT_EQ(-9, line.getLinePosition());
}



