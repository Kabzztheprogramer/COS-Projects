#include "mixer.h"


Mixer::Mixer(int red,int green,int blue){
    for(int i = 0 ; i < 10 ; i++){
        if( i % 2 == 0 ){
            palette[i]= Colour(255,255,255);
        }else{
            palette[i] = Colour(red,green,blue);
        }
    }
};
Mixer::~Mixer(){
};
Colour* Mixer:: getPalette(){
    return palette;
};
bool Mixer::addColour(int index ,const Colour& colourToAdd ){
    if(index < 10 && index>= 0){
        if(palette[index].getRed() == 255 && palette[index].getGreen() == 255 && palette[index].getBlue() == 255){
            palette[index] = colourToAdd;
        }else {
            palette[index] += colourToAdd;
        }
        return true;
    }
    return false;
} ;
Colour Mixer::getColour(int index){
if(index < 10 && index>= 0){
    return palette[index];
}else{
    return Colour(-1,-1,-1);
}
    
    
};
std::string Mixer::displayPalette(){
    std:: string Result ;
    std:: stringstream out;
    for(int i = 0 ; i <10 ;i++){
        out << "Colour " << i << ": Red: "<< palette[i].getRed() << " Green: " << palette[i].getGreen() << " Blue: " << palette[i].getBlue() << "\n";
    }
    return out.str();
};

bool Mixer:: mixTwo(int colour1 ,int colour2){
    if (colour1 >= 10 || colour1 < 0 || colour2 < 0  || colour1 >= 10 ){

        return false ;

    }else{
        palette[colour1] +=  palette[colour2];
        palette[colour2] -=  palette[colour1] ;
    
        return true ;
    }
    
};

bool Mixer:: mixRatio(int colour,double ratio){
    if (colour < 10 && colour >= 0){

        palette[colour] = palette[colour]*ratio;

        return true;

    }else{

        return false;
    }
};

Mixer& Mixer:: operator+=(const Colour coloursToMix[10]){
    for(int i =0; i<10; i++){
        this->palette[i] += coloursToMix[i];
    }
    return *this;
};
Mixer& Mixer::operator+(const Mixer other){
    for(int i = 0 ; i < 10 ; i++){
        
        if( i % 2 == 0 ){
            this->palette[i] += other.palette[i];
        }else{
            this->palette[i] -= other.palette[i];
        }
    }
    
    return *this;
};
Mixer& Mixer::operator*=(double ratio){
    for(int i = 0 ; i < 10 ; i++){
        palette[i] = palette[i]*ratio;
    }
    return *this;
};   