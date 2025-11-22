#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H

#include <sstream>
#include <string>

template <class T>
class DoublyNode {
   private:
    T data;

   public:
    DoublyNode<T> *prev;
    DoublyNode<T> *next;
    DoublyNode(T data);
    ~DoublyNode();

    T getData();

    std::string toString();
};

#include "DoublyNode.cpp"

#endif