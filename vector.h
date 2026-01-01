#ifndef VECTOR
#define VECTOR


class vector {
    public:
        double x;
        double y;
        double z;
        bool w;

        vector(double x, double y, double z, bool w){
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
        }
};

#endif