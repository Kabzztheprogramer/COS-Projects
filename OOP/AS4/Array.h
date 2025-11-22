#ifndef ARRAY_H
#define ARRAY_H

#include "DataStructure.h"
#include "Exceptions.h"

template<class T, bool append = true>
class Array: public DataStructure<T, append>{
    private:
        T* array;
        int size;

    protected:
        virtual std::ostream& printToStream(std::ostream& outStream);

    public:
        Array();
        virtual ~Array();
        
        virtual DataStructure<T, append>& operator+=( T& data);
        virtual DataStructure<T, append>& operator+=( DataStructure<T, append>& other);

        virtual T& operator[](int position);
        virtual int getSize() ;
        virtual T* toArray() ;

        virtual DataStructure<T, append>* clone() ;
};

#include "Array.cpp"

#endif //ARRAY_H
