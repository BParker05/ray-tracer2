#include <iostream>
#include <vector>

#include "tuple.h"
#include "canvas.h"
#include "colour.h"
#include "environment.h"
#include "projectile.h"
#include "matrix.h"
#include "ray.h"
#include "intersection.h"
#include "material.h"
#include "pointLight.h"
#include "world.h"

int main(){

    World world = World();
    
    Ray ray = Ray(Point(0,0,-5), Vector(0,0,1));

    std::vector<Intersection> intersections = world.intersectWorld(ray);

    std::cout << intersections.size() << std::endl;
    std::cout << intersections[0].t << std::endl;
    std::cout << intersections[1].t << std::endl;
    std::cout << intersections[2].t << std::endl;
    std::cout << intersections[3].t << std::endl;

    return 0; 
}