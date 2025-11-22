#include "Term.h"
#include  "Polynomial.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std ;

int main(){
    //testing the Term file without the Polynomial.cpp  file
    char  letter[3]  =  { 'x' , 'y' , 'z'};
    int  degree[3] = {2,3,4};
    Term T1 = Term(3,3,letter,degree);
    // cout<<T1.toString() ;
    // T1.removeVariable('x');
    // cout <<endl;
    // cout<<T1.toString() ;
    // cout<<endl;
    // T1.addVariable('x',2);
    // cout<<T1.toString() ;
    // cout<<endl;
    // T1.addVariable('z',2);
    // cout<<T1.toString() ;
    // cout<<endl;
    // cout<<T1.getVarIndex('z')<<endl;
    Term  T2 = Term(2,2,letter,degree);
    T2 = T1*T2;
    cout<<endl;
    cout<<T2.toString() ;
    
    return 0 ;
}