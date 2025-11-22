#include "car.h"
#include <iostream>

Car::Car(std::string registration, double gasUsage,double mileage , int topSpeed):Vehicle(registration,gasUsage,mileage)
{
    this->topSpeed = topSpeed;
}

Car::~Car()
{
}

int Car::getTopSpeed() const
{
    if(topSpeed < 0 ){
        return 0 ;
    }
    return topSpeed;
}

void Car::calculateCost()
{
   double costMileage ;
   double baseCost ;
   double multiplier = 500;
   double decay = 0.015;
   double costGas;

   if( topSpeed > 150 && topSpeed <= 200){
        baseCost = 12000;
   }else if(topSpeed <= 150){
        baseCost = 6000;
   }else{
        baseCost = 20000;
   }

   costMileage = baseCost*exp(-getMileage()*decay);
   if(getGasUsage() > 0){
        costGas = std::max(costMileage,baseCost)+(multiplier/ getGasUsage());
        setCost(costGas) ;
   }else{
        costGas = 0 ;
        setCost(-1.0);
   }
   
   
}

std::string Car::vehicleInfo()
{
    std::stringstream info;
    info << "R: " << getRegistration()<<" G: "<< getGasUsage() <<" M: "<< getMileage() << " S: " << topSpeed ;
    return info.str();
}
