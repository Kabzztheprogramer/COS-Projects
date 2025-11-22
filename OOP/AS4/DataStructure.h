#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include <string>
#include <iostream>

#include "Exceptions.h"

template <class T, bool>
class DataStructure;

template <class T, bool append>
std::ostream &operator<<(std::ostream &out,  DataStructure<T, append> &object);

template <class T, bool append = true>
class DataStructure
{
protected:
    virtual std::ostream &printToStream(std::ostream &outStream) = 0;

public:
    virtual ~DataStructure();

    virtual DataStructure<T, append> &operator+=( T &data) = 0;
    virtual DataStructure<T, append> &operator+=( DataStructure<T, append> &other) = 0;

    virtual T &operator[](int position) = 0;
    virtual int getSize()  = 0;
    virtual T *toArray()  = 0;
    virtual DataStructure<T, append> *clone()  = 0;

    friend std::ostream &operator<< <>(std::ostream &out,  DataStructure<T, append> &object);
};

#include "DataStructure.cpp"

#endif // DATASTRUCTURE_H
