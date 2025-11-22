#ifndef INCOMING_H
#define INCOMING_H

#include "call_handler.h"

class Incoming : public CallHandler
{
private:
    Call *tail;

public:
    Incoming(int capacity);
    ~Incoming();

    bool addCall(std::string id);
    Call *removeCall();
    bool contains(std::string id);
};

#endif
