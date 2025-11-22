#include <iostream>
using namespace std;

class StaticQueue
{
private:
    int SIZE;
    int numPresent;
    int front;
    int rear;
    int * arr;

    //this is an alternative to using (rear = (rear+ 1) % SIZE) as this way we check if you are at the last element if you are just reset to 0
    void inc(int& i){
        if (i == SIZE - 1)
        {
            i = 0;
        }
        else{
            i++;
        }
        
    }


public:
    StaticQueue(int size) : numPresent(0), front(0), rear(0), SIZE(size) {
        arr = new int[SIZE];
    }

    ~StaticQueue(){
        delete[] arr;
    }

    bool isFull() const
    {
        return numPresent == SIZE;
    }

    bool isEmpty() const
    {
        return numPresent == 0;
    }

    void enqueue(int value)
    {
        if (!isFull())
        {
            arr[rear] = value;
            //could use : rear = (rear + 1) % SIZE;
            inc(rear);
            numPresent++;
        }
        else
        {
            cout << "Queue is full. Cannot enqueue " << value << "." << endl;
        }
    }

    int dequeue()
    {
        if (!isEmpty())
        {
            int x = arr[front];
            //could use inc(front);
            front = (front + 1) % SIZE;
            numPresent--;
            return x;
        }
        else
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
    }

    void print() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue contents: ";
        for (int i = 0, idx = front; i < numPresent; ++i)
        {
            cout << arr[idx] << " ";
            idx = (idx + 1) % SIZE;
        }
        cout << endl;
    }
};
