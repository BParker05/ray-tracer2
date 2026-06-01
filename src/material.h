#pragma once

#include "colour.h"

class Material {
    public:
        float ambient;
        float diffuse;
        float specular;
        float shininess;
        Colour c;

        Material(){
            this->ambient = 0.1;
            this->diffuse = 0.9;
            this->specular = 0.9;
            this->shininess = 200;
            this->c = Colour(1,1,1);
        };

        Material(float ambient, float diffuse, float specular, float shininess){
            this->ambient = ambient;
            this->diffuse = diffuse;
            this->specular = specular;
            this->shininess = shininess;
            this->c = Colour(1,1,1);
        }

        Material(Colour c){
            this->ambient = 0.1;
            this->diffuse = 0.9;
            this->specular = 0.9;
            this->shininess = 200;
            this->c = c;
        }

};