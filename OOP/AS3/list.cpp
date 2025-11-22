#ifndef LIST_CPP
#define LIST_CPP
#include "list.h"

//Your code here
template <class T>
inline List<T>::List()
{
    head = NULL ;
}

template <class T>
inline List<T>::~List()
{
}

template <class T>
inline Task<T> *List<T>::getHead()
{
    return head;
}

#endif