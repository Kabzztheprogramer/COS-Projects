#include "missed.h"
#include "exceptions.h"

Missed::Missed(int capacity) : CallHandler(capacity)
{
}

Missed::~Missed()
{

    while (head)
    {
        Call *Ctodelete = removeCall();  
        delete Ctodelete;
        Ctodelete = NULL;
    }
}

bool Missed::addCall(std::string id)
{
    if (isFull())
    {
        throw MissedCallsFull();
    }
    Call *newCall = new Call(id);
    newCall->setResolved();


    newCall->next = head;
    head = newCall;
    ++size;

    return true;
}

Call *Missed::removeCall()
{
    if (isEmpty())
    {
        throw MissedCallsEmpty();
    }
    Call *popCall = new Call(*head);
    popCall->setResolved();

    Call *deleteCall = head;
    head = deleteCall->next;
    delete deleteCall;
    --size;
    return popCall;
}

bool Missed::contains(std::string id)
{
    if (head && head->getId() == id)
    {
        return true;
    }
    if (head && head->next && head->next->getId() == id)
    {
        return true;
    }
    return false;
}
