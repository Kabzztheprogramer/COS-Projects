#include "fleet.h"
#include <fstream>

Fleet::Fleet(int size, std::string path)
{
    std::ifstream myfile(path.c_str());
    if(!myfile.is_open() || size < 0){
        //When the file does not exist or the max items are less than zero
        maxSize = 0 ;
        currCars = 0;
        currBuses = 0;
        currTrucks = 0;

        cars = NULL;
        buses = NULL;
        trucks = NULL;


    }else{

        maxSize = size ;
        //Initializing the array with its max size
        cars = new Car *[maxSize];
        buses = new Bus *[maxSize];
        trucks = new Truck *[maxSize];

        //Initialixing the amount of cars
        currCars = 0;
        currBuses = 0;
        currTrucks = 0;
        //Initializing the array items to null
        for(int i = 0 ; i < maxSize ; i++){

            cars[i] = NULL;
            buses[i] = NULL;
            trucks[i] = NULL;
            
        }

        // Initializing the array items to the different objects
        std::string str;
        while (getline(myfile,str))
        {
            std::istringstream stream(str);

            std::string type ,sRegistr ,sGU ,sML,sDerived;

            getline(stream , type , '#');
            getline(stream , sRegistr , '#');
            getline(stream , sGU , '#');
            getline(stream , sML , '#');
            getline(stream , sDerived , '#');

             if (sGU.find('.') == std::string::npos) {
                sGU += ".0"; 
            }
            std::stringstream ssGU(sGU);
            double DGU, DML;
            ssGU >> DGU;  
            if (sML.find('.') == std::string::npos) {
                sML += ".0"; 
            }
            std::stringstream ssML(sML); 
            ssML >> DML;  
            
            if(type == "Car"){
                if(currCars < maxSize){
                    int topSpeed;
                    std::stringstream ssDerived(sDerived); 
                    ssDerived >> topSpeed;
                    cars[currCars] = new Car(sRegistr,DGU,DML,topSpeed);
                    ++currCars;
                }
                
            }else if(type == "Truck"){
                
                if(currTrucks < maxSize){
                    
                    double carry;
                    if (sDerived.find('.') == std::string::npos) {
                        sDerived += ".0"; 
                    }
                    std::stringstream ssDerived(sDerived); 
                    ssDerived >> carry;
                    trucks[currTrucks] = new Truck(sRegistr,DGU,DML,carry);
                    ++currTrucks;
                }

            }else{
                if(currBuses < maxSize){
                    int seats;
                    std::stringstream ssDerived(sDerived); 
                    ssDerived >> seats;
                    buses[currBuses] = new Bus(sRegistr,DGU,DML,seats);
                    ++currBuses;
                }

            }

            
        }
        
        
    }
    myfile.close();
}

Fleet::Fleet(const Fleet *toCopy)
{
    if(toCopy->maxSize <= 0){
        //When the max items are less than zero in the copy constructor
        this->maxSize = 0 ;
        this->currCars = 0;
        this->currBuses = 0;
        this->currTrucks = 0;

        this->cars = NULL;
        this->buses = NULL;
        this->trucks = NULL;

    }else{
        
        maxSize = toCopy->maxSize;
        //Initializing the array with its max size
        this->cars = new Car *[maxSize];
        this->buses = new Bus *[maxSize];
        this->trucks = new Truck *[maxSize];

        //Initialixing the amount of vechicle

        this->currCars = toCopy->currCars;
        this->currBuses = toCopy->currBuses;
        this->currTrucks = toCopy->currTrucks;

        //Initializing the array items to null
        for(int i = 0 ; i < maxSize ; i++){

            cars[i] = NULL;
            buses[i] = NULL;
            trucks[i] = NULL;
            
        }

        for(int c = 0; c < currCars ; c++){
            if(toCopy->cars[c] != NULL){
                cars[c] = new Car (toCopy->cars[c]->getRegistration(),toCopy->cars[c]->getGasUsage(),toCopy->cars[c]->getMileage(),toCopy->cars[c]->getTopSpeed());
            }else{
                cars[c] = NULL;
            }
        }

        for(int b = 0; b < currBuses ; b++){
            if(toCopy->buses[b] != NULL){
                buses[b] = new Bus (toCopy->buses[b]->getRegistration(),toCopy->buses[b]->getGasUsage(),toCopy->buses[b]->getMileage(),toCopy->buses[b]->getSeats());
            }else{
                buses[b] = NULL;
            }
        }

        for(int t = 0; t < currTrucks ; t++){
            if(toCopy->trucks[t] != NULL){
                trucks[t] = new Truck (toCopy->trucks[t]->getRegistration(),toCopy->trucks[t]->getGasUsage(),toCopy->trucks[t]->getMileage(),toCopy->trucks[t]->getCarry());
            }else{
                trucks[t] = NULL;
            }
        }

    }
    
}

Fleet::~Fleet()
{
    
    for(int c = 0; c < currCars ; c++){

            if(cars[c] != NULL){
               delete cars[c] ;
            }
            cars[c] = NULL;    
        }

    for(int b = 0; b < currBuses ; b++){

        if(buses[b] != NULL){
            delete buses[b] ;
        }
        buses[b] = NULL;
    }

    for(int t = 0; t < currTrucks ; t++){

        if(trucks[t] != NULL){
            delete trucks[t] ;
        }
        trucks[t] = NULL;
        
    }

    delete [] cars;
    delete [] buses;
    delete [] trucks;
}

 Car **Fleet::getCars() const
{
    return cars  ;
}
 Bus ** Fleet::getBuses() const
{
    return buses  ;
}

 Truck **Fleet::getTrucks() const
{
    return trucks  ;
}

int Fleet::getCurrentCars() const
{
    if( currCars < 0){
        return 0;
    }
    return currCars;
}

int Fleet::getCurrentBuses() const
{
    if( currBuses < 0){
        return 0;
    }
    return currBuses;
}

int Fleet::getCurrentTrucks() const
{
    if( currTrucks < 0){
        return 0;
    }
    return currTrucks;
}

int Fleet::getMaxsize() const
{
    if( maxSize < 0){
        return 0;
    }
    return maxSize;
}

bool Fleet::addCar(const Car *carToAdd)
{
    if(currCars >= maxSize || carToAdd == NULL){
        return false;
    }else{  
    cars[currCars] = new Car (carToAdd->getRegistration(),carToAdd->getGasUsage(),carToAdd->getMileage(),carToAdd->getTopSpeed());
    ++currCars;
    return true;
    }
    
}

bool Fleet::addBus(const Bus *busToAdd)
{

     if(currBuses >= maxSize || busToAdd == NULL){
        return false;
    }else{  
    buses[currBuses] = new Bus (busToAdd->getRegistration(),busToAdd->getGasUsage(),busToAdd->getMileage(),busToAdd->getSeats());
    ++currBuses;
    return true;
    }
}

bool Fleet::addTruck(const Truck *truckToAdd)
{
    if(currTrucks >= maxSize || truckToAdd == NULL){
        return false;
    }else{  
    trucks[currTrucks] = new Truck (truckToAdd->getRegistration(),truckToAdd->getGasUsage(),truckToAdd->getMileage(),truckToAdd->getCarry());
    ++currTrucks;
    return true;
    }
}

std::string Fleet::fleetInfo()
{
    std::string info;
    info += "Cars:\n";
    for (int i = 0; i < currCars; ++i) {
        if (cars[i] != NULL) {
            std::stringstream infocars ;
            infocars<< "Registration: " <<cars[i]->getRegistration()<<" Mileage: "<< cars[i]->getMileage() <<" Top Speed: " << cars[i]->getTopSpeed() << '\n';
            info += infocars.str();
        }
        
    }

    info += "\nBuses:\n";
    for (int i = 0; i < currBuses; ++i) {
         if (buses[i] != NULL) {
            std::stringstream infobuses ;
            infobuses<< "Registration: " <<buses[i]->getRegistration()<<" Mileage: "<< buses[i]->getMileage() <<" Seats: " << buses[i]->getSeats() << '\n';
            info += infobuses.str();
        }
    }

    info += "\nTrucks:\n";
    for (int i = 0; i < currTrucks; ++i) {
         if (trucks[i] != NULL) {
            std::stringstream infotrucks ;
            infotrucks<< "Registration: " <<trucks[i]->getRegistration()<<" Mileage: "<< trucks[i]->getMileage() <<" Carry: " << trucks[i]->getCarry() << '\n';
            info += infotrucks.str();
        }
    }
    return info ;
}
