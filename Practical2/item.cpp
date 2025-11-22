

#include "item.h"
#include <iostream> 
#include <fstream> 
#include <sstream>
#include<string>

item::item( std::string n , double p ,int s )
 : name(n) , price(p) , stock(s) {  
 }

item::~item(){ };

std::string item::getName(){
    return name;
}
double item::getPrice(){
    return price;
} 
int  item::getStock() {
    return stock;
}