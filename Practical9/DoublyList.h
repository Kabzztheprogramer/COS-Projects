#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include "DoublyNode.h"

template< class T>
class DoublyList {
private:
    /* data */
    DoublyNode<T>* head ;
    DoublyNode<T>* tail ;
public:
    DoublyList();
    DoublyList(const DoublyList<T>& other);
    ~DoublyList();
    std::string toString() ;
    void insert(T data , int position);
    int contains(T data);
    int remove(T data);
};


#include "DoublyList.cpp"
#endif


