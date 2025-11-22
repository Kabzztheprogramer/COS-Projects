#include "LinkedList.h"
#include "Exceptions.h"

// Constructor
template <class T, bool append>
LinkedList<T, append>::LinkedList() : head(nullptr) {}

// Destructor
template <class T, bool append>
LinkedList<T, append>::~LinkedList() {
    deleteNodes(head);  // Helper function to delete nodes recursively
}

// Recursive function to delete all nodes in the linked list
template <class T>
void deleteNodes(Node<T>* node) {
    if (!node) return;
    deleteNodes(node->next);
    delete node;
}

// Recursive helper to add a node at the end or start based on `append`
template <class T, bool append>
void addNode(Node<T>* &node, T &data) {
    if (!node) {
        node = new Node<T>(data);
    } else if (append) {
        if (!node->next) {
            node->next = new Node<T>(data);
        } else {
            addNode(node->next, data);
        }
    } else {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = node;
        node = newNode;
    }
}

// Overloaded operator+= for adding a single element
template <class T, bool append>
DataStructure<T, append>& LinkedList<T, append>::operator+=(T &data) {
    addNode(head, data);
    return *this;
}

// Recursive helper to copy all nodes from another DataStructure
template <class T, bool append>
void LinkedList<T, append>::copyNodes(const DataStructure<T, append> &other, int otherSize, int currentIndex) {
    if (currentIndex >= otherSize) return;
    *this += other[currentIndex];
    copyNodes(other, otherSize, currentIndex + 1);
}

// Overloaded operator+= for adding another DataStructure
template <class T, bool append>
DataStructure<T, append>& LinkedList<T, append>::operator+=(DataStructure<T, append> &other) {
    int otherSize = other.getSize();
    copyNodes(other, otherSize, 0);
    return *this;
}

// Recursive helper to get the size of the linked list
template <class T>
int countNodes(Node<T>* node) {
    return node ? 1 + countNodes(node->next) : 0;
}

// Get the size of the linked list
template <class T, bool append>
int LinkedList<T, append>::getSize() {
    return countNodes(head);
}

// Recursive helper to access a node at a given position
template <class T>
T& getNodeData(Node<T>* node, int position) {
    if (position == 0) return node->data;
    return getNodeData(node->next, position - 1);
}

// Overloaded subscript operator for accessing elements
template <class T, bool append>
T& LinkedList<T, append>::operator[](int position) {
    if (position < 0 || position >= getSize()) {
        throw IndexOutOfBoundsException(position, getSize() - 1);
    }
    return getNodeData(head, position);
}

// Recursive helper to copy nodes into an array
template <class T>
void copyToArray(Node<T>* node, T* array, int currentIndex) {
    if (!node) return;
    array[currentIndex] = node->data;
    copyToArray(node->next, array, currentIndex + 1);
}

// Convert linked list elements to a dynamic array
template <class T, bool append>
T* LinkedList<T, append>::toArray() {
    T* array = new T[getSize()];
    copyToArray(head, array, 0);
    return array;
}

// Recursive helper to clone nodes
template <class T, bool append>
void LinkedList<T, append>::cloneNodes(Node<T>* node, LinkedList<T, append>* cloneList) const {
    if (!node) return;
    *cloneList += node->data;
    cloneNodes(node->next, cloneList);
}

// Clone the current linked list
template <class T, bool append>
DataStructure<T, append>* LinkedList<T, append>::clone() {
    LinkedList<T, append>* newList = new LinkedList<T, append>();
    cloneNodes(head, newList);
    return newList;
}

// Recursive helper to print elements as a comma-separated list
template <class T>
void recursivePrint(std::ostream &out, Node<T>* node) {
    if (!node) return;
    out << node->data;
    if (node->next) out << ",";
    recursivePrint(out, node->next);
}

// Print elements as a comma-separated list
template <class T, bool append>
std::ostream& LinkedList<T, append>::printToStream(std::ostream &outStream) {
    recursivePrint(outStream, head);
    return outStream;
}

// Explicit instantiation for LinkedList<int, false> as required
template class LinkedList<int, false>;
