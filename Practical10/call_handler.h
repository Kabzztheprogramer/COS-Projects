#ifndef CALL_HANDLER_H
#define CALL_HANDLER_H

#include "call.h"

class CallHandler {
protected:
    int capacity;
    int size;
    Call* head;

public:
    CallHandler(int capacity);
    virtual ~CallHandler();

    int getCapacity();
    int getSize();
    Call* getHead();
    void updateCapacity(int adjustment);
    bool isEmpty();
    bool isFull();
    std::string callLog();

    virtual bool addCall(std::string id) = 0;
    virtual Call* removeCall() = 0;
    virtual bool contains(std::string id) = 0;
};

#endif
