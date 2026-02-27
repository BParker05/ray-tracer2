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

    Projectile p = Projectile(Point(0,1,0),normalize(Vector(1,1.8,0))*6.625);
    Environment e = Environment(Vector(0,-0.1,1),Vector(-0.01,0,0));
    Canvas c = Canvas (450,225);

    while(p.position.x <= c.width && p.position.y <= c.height && p.position.x >= 0 && p.position.y >= 0){
        c.writePixel(p.position.x,c.height - p.position.y,Colour(1,0,0));
        p = tick(e,p);
    }
    c.writePPM();
    
}