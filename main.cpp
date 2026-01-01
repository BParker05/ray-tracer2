#include <iostream>

#include "vector.h"

int main(){
    vector a(4.3,-4.2,3.1,true);

    std::cout << "x = " << a.x << std::endl;
    std::cout << "y = " << a.y << std::endl;
    std::cout << "z = " << a.z << std::endl;
    std::cout << "w = " << a.w << std::endl;
}