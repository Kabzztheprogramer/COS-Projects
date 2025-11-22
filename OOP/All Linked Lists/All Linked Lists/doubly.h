#include <iostream>
#include "node.h"

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    ~DoublyLinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = NULL;
    }

    // Insert a node in ascending order
    void insertInOrder(int value) {
        Node* newNode = new Node(value);

        // If list is empty
        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        // If inserting before head
        if (value < head->data) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        // Insert in the correct position in the sorted list
        Node* current = head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
    }

    // Append a node to the end of the list
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Prepend a node to the beginning of the list
    void prepend(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
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
            head->prev = NULL;
        }
        delete toDelete;
    }

    // Remove a node from the end of the list
    void removeFromEnd() {
        if (head == NULL) return;

        Node* toDelete = tail;
        if (head == tail) {  // Only one node
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete toDelete;
    }

    // Remove a node with a specific value
    void remove(int value) {
        if (head == NULL) return;

        Node* current = head;
        while (current != NULL) {
            if (current->data == value) {
                if (current == head) {  // Removing head
                    removeFromBeginning();
                } else if (current == tail) {  // Removing tail
                    removeFromEnd();
                } else {  // Removing from the middle
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                }
                return;
            }
            current = current->next;
        }
    }

    // Display the list
    void display() const {
        if (head == NULL) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Display the list in reverse order
    void displayReverse() const {
        if (tail == NULL) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = tail;
        while (temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }
};
