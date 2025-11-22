#ifndef DOUBLYNODE_CPP
#define DOUBLYNODE_CPP

#include "DoublyNode.h"

template <class T>
DoublyNode<T>::DoublyNode(T data) {
    this->data = data;
    prev = next = NULL;
}

template <class T>
DoublyNode<T>::~DoublyNode() {
}

template <class T>
T DoublyNode<T>::getData() {
    return data;
}

template <class T>
std::string DoublyNode<T>::toString() {
    std::stringstream ss;
    ss << "[";
    if (prev) {
        ss << prev->data;
    } else {
        ss << "-";
    }
    ss << "," << data << ",";
    if (next) {
        ss << next->data;
    } else {
        ss << "-";
    }
    ss << "]";
    return ss.str();
}

#endif