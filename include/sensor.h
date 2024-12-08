#include "vex.h"
#include <math.h>
#include <array>

#pragma once


// class colordesc {
// public:
//     colordesc() {} // Default constructor
//     colordesc(int id, int r, int g, int b, double size, double tolerance) {
//         // Initialize the object with parameters
//     }
// };
// std::array<aivision::colordesc, 2> colors = { redRing, blueRing };

class Sensor {
public:
    void aiGetXPos();
    int getDistance();  // unit in cm
    int redAveCount();
    int redSinCount();
    bool isBlueAbove();

    int ringInStack(); 

    int ringCountDist(); // number of ring in stake base on distant sensor
    
    void ifUp();
    void printHue();
    
};

