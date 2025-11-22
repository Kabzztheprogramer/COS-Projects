#include <cstdio>
#include <iostream>

#include "inventory.h"
#include "item.h"

using namespace std;

int main() {
    // TODO: Test your code here
    inventory inventory1 = inventory(11,"items.txt");
    inventory1.stockShelves();
    cout<< inventory1.generateReport();
    cout << endl;


    //adding item;
    item *IT1 =  new item("Chips", 42.69 , 20.00);
    inventory1.addItem(IT1);
    cout<< inventory1.generateReport();
     cout << endl;

    //removing added item
    if(inventory1.removeItem(7)){
        cout<< inventory1.generateReport();
        cout << endl;
    }

    
        
        return 0;
    };