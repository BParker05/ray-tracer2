#pragma once

#include "tuple.h"
#include "matrix.h"
#include "material.h"

class Sphere{
    public:

        int id;
        Matrix transformation = identityMatrix();
        Material material;

        Sphere(){
            this->id = std::rand();
            this->material = Material();
        }

        Sphere(Material material){
            this->id = std::rand();
            this->material = material;
        }

        void setTransform(Matrix transformMatrix){
            this->transformation = this->transformation * transformMatrix;
        }

        Tuple normalAt(Tuple p){
            Tuple objectPoint = this->transformation.inverse() * p;
            Tuple objectNormal = objectPoint - Point(0,0,0);
            Tuple worldNormal = this->transformation.inverse().transpose() * objectNormal;
            worldNormal.w = 0;
            return normalize(worldNormal);
        }
};