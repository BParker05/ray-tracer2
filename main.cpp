#include <iostream>

#include "vector.h"
#include "point.h"

int main(){
    Vector a(4.3,-4.2,3.1);
    std::cout << "x = " << a.x << std::endl;
    std::cout << "y = " << a.y << std::endl;
    std::cout << "z = " << a.z << std::endl;
    std::cout << "w = " << a.w << std::endl;

    Point b(4.3,-4.2,3.1);
    std::cout << "x = " << b.x << std::endl;
    std::cout << "y = " << b.y << std::endl;
    std::cout << "z = " << b.z << std::endl;
    std::cout << "w = " << b.w << std::endl;
}