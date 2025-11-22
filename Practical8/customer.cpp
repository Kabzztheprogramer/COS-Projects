
#include "customer.h"
#include <sstream>  

// Clone method
Customer* Customer::clone() const {
    return new Customer(*this);
}

// Constructor
Customer::Customer(std::string id, std::string contact, int age, int visits)
    : Person(id, contact, age), visits(visits), loyalty(false), discount(0.0) {
}


Customer::~Customer() {
}


bool Customer::getSpecialAttribute() {
    return this->loyalty;
}


double Customer::getSpecialAttribute1() {
    return this->discount;
}


int Customer::getSpecialAttribute2() {
    return this->visits;
}


void Customer::setSpecialAttribute(bool loyalty) {
    this->loyalty = loyalty;
}


void Customer::setSpecialAttribute(double discount) {
    this->discount = discount;
}


void Customer::setSpecialAttribute(int visits) {
    this->visits = visits;
}


std::string Customer::display() {
    std::stringstream  ss;
    ss << "ID: " << this->getId() << " | Contact: " << this->getAttribute1()
        << " | Age: " << this->getAttribute2() << " | Loyalty: " << loyalty
        << " Discount: " << this->discount << " | Visits: " << this->visits<<" |";
    return ss.str();
}
