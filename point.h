#ifndef POINT
#define POINT

#include "vector.h"

class Point : public Vector {
    public:
        Point(double x, double y, double z){
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = true;
        }
};

#endif