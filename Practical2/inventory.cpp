
#include "inventory.h"
#include "item.h"
#include <iostream> 
#include <fstream> 
#include <sstream>
#include<string>


//inventory Func

inventory::inventory(int c , std::string path)
: capacity(c)
{
    shelfSizes = NULL ;
    shelves = NULL;
    numShelves = 0 ;

    items =  new item*[capacity] ;
    count = 0 ;
    int pos = 0;
    //assign the textfile to myfile and creating a var for a line
    std:: ifstream my_file(path.c_str());
    std::string str ;
    
    // variables of items 
        std::string name;
        double price ;
        int stock ;

    // creating stringstream converts between the different data types

    
    //std::stringstream strtofloat;

    //reading the textfile and creating the items to put in the items array
    while( getline(my_file , str) && count < capacity)
    {
        //resting the items Var
        
        pos = 0;
        name = "";
        price = 0;
        stock = 0;

        //setting items vars 
        while (str.find("#") < str.length() && not(str.find("#") <0))
        {
            ++pos;
            switch(pos)
            {
                case 1 :
                    name = str.substr(0,str.find("#"));
                    break;
                case 2 : 
                    std::stringstream strtofloat;
                    strtofloat << str.substr(0,str.find("#"));
                    strtofloat >> price ;
                    break;
            }
            str.erase(0,str.find("#")+1);
            
        }
        std::stringstream strtoint;
        strtoint << str;
        strtoint >> stock;
        //loading the array with the new elements 
        items[count] = new  item(name , price , stock) ;
        ++count ;
    }
    

 };

 inventory::~inventory(){
    if(items){
        for (int i = 0; i < count; i++) {
            if(items[i] != NULL)
                delete items[i];
        }
        delete[] items;
        items = NULL;   
    }

    if(shelves){
        for (int i = 0; i < numShelves; ++i) {
            for (int j = 0; j < shelfSizes[i]; ++j) {
                delete shelves[i][j];
            }
            delete[] shelves[i];
        }

        delete[] shelves;
        delete[] shelfSizes;
        shelfSizes = NULL;
        shelves = NULL;
    }
}



item** inventory::getItems()
{
    return items;
};
item*** inventory:: getShelves() 
{
    return shelves;
};
int inventory:: getCount()
{
    return count;
};
int inventory::getNumShelves()
{
    return numShelves;
};
int* inventory:: getShelfSizes()
{
    return shelfSizes;
};
bool inventory:: addItem(item* itemtoadd)
{
    if (count < capacity ){
        items[count] = new item(itemtoadd->getName(),itemtoadd->getPrice(),itemtoadd->getStock());
        
        if(shelves){
            bool badded = false ;
            for(int i = 0 ; i < numShelves; i++){
                 if(items[count]->getName() == shelves[i][0]->getName()){
                    badded = true ;
                    item **arr = new item *[shelfSizes[i]+1] ;
                    for(int j = 0 ; j < shelfSizes[i];j++){
                        arr[j] =  new item(shelves[i][j]->getName(),shelves[i][j]->getPrice(),shelves[i][j]->getStock());
                        delete shelves[i][j];
                    }
                    arr[shelfSizes[i]] = new item(itemtoadd->getName(),itemtoadd->getPrice(),itemtoadd->getStock());
                    ++shelfSizes[i];
                    delete [] shelves[i];
                    shelves[i] = NULL;
                    shelves[i] = arr;
                 }
            }

        if (badded== false){
            item ***newShelf = new item **[numShelves+1];
            int *newShelfsize = new int [numShelves+1];
            for ( int i = 0; i < numShelves; i++){
                    newShelf[i] = new item *[shelfSizes[i]];
                    newShelfsize[i] = shelfSizes[i];
                    for (int j = 0 ; j < shelfSizes[i] ; ++j){
                        newShelf[i][j] = new item (shelves[i][j]->getName(),shelves[i][j]->getPrice(),shelves[i][j]->getStock() );
                        delete shelves[i][j];
                    }
                    delete [] shelves[i];
        }
            delete shelves;
            delete [] shelfSizes;

            newShelf[numShelves] = new  item *[1];
            newShelfsize[numShelves] = 1;
            shelfSizes = newShelfsize;
            newShelf[numShelves][0] = new item(itemtoadd->getName(),itemtoadd->getPrice(),itemtoadd->getStock());
            shelves= newShelf;
            ++numShelves;
        }
        
    }
    
    ++count ;
    return true ;
}else {
    return false ;
    }
};
bool inventory:: removeItem(int index)
{   if( items && index < count && index >= 0){

   if(shelves != NULL){
        int newindex = 0;
        for (int i  = 0 ; i < numShelves; i++){
            if(items[index]->getName() == shelves[i][0]->getName()){
                item **arr = new item *[shelfSizes[i]-1] ;
                for(int j = 0 ; j < shelfSizes[i];j++){
                    if(items[index]->getStock()!=shelves[i][j]->getStock() || items[index]->getPrice()!=shelves[i][j]->getPrice()){
                        arr[newindex] = shelves[i][j];
                        ++newindex;
                    }
                }
                --shelfSizes[i] ;
                 delete [] shelves[i];
                 shelves[i] = NULL;
                if(shelfSizes[i]==0){
                    --numShelves;
                    item**arrReplace;
                    for (int x = i ; x < numShelves ; x++)
                    { 
                        arrReplace = new item*[shelfSizes[x+1]];
                        for (int y = 0 ; y < shelfSizes[x+1];y++){
                            arrReplace[y] = shelves[x+1][y];
                            
                        }
                        delete [] shelves[x+1];
                        shelves[x]=arrReplace;
                        shelfSizes[x] = shelfSizes[x+1];
                    }
                shelves[numShelves+1]== NULL;
                shelfSizes[numShelves+1] == 0;

                }else{
                shelves[i] = arr;
                }
            }
            }
        }
    delete  items[index];
    --count;
    for (int i = index ; i < count ; i++){
            items[i] = items[i+1];
            items[i+1] = NULL;
        }
        items[count]= NULL;
    return true;   }

return false;
}
void inventory::stockShelves()
{
    std::string arrNames[count];
    int numcol = 0;
    //adding the names to the name array 
    for (int i = 0; i < count; i++){
        arrNames[i] = items[i]->getName();
    }
    //Finding the number of  rows
     for (int i = 0; i < count; i++){
        if (arrNames[i]!= ""){
            ++numShelves;
            for (int j = i+1 ;  j < count ; j++ ){
                if (arrNames[i] == arrNames[j]){
                    arrNames[j] = ""; 
                }
            }
        }
    }
    //Finding the number of cols 
    int irow = 0;
    std::string arrRowNames[numShelves];
    shelfSizes = new int [numShelves];
    for (int i = 0; i < count; i++){
        if (arrNames[i]!= ""){
            shelfSizes[irow] = 0;
            arrRowNames[irow] = arrNames[i] ;
            for (int j = 0 ;  j < count ; j++ ){
                if (arrNames[i] == items[j]->getName()){
                    ++shelfSizes[irow];
                    }
            }
            ++irow;
        }
    }

    shelves = new item **[numShelves];
    int col= 0;
    for (int i =0; i < numShelves ; i++){
        col = 0;
        shelves[i] = new item *[shelfSizes[i]];
        for (int j = 0 ; j < count ; ++j){
            if(arrRowNames[i] == items[j]->getName()){
                shelves[i][col] = new item (items[j]->getName(), items[j]->getPrice(), items[j]->getStock());
                ++col;
            }
        }
    }
};

std::string inventory::generateReport(){
    std::string Report ;
    int TotalStock = 0;
    double AveragePrice = 0;
    double Minprice = 0;
    double Maxprice = 0;

    std::string sTotalStock ;
    std::string sAveragePrice ;
    std::string sMinprice ;
    std::string sMaxprice ;
    std::string sShelf ;

     for (int i = 0 ; i < numShelves ; i++){
        if(shelves){
            Maxprice = shelves[i][0]->getPrice();
            Minprice =shelves[i][0]->getPrice();
            TotalStock = 0;
            AveragePrice = 0;
            for (int j = 0; j < shelfSizes[i] ; j++){
                if ( Maxprice < shelves[i][j]->getPrice()){
                    Maxprice = shelves[i][j]->getPrice();
                };

                if (Minprice > shelves[i][j]->getPrice()){
                    Minprice = shelves[i][j]->getPrice();
                }
                TotalStock += shelves[i][j]->getStock();
                AveragePrice += shelves[i][j]->getPrice();
            }
            AveragePrice = AveragePrice/(double) shelfSizes[i];
            std::stringstream inttostr1;
             inttostr1<< i ;
             inttostr1 >>sShelf;
            std::stringstream inttostr2;
             inttostr2<<TotalStock ;
             inttostr2>>sTotalStock;
            std::stringstream floattostr1;
             floattostr1<< AveragePrice ;
             floattostr1>> sAveragePrice;
            std::stringstream floattostr2;
             floattostr2<< Maxprice ;
             floattostr2>> sMaxprice;
            std::stringstream floattostr3;
             floattostr3<< Minprice ;
             floattostr3>> sMinprice;

            Report += "Shelf " + sShelf + ": Item: " + shelves[i][0]->getName() + " Total Stock: "   +  sTotalStock + " Average Price: "+
            sAveragePrice + " Min Price: "+ sMinprice +" Max Price: " + sMaxprice + '\n';      
        
        }
    }

    return Report;
};
