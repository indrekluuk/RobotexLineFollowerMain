cmake_minimum_required(VERSION 3.2)
project(RobotexLineFollowerMain)


# PlatformIO build targets
# Must init platformio. See: PlatformIO_CLion_init.txt
add_subdirectory(arduino)





# init Google Test target
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")

# fake arduino headers
include_directories(test/fake)
# project headers
include_directories(arduino/src)
# gtest headers
include_directories(${gtest_SOURCE_DIR}/include)

add_executable(runTests
        arduino/src/steering/ScreenToWorldY.cpp
        arduino/src/steering/FrontWheels.cpp
        arduino/src/steering/ScreenToWorld.cpp

        test/fake/Arduino.cpp
        test/fake/Servo.cpp

        test/src/steering/FrontWheelTest.cpp
        test/src/steering/ScreenToWorldTest.cpp
        )

# link
add_subdirectory(test/lib/gtest-1.7.0)
target_link_libraries(runTests gtest_main)



