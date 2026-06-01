#pragma once

#include "tuple.h"
#include "matrix.h"
#include "material.h"

class Sphere{
    public:

        int id;
        Matrix transformation = identityMatrix();
        Material m;

        Sphere(){
            this->id = std::rand();
            this->m = Material();
        }

        Sphere(Material m){
            this->id = std::rand();
            this->m = m;
        }

        void setTransform(Matrix t){
            this->transformation = this->transformation * t;
        }

        Tuple normalAt(Tuple p){
            Tuple objectPoint = this->transformation.inverse() * p;
            Tuple objectNormal = objectPoint - Point(0,0,0);
            Tuple worldNormal = this->transformation.inverse().transpose() * objectNormal;
            worldNormal.w = 0;
            return normalize(worldNormal);
        }
};