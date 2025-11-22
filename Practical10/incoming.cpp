#include "incoming.h"
#include "exceptions.h" 

Incoming::Incoming(int capacity) : CallHandler(capacity)
{
    tail = NULL;
}

Incoming::~Incoming()
{
        while (head)
        {
            Call *Ctodelete = removeCall();  
            delete Ctodelete;
            Ctodelete = NULL;
        }
} 

bool Incoming::addCall(std::string id)
{
    if (contains(id))
    {
        throw CallTaken();
    }
    if (isFull())
    {
        throw IncomingCallsFull();
    }

    Call *newCall = new Call(id);

    if (isEmpty())
    {
        head = tail = newCall;
    }
    else
    {
        tail->next = newCall;
        tail = newCall;
    }

    ++size;
    return true;
}

Call *Incoming::removeCall()
{
    if (isEmpty())
    {
        throw IncomingCallsEmpty();
    }
    Call *DequeueCall = new Call(*head);
    DequeueCall->setResolved();

    Call *deleteCall = head;
    head = deleteCall->next;
    delete deleteCall;
    --size;

    if (isEmpty())
    {
        tail = NULL;
    }

    return DequeueCall;
}

bool Incoming::contains(std::string id)
{
    Call *current = head;

    while (current)
    {
        if (current->getId() == id)
        {
            return true;
        }
        current = current->next;
    }
    return false;
    
}
