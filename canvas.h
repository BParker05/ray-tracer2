#pragma once

#include <vector>
#include "colour.h"

class Canvas{
    public:
        int width;
        int height;
        std::vector<std::vector<Colour>> pixels;

        Canvas() = default;

        Canvas(int width, int height){
            this->width = width;
            this->height = height;

            for (int i = 0; i < width; i++){
                this->pixels.push_back(std::vector<Colour>());
                for (int j = 0; j < height; j++){
                    this->pixels[i].push_back(Colour(0,0,0));
                }
            }
        }

        void writePixel(int x, int y, Colour c){
            this->pixels[x-1][y-1] = c;
        }

        Colour pixelAt(int x,int y){
            return this->pixels[x-1][y-1];
        }
};