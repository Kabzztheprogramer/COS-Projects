#include <cstdio>
#include <iostream>

#include "database.h"

using namespace std;

int main() {
    //Happy Testing
    Database<Person> Edatabase(10);
    Database<Stock> Sdatabase(10);
    Product  *P1 = new  Product("P1","0840947102",10,"Cake",10);
    Employee *E1 = new  Employee("E1","0840947102",10,"jebzo",10);
    Customer *C1 = new  Customer("C1","0840987102",10,4);
    Product  *P2 = new  Product("P2","0841447102",11,"biscuit",10);
    
    Edatabase.add(E1);
    Edatabase.add(C1);
    Sdatabase.add(P1);
    Sdatabase.add(P2);
    cout<<"Database"<<endl<<Edatabase.view();
    
    if(Edatabase.updateAll(1,500) ){

        cout<<"Updated Database :"<<endl;
        cout<<"Database"<<endl<<Edatabase.view();

    }else {
        cout<<"Not updated Database :"<<endl;
        cout<<"Database"<<endl<<Edatabase.view();
    }

     
    if(Edatabase.updateAll(2,500) ){

        cout<<"Updated Database :"<<endl;
        cout<<"Database"<<endl<<Edatabase.view();

    }else {
        cout<<"Not updated Database :"<<endl;
        cout<<"Database"<<endl<<Edatabase.view();
    }

     if(Edatabase.updateOne("r5",1,10) ){

        cout<<"Updated Database :"<<endl;
        cout<<"Database"<<endl<<Edatabase.view();

    }else {
        cout<<"Not updated Database :"<<endl;
    }

    if(Sdatabase.updateOne("P1",1,10) ){

        cout<<"Updated Database :"<<endl;
        cout<<"Database"<<endl<<Sdatabase.view();

    }else {
        cout<<"Not updated Database :"<<endl;
    }

    
    if(Sdatabase.updateOne("P3",1,10) ){

        cout<<"Updated Database :"<<endl;
        cout<<"Database"<<endl<<Sdatabase.view();

    }else {
        cout<<"Not updated Database :"<<endl;
    }

     if(Sdatabase.updateAll(2,10) ){

        cout<<"Updated Database :"<<endl;
        cout<<"Database"<<endl<<Sdatabase.view();

    }else {
        cout<<"Not updated Database :"<<endl;
    }


    return 0;
}