#include "call.h"
#include <string>
#include <sstream>
#include <iostream>

Call::Call(std::string id)
{
    this->id = id ;
    resolved = false ;
    next =  NULL ;
}

Call::~Call()
{
}
std::string Call::getId()
{
    return id;
}
void Call::setResolved()
{
    if(resolved){
        resolved = false ;
    }else{
        resolved = true ;
    }
}

std::string Call::displayDetails()
{
    std::stringstream ss;
    ss <<"Caller: "<<id<<" Resolved: "<<resolved ;
    return ss.str();
}


