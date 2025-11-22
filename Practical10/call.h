#ifndef CALL_H
#define CALL_H

#include <string>

class Call {
private:
    std::string id;
    bool resolved;
    
public:
    Call* next;

    Call(std::string id);
    ~Call();

    std::string getId();
    void setResolved();
    std::string displayDetails();
};

#endif
