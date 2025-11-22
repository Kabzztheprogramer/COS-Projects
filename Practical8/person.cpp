#include "person.h"


Person::Person(std::string id, std::string contact, int age)
    : id(id), contact(contact), age(age)
{
}


Person::~Person()
{
}


std::string Person::getId()
{
    return id;
}

std::string Person::getAttribute1()
{

    return contact;
}


int Person::getAttribute2()
{
    return age;
}

void Person::setAttribute(std::string contact)
{
    this->contact = contact ;
}


void Person::setAttribute(int age)
{
    this ->age = age ;
}

