 #include <iostream>
#include <sstream>
#include "stack.h"
using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

template <class t>
class Queue{
    private:

    struct QeueuNode
    {
        t value;
        QeueuNode* next;
    };
    QeueuNode* front;
    QeueuNode* rear;

    public:
    Queue(){
        front = NULL;
        rear = NULL;
    }
    ~Queue(){
        while(!this->IsEmpty()){
            this->Deque();
        }
    }
    void Enque(t data){
        if (IsEmpty())
        {
            QeueuNode* newNode = new QeueuNode;
            newNode->value = data;
            newNode->next = NULL;

            front = newNode;
            rear = newNode;
        }
        else{
            QeueuNode* newNode = new QeueuNode;
            newNode->value = data;
            newNode->next = NULL;
            rear->next = newNode;
            rear = newNode;
        }
        
    }
    t Deque(){
        if (IsEmpty()){
            cout << "LIST IS EMPTY " << endl;
            return 0;
        }
        else{
            t num = front->value;
            QeueuNode* temp = front;
            front = front->next;
            delete temp;
            
            //check did we dequeue the only element, if yes make sure to update rear
            if (front == NULL){
                rear = NULL;
            }
            return num;


        }
    }


    bool IsEmpty(){
        return front == NULL;
    }
    //dont really need an is full with dynamic memory but could implement

    string toString(){
        stringstream ss;
        if (front)
        {
            QeueuNode* pntr = front;
            while (pntr){
                
                if (pntr == front)
                {
                    ss << pntr->value ;
                }
                else{
                    ss << "<-" << pntr->value;
                }
                pntr=pntr->next;
            }
        }
        else{
            ss << "LIST IS EMPTY";
        }
        
        return ss.str();
    }

    void reverse(){
        Stack<t> temp;

        while(!IsEmpty())
        {
            t x = Deque();
            temp.push(x);
        }

        while(!temp.isEmpty())
        {
            t x = temp.pop();
            Enque(x);
        }

        std::cout << "Reversed Queue: ";
        std::cout << toString() << std::endl;
    }

};

#endif