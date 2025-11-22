#ifndef MISSED_H
#define MISSED_H

#include "call_handler.h"

class Missed : public CallHandler {
public:
    Missed(int capacity);
    ~Missed();

    bool addCall(std::string id);
    Call* removeCall();
    bool contains(std::string id);
};

#endif
