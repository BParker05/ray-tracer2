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

int main(){

    Tuple rayOrigin = Point(0,0,-5);
    float wallZ = 10;
    float wallSize = 7;
    float canvasPixels = 200;
    float pixelSize = wallSize / canvasPixels;
    float half = wallSize / 2;

    Canvas c = Canvas(canvasPixels, canvasPixels);
    Colour red = Colour(1,0,0);
    Sphere s = Sphere();
    s.m = Material();
    s.m.c = Colour(1,0.2,1);
    PointLight light = PointLight(Point(-10,10,-10), Colour(1,1,1));

    for (int i = 0; i < canvasPixels; i++){
        float worldY = half - pixelSize * i;

        for (int j = 0; j < canvasPixels; j++){
            float worldX = -half + pixelSize * j;

            Tuple position = Point(worldX, worldY, wallZ);
            Ray r = Ray(rayOrigin, normalize(position - rayOrigin));
            std::vector<Intersection> xs = intersect(r,s);

            if (xs.size() > 0){
                Tuple p = r.position(xs[0].t);
                Tuple normal = s.normalAt(p);
                Tuple eye = -r.direction;
                Colour pixelColour = lighting(xs[0].object.m, light, p, eye, normal);
                c.writePixel(j,i,pixelColour);
            } else {
                c.writePixel(j,i,Colour(0,0,0));
            }
        }
    }

    c.writePPM();

    return 0; 
}