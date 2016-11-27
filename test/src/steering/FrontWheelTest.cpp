//
// Created by indrek on 13.11.2016.
//


#include "gtest/gtest.h"
#include "steering/FrontWheels.h"




TEST(FrontWheelTest, testServoToCenter) {
  FrontWheels frontWheels(0);
  frontWheels.set(0);
  int center = (frontWheels.steeringMax + frontWheels.steeringMin)/2;
  ASSERT_EQ(center, frontWheels.getServo().getWrittenPos());
}



TEST(FrontWheelTest, testServoMin) {
  FrontWheels frontWheels(0);
  frontWheels.set(-100);
  ASSERT_EQ(frontWheels.steeringMin, frontWheels.getServo().getWrittenPos());
}



TEST(FrontWheelTest, testServoMax) {
  FrontWheels frontWheels(0);
  frontWheels.set(100);
  ASSERT_EQ(frontWheels.steeringMax, frontWheels.getServo().getWrittenPos());
}



TEST(FrontWheelTest, testServoLessThanMin) {
  FrontWheels frontWheels(0);
  frontWheels.set(-150);
  ASSERT_EQ(frontWheels.steeringMin, frontWheels.getServo().getWrittenPos());
}



TEST(FrontWheelTest, testServoMoreThanMax) {
  FrontWheels frontWheels(0);
  frontWheels.set(150);
  ASSERT_EQ(frontWheels.steeringMax, frontWheels.getServo().getWrittenPos());
}




TEST(FrontWheelTest, testServoMidWayToMin) {
  FrontWheels frontWheels(0);
  frontWheels.set(-50);
  int quarter = frontWheels.steeringMin + (frontWheels.steeringMax - frontWheels.steeringMin)/4;
  ASSERT_EQ(quarter, frontWheels.getServo().getWrittenPos());
}



TEST(FrontWheelTest, testServoMidWayToMax) {
  FrontWheels frontWheels(0);
  frontWheels.set(50);
  int quarter = frontWheels.steeringMin + 3*(frontWheels.steeringMax - frontWheels.steeringMin)/4;
  ASSERT_EQ(quarter, frontWheels.getServo().getWrittenPos());
}


