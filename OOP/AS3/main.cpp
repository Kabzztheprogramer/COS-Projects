#include <iostream>
#include <string>
#include <sstream>

#include "task.h"
#include "list.h"
#include "todo.h"
#include "weekly.h"
#include "priority.h"
#include "history.h"
#include "manager.h"

using namespace std;
template <class T>

void printTask(Task<T> task)
{

    cout << "Priority : " << task.getPriority() << " \n"
         << "Description : " << task.getDescription() << " \n"
         << "Repeat : " << task.getRepeat() << " \n"
         << "Data : " << task.getData() << " \n";
}
void tasktesting()
{
    // testing task
    Task<string> task1(1, "Make your bed", false, "Assignment details");
    cout << "Task 1 detials : \n";
    printTask(task1);

    cout << "Test the copy constructor \n";
    cout << "\nTask 2 detials : \n";
    Task<string> task2 = task1;
    printTask(task2);

    string equal = (task1 == task2) ? "Yes" : "No";
    cout << "Is Task 1 = Task 2\n"
         << equal << "\n";
}
void todotesting()
{
    Todo<std::string> todoList;

    Task<std::string> task1(1, "Complete Assignment", false, "Assignment details");
    Task<std::string> task2(2, "Attend Meeting", false, "Meeting agenda");
    Task<std::string> task3(3, "Workout", false, "Gym session");

    // Add tasks to the todo list
    todoList.addTask(&task1);
    todoList.addTask(&task2);
    todoList.addTask(&task3);

    std::cout << "Tasks in Todo List:\n"
              << todoList.doTasks() << std::endl;

    int searchPriority = 2;
    Task<std::string> *foundTask = todoList.findTask(searchPriority);
    if (foundTask)
    {
        std::cout << "Found task with priority " << searchPriority << ": "
                  << foundTask->getDescription() << std::endl;
    }
    else
    {
        std::cout << "Task with priority " << searchPriority << " not found." << std::endl;
    }

    string description = "Workout";
    foundTask = todoList.findTask(description);
    if (foundTask)
    {
        std::cout << "Found task with description : " << description << " && a priority of: "
                  << foundTask->getPriority() << std::endl;
    }
    else
    {
        std::cout << "Task with description : " << description << " not found." << std::endl;
    }

    std::cout << "\nRemoving task: " << task2.getDescription() << std::endl;
    todoList.removeTask(&task2);
    std::cout << "Updated Tasks in Todo List:\n"
              << todoList.doTasks() << std::endl;

    // Try finding a removed task
    foundTask = todoList.findTask(searchPriority);
    if (foundTask)
    {
        std::cout << "Found task with priority " << searchPriority << ": "
                  << foundTask->getDescription() << std::endl;
    }
    else
    {
        std::cout << "Task with priority " << searchPriority << " not found (as expected)." << std::endl;
    }
}
void WeeklyTaskstesting()
{
    WeeklyTasks<int> week1task;

    Task<int> task1(1, "C", false, 7);
    Task<int> task2(2, "A", false, 8);
    Task<int> task3(3, "D", false, 9);
    Task<int> task4(4, "B", false, 10);

    week1task.addTask(&task1);
    std::cout << "Tasks in Week List 1:\n"
              << week1task.doTasks() << std::endl;
    week1task.addTask(&task2);
    std::cout << "Tasks in Week List 2 :\n"
              << week1task.doTasks() << std::endl;
    week1task.addTask(&task3);
    std::cout << "Tasks in Week List 3:\n"
              << week1task.doTasks() << std::endl;
    week1task.addTask(&task4);
    std::cout << "Tasks in Week List 4:\n"
              << week1task.doTasks() << std::endl;

    std::cout << "Removing tasks 4:\n"
              << "Yes = 1 / No = 0 \n"
              << week1task.removeTask(&task4)
              << std::endl;
    std::cout << "Tasks in Week List 4:\n"
              << week1task.doTasks() << std::endl;
}
void prioritylisttesting()
{
    PriorityList<string> PL1;

    Task<std::string> task1(1, "Complete Assignment", false, "Assignment details");
    Task<std::string> task2(2, "Attend Meeting", false, "Meeting agenda");
    Task<std::string> task3(3, "Workout", false, "Gym session");
    Task<std::string> task4(4, "Recovery", false, "Relax");

    PL1.addTask(&task1);
    PL1.addTask(&task2);
    PL1.addTask(&task3);
    PL1.addTask(&task4);



    std::cout << "Tasks in priority List:\n"
              << "Removing a task:\n";
    bool RemoveTask = PL1.removeTask();
    if (RemoveTask)
    {
        std::cout << "Found a task " << ": "
                  << "Task was removed \n"
                  << std::endl;
    }
    else
    {
        std::cout << "Found no tasks \n"
                  << std::endl;
    }

    std::cout << "Tasks in Priority List:\n"
              << PL1.doNTasks(3) << std::endl;

    std::cout << "Removing a task:\n";
    RemoveTask = PL1.removeTask();
    if (RemoveTask)
    {
        std::cout << "Found a task " << ": "
                  << "Task was removed \n"
                  << std::endl;
    }
    else
    {
        std::cout << "Found no tasks \n"
                  << std::endl;
    }
}
void historylisttesting()
{
    History<string> HL1;

    Task<std::string> task1(1, "Complete Assignment", false, "Assignment details");
    Task<std::string> task2(2, "Attend Meeting", false, "Meeting agenda");
    Task<std::string> task3(3, "Workout", false, "Gym session");

    std::cout << "Adding to the History List ........\n";
    HL1.addTask(&task1);
    HL1.addTask(&task2);
    HL1.addTask(&task3);

    std::cout << "Removing the lastest \n"
              << HL1.undoLatest();
    std::cout << "Tasks in History List:\n"
              << HL1.doTasks();
}
void managerTesting(){
    TaskManager<string>TM1("tasks.txt");
    string s1 = TM1.getTodo()->doTasks(); 
    std::cout << "Tasks in Todo List:\n"
              << s1 << std::endl;
    std::cout << "Setting Weekly List....\n";
    TM1.setWeeklyTasks();
    string s2 = TM1.doWeekly(2);
    std::cout <<"Task done on a weekly bases : \n"<< s2;
    std::cout << "Setting Priority List....\n";
    TM1.setPriority();
    string s3 = TM1.doPriority(5);
    std::cout <<"Priority list : \n"<< s3;
    std::cout <<"Trying to do more tasks in the priority: \n"<< TM1.doPriority(5)<<"\n";
    string s4 = TM1.undoTasks(false);
    std::cout <<"Undoing 1 task in history : \n"<< s4;
    string s5 = TM1.undoTasks(true);
    std::cout <<"Undoing all the tasks in history : \n"<< s5;
    std::cout <<"Trying to undoing more from history : \n"<< TM1.undoTasks(true)<<"\n";

 
}
int main()
{

    // testing task
        // tasktesting();
    // testing todo
     //   todotesting();
    // // testing Weekly
    //WeeklyTaskstesting();
    // // testing  Priority List
    // prioritylisttesting();
    // // testing  History List
    //   historylisttesting();
    // //testing manger list
       managerTesting();
        
    
    return 0;
}