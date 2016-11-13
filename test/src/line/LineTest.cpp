//
// Created by indrek on 13.11.2016.
//


#include "line/Line.h"
#include "gtest/gtest.h"



TEST(LineTest, testLineNotFound) {
  Line line;
  ASSERT_FALSE(line.isLineFound());
}



