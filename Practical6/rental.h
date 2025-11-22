#ifndef RENTAL_H
#define RENTAL_H

#include <string>
#include "fleet.h"
#include <fstream>
#include <sstream>
#include <iostream>

class Rental{
private:
    int maxBookings;     
    int currBookings;   
    Fleet** bookings;   
public:
   
    Rental(int maxBookings, int bookingSize, std::string path);
    ~Rental();
    Fleet** getBookings()  const  ;
    int getCurrentBookings() const  ;
    int getMaxBookings() const ;
    bool newBooking(Fleet* bookingFleet);
    bool cancelBooking(int index);
    std::string bookingSummary() ;
    double calculateBookingCost(int index) ;
};

#endif
