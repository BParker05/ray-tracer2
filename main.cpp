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

    Canvas c = Canvas(10,20);
    Colour red = Colour(1,0,0);

    c.writePixel(2,3,red);
    std::cout << c.pixelAt(2,3).red << " " << c.pixelAt(2,3).green << " " << c.pixelAt(2,3).blue << std::endl;

    for (int i = 0; i < c.pixels.size(); i++) {
        for (int j = 0; j < c.pixels.at(i).size(); j++) {
            std::cout << c.pixels.at(j).at(i).red << " " << c.pixels.at(j).at(i).green << " " << c.pixels.at(j).at(i).blue << " " << "|" << " ";
        }
        std::cout << std::endl;
    }

    //std::cout << thing.red << " " << thing.green << " " << thing.blue << std::endl;
    
}