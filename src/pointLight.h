#pragma once

#include "tuple.h"
#include "colour.h"
#include "material.h"
#include "ray.h"

class PointLight {
    public:

        Tuple position;
        Colour intensity;

        PointLight() = default;

        PointLight(Tuple position, Colour intensity){
            this->position = position;
            this->intensity = intensity;
        }
};

Colour lighting(Material m, PointLight light, Tuple point, Tuple eyev, Tuple normalv){
    Colour diffuse = Colour(0,0,0);
    Colour specular = Colour(0,0,0);
    Colour ambient = Colour(0,0,0);
    Colour effectiveColour = m.c * light.intensity;

    Tuple lightv = normalize(light.position - point);

    ambient = effectiveColour * m.ambient;

    float lightDotNormal = dot(lightv, normalv);

    if (lightDotNormal < 0){

        Colour diffuse = Colour(0,0,0);
        Colour specular = Colour(0,0,0);
    } else {

        diffuse = effectiveColour * m.diffuse * lightDotNormal;

        Tuple reflectV = reflect(-lightv, normalv);
        float reflectDotEye = dot(reflectV, eyev);

        if (reflectDotEye <= 0){
            specular = Colour(0,0,0);
        } else {
            float factor = std::pow(reflectDotEye, m.shininess);
            specular = light.intensity * m.specular * factor;
        }
    }

    return ambient + diffuse + specular;
}