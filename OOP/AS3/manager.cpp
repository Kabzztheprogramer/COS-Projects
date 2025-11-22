#ifndef MANAGER_CPP
#define MANAGER_CPP
#include "manager.h"

// Your code here
template <class T>
inline TaskManager<T>::TaskManager(std::string fileName)
    : todo(new Todo<T>()), weekly(NULL), priority(NULL), history(NULL)
{

    std::ifstream file(fileName.c_str());
    std::string line;
    while (getline(file, line))
    {
        std::istringstream iss(line);
        int Tpriority;
        std::string Tdescription;
        bool Trepeat;
        T Tdata;

        if (std::getline(iss, line, '#'))
        {
            std::stringstream ss;
            ss << line;
            ss>> Tpriority;
        }
        if (std::getline(iss, line, '#'))
        {
            Tdescription = line;
        }
        if (std::getline(iss, line, '#'))
        {
            Trepeat = (line == "True");
        }
        if (std::getline(iss, line, '#'))
        {
            std::stringstream ss;
            ss << line;
            ss >> Tdata;
        }
        Task<T> *task = new Task<T>(Tpriority, Tdescription, Trepeat, Tdata);
        todo->addTask(task);
        delete task;
        task = NULL;
    }
    file.close();
}
template <class T>
inline TaskManager<T>::~TaskManager()
{
    if(todo){
        delete todo;
    }
    if(weekly){
        delete weekly;
    }
    if(priority){
        delete priority;
    }
    if(history){
        delete history;
    }
    
}

template <class T>
inline Todo<T> *TaskManager<T>::getTodo()
{
    return todo;
}

template <class T>
inline WeeklyTasks<T> *TaskManager<T>::getWeekly()
{
    return weekly;
}

template <class T>
inline PriorityList<T> *TaskManager<T>::getPriority()
{
    return priority;
}

template <class T>
inline History<T> *TaskManager<T>::getHistory()
{
    return history;
}

template <class T>
inline bool TaskManager<T>::newTask(const Task<T> *newTask)
{
    return todo->addTask(newTask);
}

template <class T>
inline void TaskManager<T>::setWeeklyTasks()
{
    if (weekly == NULL)
    {
        weekly = new WeeklyTasks<T>();
    }
    Task<T> *current = todo->getHead();
    while (current != NULL)
    {
        Task<T> *next = current->getNext();

        if (current->getRepeat())
        {
            weekly->addTask(current);
            todo->removeTask(current);
        }
        current = next;
    }
}

template <class T>
inline void TaskManager<T>::setPriority()
{

    if (priority == NULL)
    {
        priority = new PriorityList<T>();
    }

    Task<T> *current = todo->getHead();
    while (current != NULL)
    {
        Task<T> *next = current->getNext();

        if (!current->getRepeat())
        {
            bool added = false;
            while (added == false)
            {
                Task<T> *LowestP = current;
                Task<T> *current2 = current->getNext();
                while (current2 != NULL)
                {
                    if (!current2->getRepeat() && current2->getPriority() < LowestP->getPriority())
                    {
                        LowestP = current2;
                    }
                    current2 = current2->getNext();
                }
                
                if (LowestP == current)
                {
                    priority->addTask(LowestP);
                    next = current->getNext();
                    todo->removeTask(current);
                    added = true;
                }
                else
                {
                    priority->addTask(LowestP);
                    todo->removeTask(LowestP);
                }
            }
        }
        current = next;
    }
}

template <class T>
inline std::string TaskManager<T>::doWeekly(int cycles)
{
    if (weekly == NULL)
    {
        return "";
    }
    return weekly->doTasks(cycles);
}

template <class T>
inline std::string TaskManager<T>::doPriority(int numTasks)
{
    if (priority == NULL)
    {
        return "Priority Queue Empty";
    }
    if(priority->getTail() == NULL){

        return "Priority Queue Empty";
    }

    if (history == NULL)
    {
        history = new History<T>();
    }

    int count = 0;
    Task<T> *current = priority->getTail();
    while (current != NULL && count < numTasks)
    {
        history->addTask(current);
        current = current->getPrev();
        ++count;
    }
    return priority->doNTasks(numTasks);
}

template <class T>
inline std::string TaskManager<T>::undoTasks(bool all)
{

    if (history == NULL || history->getNumTasks() == 0)
    {
        return "Nothing to Undo";
    }

    std::string result;
    if (priority == NULL)
    {
        priority = new PriorityList<T>();
    }

    if (all)
    {
        Task<T> *current = history->getHead();
        while (current != NULL)
        {
            priority->addTask(current);
            current = current->getNext();
        }
        result = history->doTasks();
        
    }
    else
    {
        Task<T> *undoneTask = history->getHead();
        priority->addTask(undoneTask);
        result = history->undoLatest();
        
    }

    return result;
}

#endif