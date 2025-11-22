#include "DataStructure.h"

using namespace std;

template<class T, bool append>
DataStructure<T, append>::~DataStructure()
{
    //TODO: Implement function
}

template<class T, bool append>
std::ostream &operator<<(std::ostream &out,  DataStructure<T, append> &object)
{
    //TODO: Implement function
    return object.printToStream(out);
}
