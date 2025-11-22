#ifndef MIXER_H
#define MIXER_H

#include <string>
#include <sstream>
#include "colour.h"

class Mixer
{
private:
   Colour palette[10];
public:
    Mixer(int red,int green,int blue);;
    ~Mixer();
    Colour* getPalette();
    bool addColour(int index ,const Colour& colourToAdd ) ;
    Colour getColour(int index);
    std::string displayPalette();
    bool mixTwo(int colour1 ,int colour2);
    bool mixRatio(int colour,double ratio);
    Mixer& operator+=(const Colour coloursToMix[10]);
    Mixer& operator+(const Mixer other);
    Mixer& operator*=(double ratio);   
};

#endif