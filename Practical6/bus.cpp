#include "bus.h"

Bus::Bus(std::string registration ,double gasUsage,double mileage,int seats):Vehicle(registration,gasUsage,mileage)
{
    this->seats = seats;
};

Bus::~Bus()
{
}

int Bus::getSeats() const
{
     if(seats < 0 ){
        return 0 ;
    }
    return seats;
}

void Bus::calculateCost()
{
    double costMileage ;
   double baseCost ;
   double multiplier = 1000;
   double decay = 0.025;
   double costGas;

   if( seats > 26 && seats <= 40 ){
        baseCost = 30000;
   }else if(seats <= 26 ){
        baseCost = 20000;
   }else{
        baseCost = 40000;
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

std::string Bus::vehicleInfo()
{
    std::stringstream info;
    info << "R: " << getRegistration()<<" G: "<< getGasUsage() <<" M: "<< getMileage() << " S: " << seats ;
    return info.str();
}
