#ifndef FLEET_H
#define FLEET_H

#include "car.h"
#include "bus.h"
#include "truck.h"
#include <fstream>
#include <sstream>
#include <iostream>

class Fleet
{
    private :
        int currCars ;
        int currBuses ;
        int currTrucks; 
        int maxSize ;

        Car **cars ; 
        Bus **buses;
        Truck **trucks ;
    public:
    
        Fleet(int size , std::string path);
        Fleet(const Fleet *toCopy);
        ~Fleet();
        Car** getCars() const;
        Bus** getBuses() const;
        Truck** getTrucks() const;
        int getCurrentCars() const;
        int getCurrentBuses() const;
        int getCurrentTrucks() const;
        int getMaxsize() const;
        bool addCar(const Car* carToAdd);
        bool addBus(const Bus* busToAdd);
        bool addTruck(const Truck* truckToAdd);
        std::string fleetInfo() ;

};

#endif

