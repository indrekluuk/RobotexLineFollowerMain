//
// Created by indrek on 13.11.2016.
//


#include "gtest/gtest.h"
#include "steering/FrontWheels.h"




TEST(FrontWheelTest, testServoToCenter) {
  FrontWheels frontWheels(10);
  frontWheels.set(0, 100);
  ASSERT_EQ(frontWheels.getSteeringCenter(), frontWheels.getServo().getWrittenPos());
}



TEST(FrontWheelTest, testServoMin) {
  FrontWheels frontWheels(10);
  frontWheels.set(-10, 100);
  ASSERT_EQ(frontWheels.getSteeringMin(), frontWheels.getServo().getWrittenPos());
}



TEST(FrontWheelTest, testServoMax) {
  FrontWheels frontWheels(10);
  frontWheels.set(10, 100);
  ASSERT_EQ(frontWheels.getSteeringMax(), frontWheels.getServo().getWrittenPos());
}



TEST(FrontWheelTest, testServoLessThanMin) {
  FrontWheels frontWheels(10);
  frontWheels.set(-15, 100);
  ASSERT_EQ(frontWheels.getSteeringMin(), frontWheels.getServo().getWrittenPos());
}



TEST(FrontWheelTest, testServoMoreThanMax) {
  FrontWheels frontWheels(10);
  frontWheels.set(15, 100);
  ASSERT_EQ(frontWheels.getSteeringMax(), frontWheels.getServo().getWrittenPos());
}




TEST(FrontWheelTest, testServoMidWayToMin) {
  FrontWheels frontWheels(10);
  frontWheels.set(-5, 100);
  int quarter = frontWheels.getSteeringMin() + (frontWheels.getSteeringMax() - frontWheels.getSteeringMin())/4;
  ASSERT_EQ(quarter, frontWheels.getServo().getWrittenPos());
}



TEST(FrontWheelTest, testServoMidWayToMax) {
  FrontWheels frontWheels(10);
  frontWheels.set(5, 100);
  int quarter = frontWheels.getSteeringMin() + 3*(frontWheels.getSteeringMax() - frontWheels.getSteeringMin())/4;
  ASSERT_EQ(quarter, frontWheels.getServo().getWrittenPos());
}





TEST(FrontWheelTest, testLimitedRange1) {
  FrontWheels frontWheels(10);
  frontWheels.set(10, 50);
  int quarter = frontWheels.getSteeringMin() + 3*(frontWheels.getSteeringMax() - frontWheels.getSteeringMin())/4;
  ASSERT_EQ(quarter, frontWheels.getServo().getWrittenPos());
}




