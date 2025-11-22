#include <iostream>
#include "node.h"

// Recursive helper class
class DoublyLinkedListHelper {
public:
    // Recursive function to display the list from head to tail
    static void displayHelper(Node* node) {
        if (node == NULL) return;
        std::cout << node->data << " ";
        displayHelper(node->next);
    }

    // Recursive function to display the list in reverse from tail to head
    static void displayReverseHelper(Node* node) {
        if (node == NULL) return;
        std::cout << node->data << " ";
        displayReverseHelper(node->prev);
    }

    // Recursive function to count the number of nodes
    static int countHelper(Node* node) {
        if (node == NULL) return 0;
        return 1 + countHelper(node->next);
    }

    // Recursive helper function to insert in order
    static void insertInOrderHelper(Node* current, Node* newNode, Node*& head) {
        if (current == NULL || newNode->data < current->data) {
            if (current == head) {
                newNode->next = head;
                if (head != NULL) head->prev = newNode;
                head = newNode;
            } else {
                newNode->next = current;
                newNode->prev = current->prev;
                if (current->prev != NULL) current->prev->next = newNode;
                current->prev = newNode;
            }
            return;
        }
        insertInOrderHelper(current->next, newNode, head);
    }

    // Recursive helper function to append at the end
    static void appendHelper(Node* current, Node* newNode, Node*& head, Node*& tail) {
        if (current == NULL) {
            head = tail = newNode;
        } else {
            current->next = newNode;
            newNode->prev = current;
            tail = newNode;
        }
    }

    // Recursive helper function to prepend at the beginning
    static void prependHelper(Node* current, Node* newNode, Node*& head) {
        if (current == NULL) {
            head = newNode;
        } else {
            newNode->next = current;
            current->prev = newNode;
            head = newNode;
        }
    }

    // Recursive helper function to remove a node with a specific value
    static void removeHelper(Node* current, int value, Node*& head, Node*& tail) {
        if (current == NULL) return;
        if (current->data == value) {
            if (current == head) {  // Removing head
                if (head == tail) {
                    head = tail = NULL;
                } else {
                    head = head->next;
                    head->prev = NULL;
                }
            } else if (current == tail) {  // Removing tail
                tail = tail->prev;
                tail->next = NULL;
            } else {  // Removing from the middle
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            return;
        }
        removeHelper(current->next, value, head, tail);
    }
};

// Doubly Linked List class
class RecursiveDoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    RecursiveDoublyLinkedList() : head(NULL), tail(NULL) {}

    ~RecursiveDoublyLinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = NULL;
    }

    // Insert in order
    void insertInOrder(int value) {
        Node* newNode = new Node(value);
        DoublyLinkedListHelper::insertInOrderHelper(head, newNode, head);
    }

    // Append at the end
    void append(int value) {
        Node* newNode = new Node(value);
        DoublyLinkedListHelper::appendHelper(tail, newNode, head, tail);
    }

    // Prepend at the beginning
    void prepend(int value) {
        Node* newNode = new Node(value);
        DoublyLinkedListHelper::prependHelper(head, newNode, head);
    }

    // Remove a specific value
    void remove(int value) {
        DoublyLinkedListHelper::removeHelper(head, value, head, tail);
    }

    // Count the number of nodes
    int count() const {
        return DoublyLinkedListHelper::countHelper(head);
    }

    // Display the list from head to tail
    void display() const {
        DoublyLinkedListHelper::displayHelper(head);
        std::cout << std::endl;
    }

    // Display the list from tail to head
    void displayReverse() const {
        DoublyLinkedListHelper::displayReverseHelper(tail);
        std::cout << std::endl;
    }
};

