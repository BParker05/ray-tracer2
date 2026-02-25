#include <iostream>

#include "tuple.h"
#include "canvas.h"
#include "colour.h"
#include "environment.h"
#include "projectile.h"

Projectile tick(Environment env, Projectile proj){
    proj.position = proj.position + proj.velocity;
    proj.velocity = proj.velocity + env.gravity + env.wind;
    return proj;
};

int main(){

    /*
    Canvas canva = Canvas(10,20);

    Projectile p = Projectile(Point(0,1,0),normalize(Vector(1,1,0)));
    Environment e = Environment(Vector(0,-0.1,0), Vector(-0.01,0,0));

    while(p.position.y > 0){
        std::cout << p.position.x << " " << p.position.y << " " << p.position.z << std::endl;
        p = tick(e,p);
    }
    */

    Canvas c = Canvas(5,3);
    Colour c1 = Colour(1.5, 0, 0);
    Colour c2 = Colour(0, 0.5, 0);
    Colour c3 = Colour(-0.5, 0, 1);

    c.writePixel(0,0,c1);
    c.writePixel(2,1,c2);
    c.writePixel(4,2,c3);

    c.writePPM();
    
}