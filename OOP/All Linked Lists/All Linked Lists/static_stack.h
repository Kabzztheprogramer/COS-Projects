#include <iostream>
using namespace std;

class StaticStack {
private:
    int SIZE;
    int numPresent;
    int top;
    int* arr;

public:
    StaticStack(int size = 10) : numPresent(0), top(-1), SIZE(size) {
        arr = new int[SIZE];
    }

    ~StaticStack() {
        delete[] arr;
    }

    bool isEmpty() {
        return numPresent == 0;
    }

    bool isFull() {
        return numPresent == SIZE;
    }

    void push(int x) {
        if (!isFull()) {
            arr[++top] = x;
            numPresent++;
        } else {
            cout << "STACK IS FULL" << endl;
        }
    }

    int Top() {
        if (!isEmpty()) {
            return arr[top];
        } else {
            cout << "STACK IS EMPTY" << endl;
            return -1; // Error case
        }
    }

    int pop() {
        if (!isEmpty()) {
            int x = arr[top];
            top--;
            numPresent--;
            return x;
        } else {
            cout << "STACK IS EMPTY" << endl;
            return -1; // Error case
        }
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack contents: \n";
        // Print from top to 0 (top to bottom of the stack)
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << endl;
        }
        cout << endl;
    }
};
