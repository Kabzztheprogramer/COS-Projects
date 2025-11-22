#ifndef CALL_CENTER_H
#define CALL_CENTER_H

#include "call_handler.h"
#include <string>

class CallCenter {
private:
    CallHandler*** operators;
    int* phones;
    int numOperators;
    int callLimit;

public:
    CallCenter(std::string fileName);
    ~CallCenter();

    CallHandler*** getOperators();
    int* getPhones();
    int getNumOperators();
    int getCallLimit();

    void recieveCalls(std::string fileName);
    std::string takeCall(int op, int calls);
    std::string callBack(int op, int calls);
};

#endif
    