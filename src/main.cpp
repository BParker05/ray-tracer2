#include <iostream>
#include <vector>

#include "tuple.h"
#include "canvas.h"
#include "colour.h"
#include "environment.h"
#include "projectile.h"
#include "matrix.h"

Projectile tick(Environment env, Projectile proj){
    proj.position = proj.position + proj.velocity;
    proj.velocity = proj.velocity + env.gravity + env.wind;
    return proj;
};



int main(){

    std::vector<std::vector<float>> z = {{1,2,3,4},
                                        {2,4,4,2},
                                        {8,6,4,1},
                                        {0,0,0,1}};

    Matrix a = Matrix(z);

    Tuple b = Tuple(1,2,3,1);

    Tuple c = a*b;

    std::cout<< c.x << " " << c.y << " " << c.z << " " << c.w << std::endl;
    
    return 0; 
}