//
// Created by indrek on 13.11.2016.
//


#include "gtest/gtest.h"
#include "steering/ScreenToWorld.h"




TEST(ScreenToWorldTest, testCenterLine) {
  LineSegment onScreen(15, 0, 0, 0, 119);
  ScreenToWorld screenToWorld(onScreen);

  ASSERT_EQ(0, screenToWorld.lineInWorld.x1);
  ASSERT_EQ(0, screenToWorld.lineInWorld.y1);
  ASSERT_EQ(0, screenToWorld.lineInWorld.x2);
  ASSERT_EQ(ScreenToWorld::screenToWorldYTable[119], screenToWorld.lineInWorld.y2);
}


TEST(ScreenToWorldTest, testDiagonalLine) {
  LineSegment onScreen(15, 14, 8, -12, 100);
  ScreenToWorld screenToWorld(onScreen);

  ASSERT_EQ(17, screenToWorld.lineInWorld.x1);
  ASSERT_EQ(7, screenToWorld.lineInWorld.y1);
  ASSERT_EQ(-52, screenToWorld.lineInWorld.x2);
  ASSERT_EQ(170, screenToWorld.lineInWorld.y2);
}



