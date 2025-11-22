#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
#include <sstream>

class Person
{
private: //protected
    std::string id;
    std::string contact;
    int age;
public:

   Person(std::string id, std::string contact, int age);
    virtual ~Person();
    
    std::string getId();
    std::string getAttribute1();
    int getAttribute2();

    void setAttribute(std::string contact);
    void setAttribute(int age);

    // Pure virtual functions
    virtual double getSpecialAttribute1() = 0;
    virtual int getSpecialAttribute2() = 0;
    virtual void setSpecialAttribute(double value) = 0;
    virtual void setSpecialAttribute(int value) = 0;
    virtual std::string display() = 0;
    virtual Person* clone() const = 0;
};


#endif