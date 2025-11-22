#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "person.h"
#include <string>

class Customer : public Person {
private:
    bool loyalty;
    double discount;
    int visits;

public:
    Customer(std::string id, std::string contact, int age, int visits);
    ~Customer();

    bool getSpecialAttribute();
    double getSpecialAttribute1() ;
    int getSpecialAttribute2() ;

    void setSpecialAttribute(bool loyalty) ;
    void setSpecialAttribute(double discount) ;
    void setSpecialAttribute(int visits) ;

    std::string display() ;
    Customer* clone() const ;
};

#endif // CUSTOMER_H
