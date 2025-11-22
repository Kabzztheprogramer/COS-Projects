#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class CallTaken : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Call already taken";
    }
};

class IncomingCallsFull : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Incoming call queue full";
    }
};

class IncomingCallsEmpty : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Incoming call queue empty";
    }
};

class MissedCallsFull : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Missed calls stack full";
    }
};

class MissedCallsEmpty : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Missed calls stack empty";
    }
};

class OperatorNotFound : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Operator not found";
    }
};

#endif
