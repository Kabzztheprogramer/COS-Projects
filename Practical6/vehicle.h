#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <cmath>
#include <sstream>


class Vehicle
{
    private : 

    std::string registration;  
    double gasUsage;           
    double mileage;           
    double cost;  

    public :

    Vehicle( std::string registration ,double gasUsage , double mileage);
    ~Vehicle();
    std::string getRegistration() const ;
    double getGasUsage() const ;
    double getMileage() const ;
    double getCost() const;
    void setCost(double cost);
    



};

#endif