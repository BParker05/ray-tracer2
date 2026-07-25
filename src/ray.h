#pragma once

#include <vector>

#include "tuple.h"
#include "sphere.h"
#include "intersection.h"

class Ray {
    public:
        Tuple origin;
        Tuple direction;

        Ray() = default;

        Ray(Tuple origin, Tuple direction){
            this->origin = origin;
            this->direction = direction;
        }

        Tuple position(float t){
            return this->origin + this->direction * t;

        }
};

Ray transform(Ray r, Matrix m){
    return Ray(m * r.origin, m * r.direction);
}

std::vector<Intersection> intersect(Ray ray, Sphere sphere){
    std::vector<Intersection> intersections;
    ray = transform(ray, sphere.transformation.inverse());

    Tuple sphereToRay = ray.origin - Point(0,0,0);

    float a = dot(ray.direction, ray.direction);
    float b = 2 * dot(ray.direction, sphereToRay);
    float c = dot(sphereToRay, sphereToRay) - 1;

    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0){
        return intersections;
    }

    intersections.push_back(Intersection((-b - std::sqrt(discriminant)) / (2 * a), sphere));
    intersections.push_back(Intersection((-b + std::sqrt(discriminant)) / (2 * a), sphere));

    return intersections;
}

Intersection hit(std::vector<Intersection> xs){
	Intersection tmp = Intersection(-1);

	for (int i = 0; i < xs.size(); i++){
		if (xs[i].t < 0) {
			continue;
		} else if (tmp.t < 0) {
			tmp = xs[i];
		} else if (xs[i].t < tmp.t) {
			tmp = xs[i];
		}
	}

	if (tmp.t < 0){
		return NULL;
	}

	return tmp;
}

Tuple reflect(Tuple in, Tuple normal){
    return in - normal * 2 * dot(in, normal);
}