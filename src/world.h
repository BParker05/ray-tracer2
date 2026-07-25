#pragma once

#include "pointLight.h"
#include "sphere.h"

class World{
    public:
        PointLight light;
        Sphere sphere1;
        Sphere sphere2;

        World(){
            this->light = PointLight(Point(-10,10,-10), Colour(1,1,1));
            this->sphere1 = Sphere();
            this->sphere1.material.colour = Colour(0.8,1.0,0.6);
            this->sphere1.material.diffuse = 0.7;
            this->sphere1.material.specular = 0.2;
            this->sphere2 = Sphere();
            this->sphere2.setTransform(scaling(0.5,0.5,0.5));
        }

        std::vector<Intersection> intersectWorld(Ray ray){
            std::vector<Intersection> worldIntersections = intersect(ray, sphere2);
            worldIntersections.push_back(intersect(ray,sphere1)[0]);
            worldIntersections.push_back(intersect(ray,sphere1)[1]);

            return worldIntersections;
        };

};