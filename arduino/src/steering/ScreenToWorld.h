//
// Created by indrek on 28.11.2016.
//

#ifndef ROBOTEXLINEFOLLOWERMAIN_SCREENTOWORLD_H
#define ROBOTEXLINEFOLLOWERMAIN_SCREENTOWORLD_H


#include "../data/LineSegment.h"


class ScreenToWorld {


    const LineSegment & lineOnScreen;

    struct  {

    };

public:


    ScreenToWorld(const LineSegment & lineOnScreen);

};


#endif //ROBOTEXLINEFOLLOWERMAIN_SCREENTOWORLD_H
