#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "person.h"

class Employee : public Person
{
private:
    std::string name;
    double salary;
    int hoursWorked;

public:
    Employee(std::string id, std::string contact, int age, std::string name, double salary);
    ~Employee();

    std::string getName();
    double getSpecialAttribute1() ;
    int getSpecialAttribute2() ;

    void setSpecialAttribute(double salary) ;
    void setSpecialAttribute(int hours) ;

    std::string display() ;
    Employee* clone() const ;
};

#endif
