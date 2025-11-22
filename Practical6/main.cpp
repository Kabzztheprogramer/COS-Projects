#include <cstdio>
#include <iostream>

#include "rental.h"
using namespace std ;
int main() {
    //Happy Testing
    Fleet stack = Fleet(10,"fleet.txt");
    cout<< stack.fleetInfo() << endl;
    Fleet stack2 = Fleet(&stack);
    cout << "stack 2 : " << endl;
    cout<< stack2.fleetInfo();
    cout<< "Buses : " << stack2.getCurrentBuses() << endl;
    cout<< "Cars : " << stack2.getCurrentCars() << endl;
    cout<< "Trucks : " << stack2.getCurrentTrucks() << endl;
    cout<< "Total : " << stack2.getMaxsize() << endl;

    //adding to the stack2 fleet ;
    Car merc  = Car("UMK249",2004.50,120030.50,250);
    Truck merctruck  = Truck("UMK249",2004.50,120030.50,30.40);
    Bus mercBus = Bus("UMK249",2004.50,120030.50,23);
    stack2.addCar(&merc);
    stack2.addTruck(&merctruck);
    stack2.addBus(&mercBus);
    cout<< stack2.fleetInfo();

    cout<< "Buses : " << stack2.getCurrentBuses() << endl;
    cout<< "Cars : " << stack2.getCurrentCars() << endl;
    cout<< "Trucks : " << stack2.getCurrentTrucks() << endl;
    cout<< "Total : " << stack2.getMaxsize() << endl;
    
    cout << "Test the Rental class : " << endl ;
    
   Rental myLib = Rental(15, 30,"fleet.txt");
   cout<<"Current bookings : "<< myLib.getCurrentBookings() <<endl;
   cout<<"Max bookings : "<< myLib.getMaxBookings() <<endl;

   for(int i = 0 ; i < myLib.getCurrentBookings(); i++){
    cout << "Fleet number : " << i +1 <<endl;
    cout<< myLib.getBookings()[i]->fleetInfo();
   }

   myLib.newBooking(&stack2);

   for(int i = 0 ; i < myLib.getCurrentBookings(); i++){
    cout << "Fleet number : " << i +1 <<endl;
    cout<< myLib.getBookings()[i]->fleetInfo();
   }

   myLib.cancelBooking(1);

   for(int i = 0 ; i < myLib.getCurrentBookings(); i++){
    cout << "Fleet number : " << i +1 <<endl;
    cout<< myLib.getBookings()[i]->fleetInfo();
   }
   cout<<endl;
   cout<<myLib.bookingSummary();
   cout<< "Total cost : R" << myLib.calculateBookingCost(0)<<endl;
    


    return 0;
}