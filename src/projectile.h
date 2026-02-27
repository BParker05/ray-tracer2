#pragma once

#include "tuple.h"

class Projectile{
    public:

        Tuple position;
        Tuple velocity;

        Projectile() = default;

        Projectile(Tuple position, Tuple velocity){
            this->position = position;
            this->velocity = velocity;
        }

};