
#include "rental.h"

Rental::Rental(int maxBookings, int bookingSize, std::string path)
{
    std::ifstream myfile(path.c_str());
    if(!myfile.is_open() || maxBookings <= 0){

        this->maxBookings = 0;
        this->currBookings = 0 ;
        this->bookings = NULL ;

    }else{
        
        this->maxBookings = maxBookings;
        bookings = new Fleet *[maxBookings];
        this->currBookings =0;

        for(int i = 0 ; i < maxBookings ; i++){
            bookings[i] = NULL;
        }
        bookings[0] = new Fleet(bookingSize,path);
        ++currBookings;


    }
}

Rental::~Rental()
{
    if(bookings != NULL){
        
        for(int i = 0; i < currBookings ; i++){

            if(bookings[i] != NULL){
               delete bookings[i] ;
            }
            bookings[i] = NULL;    
        }
        delete [] bookings;
        
    }
        bookings = NULL;

    
}

Fleet** Rental::getBookings() const 
{
    return bookings ;
}

int Rental::getCurrentBookings() const 
{
    return currBookings;
}

int Rental::getMaxBookings() const
{
    return maxBookings;
}

bool Rental::newBooking(Fleet* bookingFleet)
{
    if(currBookings >= maxBookings || bookingFleet == NULL){
        return false;
    }else{  
    bookings[currBookings] = new Fleet (bookingFleet);
    ++currBookings;
    return true;
    }
    
}

bool Rental::cancelBooking(int index)
{
    if(index >= currBookings || index < 0 ){
        return false;
    }else{
        delete bookings[index] ;
        bookings[index] = NULL;
        --currBookings;
        for(int i  = index ; i < currBookings ; i++ ){
            bookings[i] = new Fleet (bookings[i+1] ) ;
            if(bookings[i+1] != NULL){
               delete bookings[i+1] ;
               bookings[i+1] = NULL ;
            }
        }
        return true;
    }
}

std::string Rental::bookingSummary() 
{
    std::string infomation;
    
    for (int i = 0; i < currBookings; i++) {
        std::stringstream ss;
        ss << "Booking: " << i 
           << " Cars: " << bookings[i]->getCurrentCars()
           << " Buses: " << bookings[i]->getCurrentBuses()
           << " Trucks: " << bookings[i]->getCurrentTrucks()
           << " Total Cost: " << calculateBookingCost(i);

        // Append the current booking info to the final summary
        infomation += ss.str() + '\n';
    }

    return infomation;
}

double Rental::calculateBookingCost(int index) 
{
    if (index >= currBookings || index < 0) {
        return -100; 
    }
    double Tcost = 0;

    // Calculate cost for cars
    for (int c = 0; c < bookings[index]->getCurrentCars(); c++) {
        bookings[index]->getCars()[c]->calculateCost();
        Tcost += bookings[index]->getCars()[c]->getCost() ;
    }

    // Calculate cost for buses
    for (int b = 0; b < bookings[index]->getCurrentBuses(); b++) {
        bookings[index]->getBuses()[b]->calculateCost();
        Tcost += bookings[index]->getBuses()[b]->getCost() ;
    }

    // Calculate cost for trucks
    for (int t = 0; t < bookings[index]->getCurrentTrucks(); t++) {
        bookings[index]->getTrucks()[t]->calculateCost();
        Tcost += bookings[index]->getTrucks()[t]->getCost() ;
    }
    
    return Tcost;


    
}
