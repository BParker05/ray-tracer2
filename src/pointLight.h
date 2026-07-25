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

Colour lighting(Material material, PointLight light, Tuple point, Tuple eyeVector, Tuple normalVector){
    Colour diffuse = Colour(0,0,0);
    Colour specular = Colour(0,0,0);
    Colour ambient = Colour(0,0,0);
    Colour effectiveColour = material.colour * light.intensity;

    Tuple lightVector = normalize(light.position - point);

    ambient = effectiveColour * material.ambient;

    float lightDotNormal = dot(lightVector, normalVector);

    if (lightDotNormal < 0){

        Colour diffuse = Colour(0,0,0);
        Colour specular = Colour(0,0,0);
    } else {

        diffuse = effectiveColour * material.diffuse * lightDotNormal;

        Tuple reflectVector = reflect(-lightVector, normalVector);
        float reflectDotEye = dot(reflectVector, eyeVector);

        if (reflectDotEye <= 0){
            specular = Colour(0,0,0);
        } else {
            float factor = std::pow(reflectDotEye, material.shininess);
            specular = light.intensity * material.specular * factor;
        }
    }

    return ambient + diffuse + specular;
}