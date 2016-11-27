//
// Created by indrek on 27.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_SERVO_H
#define ROBOTEXLINEFOLLOWERMAIN_SERVO_H


class Servo {

    int writePos;

public:
    Servo();

    void attach(int pin);
    void write(int pos);
    int getWrittenPos() const;

};


#endif //ROBOTEXLINEFOLLOWERMAIN_SERVO_H
