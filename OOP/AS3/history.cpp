#ifndef HISTORY_CPP
#define HISTORY_CPP
#include "history.h"

//Your code here
template <class T>
inline History<T>::History():List<T>()
{
    numTasks = 0 ;
}
template <class T>
inline History<T>::~History()
{
    Task<T> *current; 
    while (this->head)
        {
        current = removeTask();
        delete current ;
        }
    current = NULL ;
}
template <class T>
inline int History<T>::getNumTasks() {
    return numTasks;
}
template <class T>
inline bool History<T>::addTask(const Task<T> *newTask)
{
    if (newTask == NULL)
    {
        return false;
    }

    Task<T> *toAdd = new Task<T>(*newTask);

    if (this->head)
    {
        toAdd->setNext(this->head);
        this->head = toAdd ;
    }
    else
    {
        this->head = toAdd ;
    }
    ++numTasks;
    return true;
}

template <class T>
inline Task<T> *History<T>::removeTask()
{

     if (this->head == NULL)
    {
        return NULL;
    }

    Task<T> *current = this->head;
    Task<T> *Temp = new Task<T>(*this->head);
    
    if(current->getNext() == NULL){
        this->head = NULL ;
    }else{
        this->head = current->getNext();
    }
    delete current;
    --numTasks;

    return Temp ;
}

template <class T>
inline std::string History<T>::undoLatest()
{
    std::stringstream results ; 
    
    Task<T> *current = removeTask();
    if(current){
        results << "Task: "<<current->getDescription() << " Priority: "<<current->getPriority() << " Data: "<<current->getData()<<" UNDID\n"; 
        delete current;
    }
    return results.str();
}

template <class T>
inline std::string History<T>::doTasks()
{
    std::stringstream results ; 
    int Ttotal = numTasks;
    for(int i  = 0 ; i < Ttotal ; i++){

        results << undoLatest();

    }
    return results.str();
}

#endif