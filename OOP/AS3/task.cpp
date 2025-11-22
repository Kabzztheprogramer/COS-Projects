#ifndef TASK_CPP
#define TASK_CPP
#include "task.h"

// Your code here
template <class T>
inline Task<T>::Task(int priority, std::string description, bool repeat, T data)
{
    this->priority = priority;
    this->description = description;
    this->repeat = repeat;
    this->data = data;
    prev = NULL;
    next = NULL;
}

template <class T>
inline Task<T>::Task(const Task<T> &toCopy)
{
    this->priority = toCopy.priority;
    this->description = toCopy.description;
    this->repeat = toCopy.repeat;
    this->data = toCopy.data;
    prev = NULL;
    next = NULL;
    
}
template <class T>
inline Task<T>::~Task()
{
}

template <class T>
inline int Task<T>::getPriority()
{
    return priority;
}

template <class T>
inline std::string Task<T>::getDescription()
{
    return description;
}

template <class T>
inline bool Task<T>::getRepeat()
{
    return repeat;
}

template <class T>
inline T Task<T>::getData()
{
    return data;
}

template <class T>
inline Task<T> *Task<T>::getNext()
{
    return next;    
}

template <class T>
inline Task<T> *Task<T>::getPrev()
{
    return prev;
}

template <class T>
inline bool Task<T>::setNext(Task<T> *nextTask)
{
    this->next = nextTask;
    return true;
}

template <class T>
inline bool Task<T>::setPrev(Task<T> *prevTask)
{
    this->prev = prevTask;
    return true;
}

template <class T>
inline bool Task<T>::operator==(const Task<T> &other)
{
    return (this->priority == other.priority &&
            this->description == other.description &&
            this->repeat == other.repeat &&
            this->data == other.data);
}

#endif