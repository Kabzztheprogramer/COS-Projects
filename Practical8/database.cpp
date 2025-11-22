#include "database.h"

// Constructor
template<class T>
Database<T>::Database(int max)
{
    this->maxSize = max ;
    this->currentSize = 0;
    data = new T *[maxSize];

    for(int i = 0 ; i < maxSize ; i++){
        data[i] = NULL;
    }
}

// Destructor
template<class T>
Database<T>::~Database()
{
    // Destructor body
    if(data != NULL){

        for(int i = 0 ; i < maxSize ; i++){
            if(data[i] != NULL ){
                delete data[i];
            }
        }
        delete [] data ;
        data = NULL;
    }

}

// Getter for data
template<class T>
T** Database<T>::getData()
{
    return data ;
}

// Getter for maxSize
template<class T>
int Database<T>::getMaxSize()
{
    return maxSize ;
}

// Getter for currentSize
template<class T>
int Database<T>::getCurrentSize()
{
    return currentSize;
}

// Add a new record to the database
template<class T>

bool Database<T>::add(T* record)
{
    if(currentSize < maxSize && data != NULL && record != NULL){

        for(int i = 0 ; i < currentSize ; i++){
            if(data[i]->getId() == record->getId()){
                return false;
            }
        }
        data[currentSize] = record->clone();
        ++currentSize;
        return true;
    }
    return false;
}

// Retrieve a record by ID
template<class T>
T* Database<T>::getRecord(std::string id)
{
    if(currentSize > 0 && data != NULL ){

        for(int i =0 ; i < currentSize ; i++){

            if(data[i]->getId() == id){

                return data[i];

            }
        }
    }
    return NULL;
}


template<class T>
bool Database<T>::updateAll(int attribute, double newValue)
{       
     if(currentSize > 0 && data != NULL ){
        for(int i = 0; i < currentSize ; i++){
            if(attribute == 1){
                if(data[i]->getSpecialAttribute1() == 0){
                    data[i]->setSpecialAttribute(newValue/100.0) ;
                }else{
                    double val = data[i]->getSpecialAttribute1();
                    double result = val + val*(newValue/100.0) ;
                    data[i]->setSpecialAttribute(result);
                }
            }else if(attribute == 2){

                    int val = data[i]->getSpecialAttribute2();
                    int result = val + static_cast<int>(newValue) ;

                    data[i]->setSpecialAttribute(result) ;
            }else{
                return false;
            }
        }
        return true ;
    }
    return false ;
 }

template <>
bool Database<Customer>::updateAll(int attribute, double newValue) {

    if(currentSize > 0 && data != NULL ){
        for (int i = 0; i < currentSize; ++i) {
            Customer* record = data[i];
            double newV = newValue;
            if (attribute == 1) {

                if (record->getSpecialAttribute()) { 
                    newV += 2.5; 
                }

                if (record->getSpecialAttribute1() == 0) {
                    record->setSpecialAttribute(newV / 100.0);
                } else {
                    double currentDiscount = record->getSpecialAttribute1();
                    record->setSpecialAttribute(currentDiscount + currentDiscount * newV / 100.0);
                }
            } else if (attribute == 2) {
                int currentVisits = record->getSpecialAttribute2();
                record->setSpecialAttribute(currentVisits + static_cast<int>(newV));
                
                if (record->getSpecialAttribute2() > 15) {
                    record->setSpecialAttribute(true); 
                }
            } else {
                return false;
            }
        }
        
        return true ;
    }
    return false ;
}

// Update one record's specific attribute by ID
template<class T>
bool Database<T>::updateOne(std::string id, int attribute, double newValue)
{
    T*record = getRecord(id);
    if(currentSize > 0 && data != NULL ){
            if(record){
                if(attribute == 1){

                    if(record->getSpecialAttribute1() == 0){
                        record->setSpecialAttribute(newValue/100.0) ;
                    }else{
                        double val = record->getSpecialAttribute1();
                        double result = val + val*newValue/100.0 ;
                        record->setSpecialAttribute(result);
                    }

                }else if(attribute == 2){

                        double val = record->getSpecialAttribute1();
                        double result = val + static_cast<int>(newValue) ;
                        record->setSpecialAttribute(result) ;
                }else{
                        return false;
                }

                return true ;
            }
        }

    return false ;
}


template <>
bool Database<Customer>::updateOne(std::string id, int attribute, double newValue) {
    if(currentSize > 0 && data != NULL ){
            Customer* record = getRecord(id);
            if (record) {
                double newV = newValue;
                if (attribute == 1) {

                    if (record->getSpecialAttribute()) { 
                        newV += 2.5; 
                    }
                    
                    if (record->getSpecialAttribute1() == 0) {
                        record->setSpecialAttribute(newV / 100.0);
                    } else {
                        double currentDiscount = record->getSpecialAttribute1();
                        record->setSpecialAttribute(currentDiscount + (currentDiscount * newV / 100.0));
                    }
                } else if (attribute == 2) {
                    
                    int currentVisits = record->getSpecialAttribute2();
                    record->setSpecialAttribute(currentVisits + static_cast<int>(newValue));
                    
                    if (record->getSpecialAttribute2() > 15) {
                        record->setSpecialAttribute(true); 
                    }
                } else {
                    return false; 
                }
                
                return true; 
            }
        }
    return false;
}


template<class T>
bool Database<T>::remove(std::string id)
{
    if(currentSize > 0 && data != NULL ){

        for (int i = 0; i < currentSize; ++i) {
            if (data[i]->getId() == id) {
                delete data[i] ;
                data[i] = NULL;
                for(int j = i ; j < currentSize-1; j++){

                    if(data[j+1] != NULL ){

                        data[j]= data[j+1]->clone();
                        delete data[j+1] ;
                        data[j+1] = NULL;

                    }else{
                        data[j] =  0 ;
                    }
                    
                }
                --currentSize;
                return true;
            }
        }
    }
    return false ;
}

// View all records as a string
template<class T>
std::string Database<T>::view()
{
    if(currentSize > 0 && data != NULL ){
        std::string sdata = "";

        for (int i = 0; i < currentSize; ++i) {
            if (data[i] != NULL) {
                sdata += data[i]->display()+"\n";
            }
        }

        return sdata ;
    }
}

// Explicit template instantiation should be declared here if needed
// For example:
// template class Database<Product>;
// template class Database<Employee>;
// template class Database<Customer>;
