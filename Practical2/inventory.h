#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream> 
#include "item.h"

 class inventory{
    private :
        int capacity;
        int count;
        int* shelfSizes;
        int numShelves;
        item** items;
        item*** shelves;
    public :
    
    inventory(int c , std::string path);
    ~inventory();
    item** getItems() ;
    item*** getShelves() ;
    int getCount();
    int getNumShelves();
    int* getShelfSizes();
    bool addItem(item* itemtoadd);
    bool removeItem(int index);
    void stockShelves();
    std::string generateReport();
 };


#endif