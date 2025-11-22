#include "truck.h"
#include <iostream>


Truck::Truck(std::string registration, double gasUsage, double mileage, double carry):Vehicle(registration,gasUsage,mileage)
{
    this->carry = carry;
}

Truck::~Truck()
{
}

double Truck::getCarry() const
{
    return carry;
}

void Truck::calculateCost()
{
     double costMileage ;
   double baseCost ;
   double multiplier = 10000;
   double decay = 0.010;
   double costGas;

   if( carry > 2 && carry <= 5 ){
        baseCost = 52000;
   }else if(carry <= 2 ){
        baseCost = 35000 ;
   }else{
        baseCost = 78000;
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

std::string Truck::vehicleInfo() 
{
    std::stringstream info;
    info << "R: " << getRegistration()<<" G: "<< getGasUsage() <<" M: "<< getMileage() << " C: " << carry ;
    return info.str();
}

