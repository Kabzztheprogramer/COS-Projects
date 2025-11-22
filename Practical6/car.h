#ifndef CAR_H
#define CAR_H

#include <string>
#include <cmath>
#include <sstream>
#include <fstream>

#include "vehicle.h"

class Car : public Vehicle
{
    private :
    int topSpeed ;

    public:

    Car(std::string registration ,double gasUsage,double mileage ,int topSpeed);
    ~Car();
    int getTopSpeed() const;
    void calculateCost();
    std::string vehicleInfo();

};

#endif
