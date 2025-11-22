#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream> 
 class item{

    private :
        std::string name;
        double price ;
        int stock ;
    public :
    item( std::string n, double p ,int s );
    ~item();
    std::string getName();
    double getPrice();
    int getStock();

 };

 #endif