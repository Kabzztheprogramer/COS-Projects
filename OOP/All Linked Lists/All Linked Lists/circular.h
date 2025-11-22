#include <iostream>
#include "node.h"

class CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() : head(NULL), tail(NULL) {}

    ~CircularLinkedList() {
        if (head == NULL) return;
        Node* current = head;
        while (current != tail) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete tail;
        head = tail = NULL;
    }

    // Insert a node in ascending order
    void insertInOrder(int value) {
        Node* newNode = new Node(value);

        // If list is empty
        if (head == NULL) {
            head = tail = newNode;
            head->next = head;
            return;
        }

        // If inserting before head or in an ascending position
        if (value < head->data) {
            newNode->next = head;
            tail->next = newNode;
            head = newNode;
            return;
        }

        // Insert in the correct position in the sorted list
        Node* current = head;
        while (current->next != head && current->next->data < value) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        // Update tail if inserted at the end
        if (current == tail) {
            tail = newNode;
        }
    }

    // Append a node to the end of the list
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = tail = newNode;
            head->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    // Prepend a node to the beginning of the list
    void prepend(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = tail = newNode;
            head->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            head = newNode;
        }
    }

    // Remove a node from the beginning of the list
    void removeFromBeginning() {
        if (head == NULL) return;

        Node* toDelete = head;
        if (head == tail) {  // Only one node
            head = tail = NULL;
        } else {
            head = head->next;
            tail->next = head;
        }
        delete toDelete;
    }

    // Remove a node from the end of the list
    void removeFromEnd() {
        if (head == NULL) return;

        Node* current = head;
        if (head == tail) {  // Only one node
            delete head;
            head = tail = NULL;
            return;
        }

        while (current->next != tail) {
            current = current->next;
        }

        delete tail;
        tail = current;
        tail->next = head;
    }

    // Remove a node with a specific value
    void remove(int value) {
        if (head == NULL) return;

        Node* current = tail->next;
        Node* previous = tail;

        while (current != head || previous == tail) { // To ensure we only loop once around the list
            if (current->data == value) {
                if (current == head) {  // Removing head
                    if (head == tail) {  // Single element case
                        delete head;
                        head = tail = NULL;
                    } else {
                        head = head->next;
                        tail->next = head;
                        delete current;
                    }
                } else if (current == tail) {  // Removing tail
                    previous->next = head;
                    tail = previous;
                    delete current;
                } else {  // Removing from the middle
                    previous->next = current->next;
                    delete current;
                }
                return;
            }
            previous = current;
            current = current->next;
            if (current == head) break;  // Prevents infinite loop if value is not found
        }
    }

    // Display the list
    void display() const {
        if (head == NULL) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = head;
        while (temp != tail) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << tail->data << std::endl;
    }
};
