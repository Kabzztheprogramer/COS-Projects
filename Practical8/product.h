#ifndef PRODUCT_H
#define PRODUCT_H

#include "stock.h"

class Product : public Stock
{
private:
    std::string name;
    double price;
    int sold;
public:
    Product(std::string id, std::string supplier, int quantity, std::string name, double price);
    ~Product();

    std::string getName();
    double getSpecialAttribute1();
    int getSpecialAttribute2();

    void setSpecialAttribute(double price);
    void setSpecialAttribute(int sold);

    std::string display();
    Product* clone() const;
};



#endif