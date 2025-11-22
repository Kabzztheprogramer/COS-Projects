#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "DataStructure.h"

template <class T>
struct Node{
    T data;
    Node<T>* next;
    Node(T data): data(data), next(NULL){};
};

template <class T, bool append=true>
class LinkedList: public DataStructure<T, append>{
    private:
        Node<T>* head;
        virtual std::ostream &printToStream(std::ostream &outStream);
    public:
        LinkedList();
        ~LinkedList();
        virtual DataStructure<T, append> &operator+=( T &data);
        virtual DataStructure<T, append> &operator+=( DataStructure<T, append> &other);

        virtual T &operator[](int position);
        virtual int getSize();
        virtual T *toArray();
        virtual DataStructure<T, append> *clone();
};

#include "LinkedList.cpp"

#endif /*LINKEDLIST_H*/
