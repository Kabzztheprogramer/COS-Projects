#ifndef STOCK_H
#define STOCK_H
#include<string>
#include <sstream>


class Stock
{
private:
     std::string id;
    std::string supplier;
    int quantity;
public:
Stock(std::string id, std::string supplier, int quantity);
    virtual ~Stock();

    std::string getId();
    std::string getAttribute1();
    int getAttribute2();

    void setAttribute(std::string supplier);
    void setAttribute(int quantity);

    // Pure virtual functions
    virtual double getSpecialAttribute1() = 0;
    virtual int getSpecialAttribute2() = 0;
    virtual void setSpecialAttribute(double value) = 0;
    virtual void setSpecialAttribute(int value) = 0;
    virtual std::string display() = 0;
    virtual Stock* clone() const = 0;
};


#endif