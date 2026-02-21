#pragma once

class Colour{
    public:
        float red;
        float green;
        float blue;

        Colour() = default;

        Colour(float red, float green, float blue){
            this->red = red;
            this->green = green;
            this->blue = blue;
        }

        Colour operator+(Colour a){
            return Colour(this->red + a.red, this->green + a.green, this->blue + a.blue);
        }

        Colour operator-(Colour a){
            return Colour(this->red - a.red, this->green - a.green, this->blue - a.blue);
        }

        Colour operator-(){
            return Colour(this->red * -1, this->green * -1, this->blue * -1);
        }


        Colour operator*(Colour a){
            return Colour(this->red * a.red, this->green * a.green, this->blue * a.blue);
        }

        Colour operator*(float a){
            return Colour(this->red * a, this->green * a, this->blue * a);
        }

        Colour operator/(Colour a){
            return Colour(this->red / a.red, this->green / a.green, this->blue / a.blue);
        }

        Colour operator/(float a){
            return Colour(this->red / a, this->green / a, this->blue / a);
        }
};