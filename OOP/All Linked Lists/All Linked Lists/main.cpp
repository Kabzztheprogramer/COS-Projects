#include <iostream>
#include "circular.h"
#include "doubly.h"
#include "stack.h"
#include "queue.h"
#include "static_queue.h"
#include "static_stack.h"
#include "recursive.h"

using namespace std;


void doublely(){
    DoublyLinkedList list;

    list.display(); //Expected List is empty
    // Insert in order
    list.insertInOrder(1);
    list.insertInOrder(2);
    list.insertInOrder(3);
    list.insertInOrder(4);
    list.display();  // Expected: 1 2 3 4

    // Append
    list.append(5);
    list.remove(2);
    list.display();  // Expected: 1 3 4 5

    // Prepend
    list.prepend(2);
    list.display();  // Expected: 2 1 3 4 5

    // Remove from beginning
    list.removeFromBeginning();
    list.display();  // Expected: 1 3 4 5

    // Remove from end
    list.removeFromEnd();
    list.display();  // Expected: 1 3 4
}

void circle(){
    CircularLinkedList list;

    list.display(); //Expected List is empty
    // Insert in order
    list.insertInOrder(10);
    list.insertInOrder(5);
    list.insertInOrder(20);
    list.insertInOrder(15);
    list.display();  // Expected: 5 10 15 20

    // Append
    list.append(25);
    list.remove(10);
    list.display();  // Expected: 5 15 20 25

    // Prepend
    list.prepend(2);
    list.display();  // Expected: 2 5 15 20 25

    // Remove from beginning
    list.removeFromBeginning();
    list.display();  // Expected: 5 15 20 25

    // Remove from end
    list.removeFromEnd();
    list.display();  // Expected: 5 15 20
}

void dynamicQueue(){
    Queue<int> q;
    q.Enque(1);
    q.Enque(2);
    q.Enque(3);
    q.Enque(4);

    cout << q.toString() << endl;
    q.reverse();
    
    q.Deque();
    q.Deque();
    cout << q.toString() << endl;

}

void dynamicStack(){
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << s.toString() << endl;
    cout << endl;
    s.pop();
    s.pop();
    cout << s.toString() << endl;
}

void staticQueue(){
    StaticQueue s(10);
    s.enqueue(1);
    s.enqueue(2);
    s.enqueue(3);
    s.enqueue(4);
    s.enqueue(5);
    s.enqueue(6);
    s.enqueue(7);
    s.enqueue(8);
    s.enqueue(9);
    s.enqueue(10);
    s.enqueue(22);
    s.enqueue(22);
    s.enqueue(22);
    s.enqueue(22);
    s.enqueue(22);
    s.print();

    s.dequeue();
    s.dequeue();
    s.dequeue();
    cout << endl;
    s.print();

    s.enqueue(11);
    s.enqueue(12);
    s.enqueue(13);
    cout << endl;
    s.print();


}

void staticStack(){
    StaticStack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    stack.print();

    cout << "Top element: " << stack.Top() << endl;

    stack.pop();
    stack.print();

}

void recursiveLinkedList(){
        RecursiveDoublyLinkedList list;

    list.append(5);
    list.append(10);
    list.append(20);
    list.insertInOrder(15);
    list.prepend(25);

    std::cout << "List: ";
    list.display();

    std::cout << "Reverse List: ";
    list.displayReverse();

    std::cout << "Number of nodes: " << list.count() << std::endl;

    list.remove(15);
    std::cout << "List after removing 15: ";
    list.display();
}


int main() {

    // circle();
    //dynamicStack();
    //staticQueue();
    //staticStack();
    // doublely();
    //dynamicQueue();
    recursiveLinkedList();
    return 0;
}