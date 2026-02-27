#pragma once

#include "tuple.h"

class Environment{
    public:

        Tuple gravity;
        Tuple wind;

        Environment() = default;

        Environment(Tuple gravity, Tuple wind){
            this->gravity = gravity;
            this->wind = wind;
        }
};