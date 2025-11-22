#ifndef PRIORITY_CPP
#define PRIORITY_CPP
#include "priority.h"
#include <iostream>
// Your code here
template <class T>
inline PriorityList<T>::PriorityList() : List<T>()
{
    tail = NULL;
    numTasks = 0;
}

template <class T>
inline PriorityList<T>::~PriorityList()
{
    while (this->head)
    {
        removeTask();
    }
    this->head = NULL;
    tail = NULL;
}

template <class T>
inline Task<T> *PriorityList<T>::getTail()
{
    return tail;
}

template <class T>
inline int PriorityList<T>::getNumTasks()
{
    return numTasks;
}

template <class T>
inline bool PriorityList<T>::addTask(const Task<T> *toAdd)
{
      if (toAdd == NULL)
    {
        return false;
    }

    Task<T> *newTask = new Task<T>(*toAdd);

    if (this->head)
    {
        this->head->setPrev(newTask);
        newTask->setNext(this->head);
        this->head = newTask;
    }
    else
    {
        this->head = newTask;
        tail = newTask;
    }
    ++numTasks;
    return true;
}

template <class T>
inline bool PriorityList<T>::removeTask()
{

     if (this->tail == NULL)
    {
        return false;
    }

    Task<T> *current = this->tail;

    if(tail == this->head){
        this->head = tail = NULL;
    }else{
        tail = current->getPrev();
        if(tail->getPrev() == NULL){
            this->head = tail;
        }
        tail->setNext(NULL);
    }

    delete current ;
    --numTasks;

    return true;
}

template <class T>
inline std::string PriorityList<T>::doNTasks(int numTasks)
{
    
    std::stringstream results ; 
    
    Task<T> *current = this->tail;
    int total = numTasks;
    
    for(int i  = 0 ; i < total ; i++){
        if(this->tail){ 
            results << "Task: "<<tail->getDescription() << " Priority: "<<tail->getPriority()  << " Data: "<<tail->getData()<<" COMPLETED\n"; 
            removeTask();
        }
    }
    
    return results.str();
}

template <class T>
inline std::string PriorityList<T>::doTasks()
{
    
    return doNTasks(numTasks);
}
#endif