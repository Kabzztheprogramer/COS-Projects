#include "stock.h"


Stock::Stock(std::string id, std::string supplier, int quantity)
    : id(id), supplier(supplier), quantity(quantity)
{
}

Stock::~Stock()
{

}


std::string Stock::getId()
{
    return this->id;
}

std::string Stock::getAttribute1()
{
    return this->supplier;
}


int Stock::getAttribute2()
{
    return this->quantity;
}


void Stock::setAttribute(std::string supplier)
{
    this->supplier = supplier;
}

void Stock::setAttribute(int quantity)
{
    this->quantity = quantity;
}



