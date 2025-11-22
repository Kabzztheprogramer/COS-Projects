#include "employee.h"

Employee* Employee::clone() const{
    return new Employee(*this);
}

Employee::Employee(std::string id, std::string contact, int age, std::string name, double salary)
    : Person(id, contact, age), name(name), salary(salary), hoursWorked(0)
{
}
// Destructor
Employee::~Employee()
{
}

// Getter for name
std::string Employee::getName()
{
    return name ;
}

// Getter for salary (Special Attribute 1)
double Employee::getSpecialAttribute1()
{
    return salary ;
}

// Getter for hoursWorked (Special Attribute 2)
int Employee::getSpecialAttribute2()
{
    return hoursWorked;
}

// Setter for salary
void Employee::setSpecialAttribute(double salary)
{
    this->salary = salary;
}

// Setter for hoursWorked
void Employee::setSpecialAttribute(int hours)
{
    this->hoursWorked = hours;
}

// Display function
std::string Employee::display()
{
    std::stringstream ss;
    ss<<"ID: " << this->getId() << " | Contact: " << this->getAttribute1()
        << " | Age: " << this->getAttribute2()<< " | Name: "<< getName() << 
        " | Salary: "<< salary  << " | Hours: "<<hoursWorked <<" |" ;
    return ss.str();
}