#include <cmath>
#pragma once

class Tuple{
    public:
        float x;
        float y;
        float z;
        float w;

        Tuple() = default;

        Tuple(float x, float y, float z, float w){
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
        }

        Tuple operator+(Tuple a){
            return Tuple(this->x + a.x, this->y + a.y, this->z + a.z, this->w + a.w);
        }

        Tuple operator-(Tuple a){
            return Tuple(this->x - a.x, this->y - a.y, this->z - a.z, this->w - a.w);
        }

        Tuple operator-(){
            return Tuple(this->x * -1, this->y * -1, this->z * -1, this->w * -1);
        }


        Tuple operator*(Tuple a){
            return Tuple(this->x * a.x, this->y * a.y, this->z * a.z, this->w * a.w);
        }

        Tuple operator*(float a){
            return Tuple(this->x * a, this->y * a, this->z * a, this->w * a);
        }

        Tuple operator/(Tuple a){
            return Tuple(this->x / a.x, this->y / a.y, this->z / a.z, this->w / a.w);
        }

        Tuple operator/(float a){
            return Tuple(this->x / a, this->y / a, this->z / a, this->w / a);
        }
};

Tuple Point(float x, float y, float z){
    Tuple point = Tuple(x,y,z,1.0f);
    return point;
}

Tuple Vector(float x, float y, float z){
    Tuple vector = Tuple(x,y,z,0.0f);
    return vector;
}

float magnitude(Tuple a){
    return std::sqrtf(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}

Tuple normalize(Tuple a){
    float mag = magnitude(a);
    return Tuple(a.x / mag, a.y / mag, a.z / mag, a.w / mag);
}

float dot(Tuple a, Tuple b){
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

Tuple cross (Tuple a, Tuple b){
    return Vector(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}