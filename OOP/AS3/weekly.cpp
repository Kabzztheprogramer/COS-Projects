#ifndef WEEKLY_CPP
#define WEEKLY_CPP
#include "weekly.h"
#include <iostream>

// Your code here
template <class T>
inline WeeklyTasks<T>::WeeklyTasks() : List<T>()
{
    tail = NULL;
    numTasks = 0;
}

template <class T>
inline WeeklyTasks<T>::~WeeklyTasks()
{

    while (this->tail)
    {
        removeTask(this->tail);
    }
    this->head = NULL;
    this->tail = NULL;
}

template <class T>
inline Task<T> *WeeklyTasks<T>::getTail()
{
    return tail;
}

template <class T>
inline int WeeklyTasks<T>::getNumTasks()
{
    return numTasks;
}

template <class T>
inline bool WeeklyTasks<T>::addTask(const Task<T> *toAdd)
{

    if (toAdd == NULL)
    {
        return false;
    }

    Task<T> *newTask = new Task<T>(*toAdd);
    if (this->head)
    {
        Task<T> *current = this->head;
        Task<T> *prev = NULL;
        while (current != tail)
        {
            if( current->getDescription() >= newTask->getDescription()){
                if (current == this->head )
                {
                    newTask->setNext(this->head);
                    this->head = newTask;
                    tail->setNext(newTask);
                    ++numTasks;
                    return true;
                }
                else 
                {
                    prev->setNext(newTask);
                    newTask->setNext(current);
                    ++numTasks;
                    return true;
                }
            }
                prev = current;
                current = current->getNext();
        }

        if (current == this->tail && current->getDescription() >= newTask->getDescription())
        {
            if(tail == this->head){
                newTask->setNext(tail);
                tail->setNext(newTask);
                this->head = newTask;
            }else{
            prev->setNext(newTask);
            newTask->setNext(current);
            }
            
        }else{
            newTask->setNext(this->head);
            tail->setNext(newTask);
            tail = newTask;
        }
        ++numTasks;
        return true;
    }
    else
    {
        tail = this->head = newTask;
        tail->setNext(this->head);
        this->head->setNext(tail);
    }
    ++numTasks;
    return true;
}

template <class T>
inline bool WeeklyTasks<T>::removeTask(Task<T> *toRemove)
{
    if (toRemove == NULL || this->head == NULL)
    {
        return false;
    }

    Task<T> *current = this->head;
    Task<T> *prev = NULL;

    while (current != tail)
    {
        if (*current == *toRemove)
        {
            if (current == this->head)
            {
                this->head = current->getNext();
                if (this->head)
                {
                    tail->setNext(this->head);
                }
                else
                {
                    tail = NULL;
                }
            }
            else
            {
                prev->setNext(current->getNext());
            }
            delete current;
            numTasks--;
            if (numTasks == 0)
            {
                this->head = NULL;
                this->tail = NULL;
            }
            return true;
        }
        prev = current;
        current = current->getNext();
    }

    if (*tail == *toRemove)
    {

        if (tail == tail->getNext())
        {
            delete tail;
            this->head = NULL;
            this->tail = NULL;
        }
        else
        {
            prev->setNext(tail->getNext());
            delete tail;
            tail = prev;
        }
        numTasks--;
        return true;
    }
    return false;
}

template <class T>
inline std::string WeeklyTasks<T>::doTasks()
{
    std::stringstream result;
    Task<T> *current = tail->getNext();
    while (current != tail)
    {

        result << "Task: " << current->getDescription() << " Data: " << current->getData() << " COMPLETED\n";
        current = current->getNext();
    }
        result << "Task: " << current->getDescription() << " Data: " << current->getData() << " COMPLETED\n";

    return result.str();
}

template <class T>
inline std::string WeeklyTasks<T>::doTasks(int repitions)
{
    std::string result;
    for (int i = 0; i < repitions; i++)
    {

        result += doTasks();
    }
    return result;
}
#endif