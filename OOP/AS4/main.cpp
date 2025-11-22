#include <iostream>

#include "DataStructure.h"
#include "Array.h"
#include "LinkedList.h"
#include "Exceptions.h"

using namespace std;

int main(){
    try{
        DataStructure<int, false>* ds1 = new LinkedList<int, false>();
        DataStructure<int, true>* ds2 = new Array<int, true>();
        delete ds1;
        delete ds2;
    }catch(IndexOutOfBoundsException* e){
        e->getMessage();
    }
}
