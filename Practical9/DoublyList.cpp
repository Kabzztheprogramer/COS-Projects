#ifndef DOUBLYLIST_CPP
#define DOUBLYLIST_CPP

#include "DoublyList.h"
#include <string>
#include <sstream>
#include <iostream>
template <class T>
DoublyList<T>::DoublyList() : head(NULL), tail(NULL)
{
}

template <class T>
DoublyList<T>::DoublyList(const DoublyList<T> &other)
{
    DoublyNode<T> *OnodePtr = other.head;
    if (OnodePtr != NULL)
    {

        head = new DoublyNode<T>(OnodePtr->getData());
        DoublyNode<T> *nodePtr = head;

        while (OnodePtr->next)
        {
            nodePtr->next = new DoublyNode<T>(OnodePtr->next->getData());
            nodePtr->next->prev = nodePtr;
            OnodePtr = OnodePtr->next;
            nodePtr = nodePtr->next;
        }
        tail = nodePtr;
    }
    else
    {
        head = NULL;
        tail = NULL;
    }
}

template <class T>
DoublyList<T>::~DoublyList()
{
    DoublyNode<T> *nodePtr = head;
    if (nodePtr != NULL)
    {

        while (nodePtr->next)
        {
            nodePtr = nodePtr->next;
            delete nodePtr->prev;
        }
        delete nodePtr;
    }
}

template <class T>
std::string DoublyList<T>::toString()
{
    DoublyNode<T> *nodePtr = head;
    std::stringstream ss;

    while (nodePtr)
    {
        ss << nodePtr->toString();
        if (nodePtr->next)
        {
            ss << "->";
        }
        nodePtr = nodePtr->next;
    }
    return ss.str();
}

template <class T>
void DoublyList<T>::insert(T data, int position)
{
      if (position == 0)
    {
        return;
    }

    DoublyNode<T> *newNode = new DoublyNode<T>(data);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        head->next = NULL;
        head->prev = NULL;
        return;
    }

    if (position > 0)
    {
        bool found = false;
        int num = 1;
        DoublyNode<T> *nodePtr = head;
        while (nodePtr != NULL && num < position)
        {
            nodePtr = nodePtr->next;
            ++num;
        }

        if (nodePtr == NULL)
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else
        {
            newNode->next = nodePtr;
            newNode->prev = nodePtr->prev;

            if (newNode->prev == NULL)
            {
                head = newNode;
            }
            else
            {
                nodePtr->prev->next = newNode;
            }
            nodePtr->prev = newNode;
        }
    }
    else
    {

        bool found = false;
        int num = -1;
        DoublyNode<T> *nodePtr = tail;
        while (nodePtr != NULL && num > position)
        {
            nodePtr = nodePtr->prev;
            --num;
        }

        if (nodePtr == NULL)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else
        {
            newNode->prev = nodePtr;
            newNode->next = nodePtr->next;
            if (newNode->next == NULL)
            {
                tail = newNode;
            }
            else
            {
                nodePtr->next->prev = newNode;
            }
            nodePtr->next = newNode;
        }
    }
}
template <class T>
int DoublyList<T>::contains(T data)
{
    DoublyNode<T> *nodePtr = head;
    int num = 0;
    while (nodePtr)
    {
        if (nodePtr->getData() == data)
        {
            ++num;
        }
        nodePtr = nodePtr->next;
    }
    return num;
}

template <class T>
int DoublyList<T>::remove(T data)
{
    DoublyNode<T> *nodePtr = head;
    int num = 0;
    while (nodePtr)
    {
        if (nodePtr->getData() == data)
        {
            DoublyNode<T> *DnodePtr = nodePtr;
            nodePtr = nodePtr->next;
            if (DnodePtr->prev == NULL && DnodePtr->next == NULL)
            {
                head = NULL;
                tail = NULL;
            }
            else if (DnodePtr->prev == NULL)
            {
                head = DnodePtr->next;
                head->prev = NULL;
            }
            else if (DnodePtr->next == NULL)
            {
                tail = DnodePtr->prev;
                tail->next = NULL;
            }
            else
            {
                DnodePtr->prev->next = DnodePtr->next;
                DnodePtr->next->prev = DnodePtr->prev;
            }
            delete DnodePtr;
            DnodePtr = NULL;

            ++num;
        }
        else
        {
            nodePtr = nodePtr->next;
        }
    }
    return num;
}

#endif