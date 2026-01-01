#ifndef VECTOR
#define VECTOR


class Vector {
    public:
        double x;
        double y;
        double z;
        bool w = false;

        Vector() = default;

        Vector(double x, double y, double z){
            this->x = x;
            this->y = y;
            this->z = z;
        }
};

#endif