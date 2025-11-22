#include "product.h"
#include <sstream> 


Product* Product::clone() const {
    return new Product(*this);
}


Product::Product(std::string id, std::string supplier, int quantity, std::string name, double price)
    : Stock(id, supplier, quantity), name(name), price(price), sold(0) {
}


Product::~Product() {
}

std::string Product::getName() {
    return this->name;
}

double Product::getSpecialAttribute1() {
    return this->price;
}

int Product::getSpecialAttribute2() {
    return this->sold;
}


void Product::setSpecialAttribute(double price) {
    this->price = price;
}


void Product::setSpecialAttribute(int sold) {
    this->sold = sold;
}


std::string Product::display() {
    std::stringstream ss;
    ss << "ID: " << this->getId() << " | Supplier: " << this->getAttribute1()
        << " | Quantity: " << this->getAttribute2() << " | Name: " << this->name
        << " | Price: " << this->price << " | Units Sold: " << this->sold << " |";
    return ss.str();
}
