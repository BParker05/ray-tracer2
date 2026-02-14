#include <iostream>

#include "tuple.h"

int main(){
 
    Tuple a = Vector(1,2,3);
    Tuple b = Vector(2,3,4);

    Tuple c = cross(b,a);
    std::cout<< c.x << " " << c.y << " " << c.z << " " << c.w << std::endl;

    return 0;
    
}