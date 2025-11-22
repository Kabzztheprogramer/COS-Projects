
#include <iostream>
#include <sstream>
using namespace std;

#ifndef STACK_H
#define STACK_H

template <class T>
class Stack{
private:
struct stackNode
{
    T data;
    stackNode* next;
};
stackNode* top;
public:
Stack(){
    top = NULL;
}
~Stack(){
    while(!isEmpty()){
        pop();
    }
}
bool isEmpty(){
    return top == NULL;
}
void push(T value){
    stackNode* newNode = new stackNode;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
T pop(){
    if (!isEmpty())
    {
    T num = top->data;
    stackNode* temp = top;
    top = top->next;
    delete temp;
    return num;
    }
    else{
        return 0;
    }

}

T lookTop(){
    return top->data;
}

    string toString(){
        stringstream ss;
        if (top)
        {
            stackNode* pntr = top;
            while (pntr){
                ss << pntr->data  ;
                if (pntr->next)
                {
                    ss << "\n|" << endl;
                }
                pntr=pntr->next;
            }
        }
        else{
            ss << "Stack IS EMPTY";
        }
        
        return ss.str();
    }

};

#endif