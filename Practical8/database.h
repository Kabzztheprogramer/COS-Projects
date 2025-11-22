#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sstream>
#include "person.h"
#include "stock.h"
#include "product.h"
#include "employee.h"
#include "customer.h"

template<class T>
class Database
{
private:
T** data;
    int maxSize;
    int currentSize;

public:
Database(int max);
    ~Database();

    T** getData();
    int getMaxSize();
    int getCurrentSize();

    bool add(T* record);
    T* getRecord(std::string id);
    bool updateAll(int attribute, double newValue);
    bool updateOne(std::string id, int attribute, double newValue);
    bool remove(std::string id);
    std::string view();

};

#include "database.cpp"
#endif
