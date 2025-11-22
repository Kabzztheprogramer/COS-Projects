#ifndef TODO_CPP
#define TODO_CPP
#include "todo.h"
    #include <iostream>
// Your code here
template <class T>
inline Todo<T>::Todo() : List<T>()
{
    tail = NULL;
}

template <class T>
Todo<T>::~Todo()
{
    while (this->head)
    {
        removeTask(this->head);
    }
    tail = NULL;
};

template <class T>
inline Task<T> *Todo<T>::getTail()
{
    return tail;
}

template <class T>
bool Todo<T>::addTask(const Task<T> *toAdd)
{

    if (toAdd == NULL)
    {
        return false;
    }

    Task<T> *newTask = new Task<T>(*toAdd);

    if (this->head)
    {
        tail->setNext(newTask);
        newTask->setPrev(tail);
        tail = newTask;
    }
    else
    {
        this->head = newTask;
        tail = newTask;
    }
    return true;
};

template <class T>
bool Todo<T>::removeTask(Task<T> *toRemove)
{
    if (toRemove == NULL || this->head == NULL)
    {
        return false;
    }

    Task<T> *current = this->head;
    while (current != NULL)
    {
        if (*current == *toRemove)
        {
            if (current == this->head)
            {
                this->head = current->getNext();
                if (this->head)
                {
                    this->head->setPrev(NULL);
                }
                else
                {
                    tail = NULL; 
                }
            }
            else if (current == tail)
            {
                tail = current->getPrev();
                if (tail)
                {
                    tail->setNext(NULL);
                }
            }
            else
            {
                current->getNext()->setPrev(current->getPrev());
                current->getPrev()->setNext(current->getNext());
            }
            delete current;

            if (tail == NULL)
            {
                this->head = NULL;
            }

            return true;
        }
        current = current->getNext();
    }

    return false;
}

template <class T>
inline Task<T> *Todo<T>::findTask(int priority)
{
    if (this->head == NULL)
    {
        return NULL;
    }

    Task<T> *current = this->head;
    while (current != NULL)
    {
        if (current->getPriority() == priority)
        {
            return current;
        }
        current = current->getNext();
    }

    return NULL;
}

template <class T>
inline Task<T> *Todo<T>::findTask(std::string description)
{

    Task<T> *current = this->head;

    while (current != NULL)
    {
        if (current->getDescription() == description)
        {
            return current;
        }
        current = current->getNext();
    }
    return NULL;
}

template <class T>
inline std::string Todo<T>::doTasks()
{
    std::string result;
    Task<T> *current = this->head;
    while (current != NULL)
    {
        result += current->getDescription() + "\n";
        current = current->getNext();
    }
    return result;
}
#endif