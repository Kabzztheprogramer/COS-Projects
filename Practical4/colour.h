#ifndef COLOUR_H
#define COLOUR_H

#include <iostream>
#include <cmath>

class Colour
{
    private:
        int red ;
        int green;
        int blue;

    public:
    Colour(int red= 0 , int green = 0 , int blue = 0 );
    ~Colour();
    int getRed();
    int getGreen();
    int getBlue();
    Colour operator+(const Colour& other);
    Colour operator-(const Colour& other);
    Colour& operator+=(const Colour& other);
    Colour& operator-=(const Colour& other);
    Colour operator*(double ratio);
    bool operator==(const Colour& rhs);

};

#endif