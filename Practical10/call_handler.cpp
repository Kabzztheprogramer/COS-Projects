#include "call_handler.h"

#include <string>
#include <sstream>
#include <iostream>

CallHandler::CallHandler(int capacity)
{
    this->capacity = capacity;
    size = 0;
    head = NULL;
}

CallHandler::~CallHandler()
{
}

int CallHandler::getCapacity()
{
    return capacity;
}

int CallHandler::getSize()
{
    return size;
}

Call *CallHandler::getHead()
{
    return head;
}

void CallHandler::updateCapacity(int adjustment)
{
    capacity += adjustment;
    if (capacity <= 0)
    {
        capacity = 1;
    }
}

bool CallHandler::isEmpty()
{
    if (head)
    {
        return false;
    }
    return true;
}

bool CallHandler::isFull()
{
    if (size == capacity)
    {
        return true;
    }
    return false;
}

std::string CallHandler::callLog()
{
    Call *nodeptr = head;
    std::stringstream ss;
    while (nodeptr)
    {
        ss << nodeptr->displayDetails() << "\n";
        nodeptr = nodeptr->next;
    }

    return ss.str();
}
