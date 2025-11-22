#include "colour.h"
#include <iostream>
#include <sstream>
#include <string>

Colour:: Colour(int red , int green , int blue ){
    if(red < 255){
        this -> red = red;
    }else{
        this ->red = 255;
    }
    
    if(blue < 255){
        this->blue = blue;
    }else{
        this->blue = 255;
    }

    if(green<255){
        this -> green = green;
    }else{
        this -> green = 255;
    }
    
    
 };
Colour:: ~Colour(){
};
int  Colour:: getRed(){
    return red;
};
int  Colour:: getGreen(){
    return green;
};
int  Colour::getBlue(){
    return blue;
};
Colour Colour::operator+(const Colour& other){
    
    int newRed =(this-> red + other.red)/2;
    int newGreen =(this-> green + other.green)/2;
    int newBlue =(this-> blue + other.blue)/2;
    Colour newCC = Colour(newRed,newGreen,newBlue);
    return newCC;
};
Colour Colour::operator-(const Colour& other){

    int newRed = abs(this-> red - other.red)/2;
    int newGreen = abs(this-> green - other.green)/2;
    int newBlue = abs(this-> blue - other.blue)/2;
    Colour newCC = Colour(newRed,newGreen,newBlue);
    return newCC;

};
Colour& Colour::operator+=(const Colour& other){

    if(red + (this-> red + other.red)/2 < 255){
        this->red = red + (this-> red + other.red)/2;
    }else{
        red = 255;
    }
    
    if ( green+(this-> green + other.green)/2 < 255)
    {
         this->green = green + (this-> green + other.green)/2;
    }else{
        green = 255;
    }
    
    if(blue + (this-> blue + other.blue)/2 < 255){

        this->blue = blue + (this-> blue + other.blue)/2;
    }else{
        blue = 255;
    }
    

    return *this;

};
Colour&  Colour::operator-=(const Colour& other){

    if(abs(red - ((this-> red - other.red)/2) )< 255){
        red = abs(red - ((this-> red - other.red)/2) );
    }else{
        red=255;
    }
    if(abs(green -( (this-> green - other.green)/2)) < 255){
         green = abs(green -( (this-> green - other.green)/2));
    }else{
        green = 255;
    }
   if(abs(blue-((this-> blue - other.blue)/2)) < 255){
        blue = abs(blue-((this-> blue - other.blue)/2));
   }else{
        blue = 255;
   }
    return *this;
};
Colour  Colour:: operator*(double ratio){
    
    Colour newColour = Colour(0,0,0);
    if(red*ratio < 255){
       newColour.red= red*ratio ;
    }else{
        newColour.red= 255;
    }

    if(blue*ratio < 255){
        newColour.blue= blue*ratio ;
    }else{
        newColour.blue = 255;
    }

    if(green*ratio < 255){
        newColour.green= green*ratio ;
    }else{
        newColour.green = 255;
    }   
    return newColour;
};
bool  Colour:: operator==(const Colour& rhs){
    if(this->red == rhs.red && this->green == rhs.green && this->blue == rhs.blue){
        return true ;
    }
    return false ;
};