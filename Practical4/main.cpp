#include <iostream>
#include "mixer.h"

using namespace std;

void print(Colour& Ctype , string Name){
    cout <<Name << " is made by Red : "<< Ctype.getRed() << " Green : " << Ctype.getGreen() << " Blue :  " << Ctype.getBlue() << endl;
}
int main() {
    //Test your code here
    Colour purple = Colour(160,32,240);
    Colour pink = Colour(255,192,203);
    print(purple,"Purple");
    Colour lightPlum = purple + pink ;
    print(lightPlum ,"Light Plum");
    Colour purple2 = purple;
    print(purple2,"New purple") ;
    Colour NC = lightPlum - purple2;
    cout<<"New colour made by lightPlum - purple = "<<endl;
    print(NC,"New colour");
    cout<<"New colour * the ratio 10 "<<endl;
    NC = NC*10;
    print(NC ,"New colour * 10");
    NC += purple;
    print(NC , "New colour += purple");
    NC -= pink;
    print(NC , "New colour -= pink");
    bool equal = purple == purple2;
    cout <<"pink== pink2 : " << equal << endl ;
    //Testing the Mixer

    Mixer M1 = Mixer(160,32,240);
    Mixer M2 = Mixer(150,75,0);
    cout<<"Palette colours :"<<endl;
    
    for(int i =0 ; i<10;i++){
        cout<< i ;
        print(M1.getPalette()[i]," Colour ");
    }

    if(M1.addColour(0,pink) == 1){
    cout<<M1.addColour(0,pink)<<endl;
    print(M1.getPalette()[0],"Add Colour in the mixer :");
    cout<<M1.addColour(1,pink)<<endl;
    print(M1.getPalette()[1],"Add Colour in the mixer :");
    }

    //Printing a colour by it's index;
    Colour IndexColour = M1.getColour(1);
    print(IndexColour,"Colour 1 in the Palette");

    //Print using the member function
    cout<<M1.displayPalette();

    //mixTwo test;
    M1.mixTwo(3,4);
    cout<<endl;
    cout<<M1.displayPalette();

    //mix Ratio test
    cout<<endl;
    M1.mixRatio(4,9.5);
    cout<<M1.displayPalette();
    

    // Mixer operator+= test
    cout<<"Mixer operator+= test : "<<endl;
    M1 += M2.getPalette();
    cout<<M1.displayPalette();

    //Mixer operator+ test
    cout<<"Mixer operator+ test : "<<endl;
    M1 = M1 + M2;
    cout<<M1.displayPalette();

    //Mixer operator*= test
    cout<<"Mixer operator*= test:" <<endl;
    M2 *= 2.3;
    cout<<M1.displayPalette();
    return 0;


}