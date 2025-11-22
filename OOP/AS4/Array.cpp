#include "Array.h"
#include "Exceptions.h"
#include <sstream>

// Constructor
template <class T, bool append>
Array<T, append>::Array() : array(nullptr), size(0) {}

// Destructor
template <class T, bool append>
Array<T, append>::~Array() {
    delete[] array;
}

// Helper function to recursively copy elements
template <typename T>
void recursiveCopy(T* source, T* dest, int currentIndex, int maxIndex) {
    if (currentIndex >= maxIndex) return;
    dest[currentIndex] = source[currentIndex];
    recursiveCopy(source, dest, currentIndex + 1, maxIndex);
}

// Helper function to shift elements to the right recursively
template <typename T>
void recursiveShiftRight(T* array, int currentIndex) {
    if (currentIndex <= 0) return;
    array[currentIndex] = array[currentIndex - 1];
    recursiveShiftRight(array, currentIndex - 1);
}

// Overloaded operator+= for adding a single element
template <class T, bool append>
DataStructure<T, append>& Array<T, append>::operator+=(T &data) {
    T* newArray = new T[size + 1];
    recursiveCopy(array, newArray, 0, size);

    if (append) {
        newArray[size] = data;  // Add to the end
    } else {
        recursiveShiftRight(newArray, size);  // Shift elements right to add at the beginning
        newArray[0] = data;  // Add to the beginning
    }

    delete[] array;
    array = newArray;
    ++size;

    return *this;
}

// Helper to recursively add elements from another DataStructure
template <class T, bool append>
void copyFromDataStructure(const DataStructure<T, append>& other, int otherSize, int currentIndex) {
    if (currentIndex >= otherSize) return;
    *this += other[currentIndex];  // Recursively add each element
    copyFromDataStructure(other, otherSize, currentIndex + 1);
}

// Overloaded operator+= for adding another DataStructure
template <class T, bool append>
DataStructure<T, append>& Array<T, append>::operator+=(DataStructure<T, append> &other) {
    int otherSize = other.getSize();
    copyFromDataStructure(other, otherSize, 0);
    return *this;
}

// Overloaded subscript operator for accessing elements
template <class T, bool append>
T& Array<T, append>::operator[](int position) {
    if (position < 0 || position >= size) {
        throw IndexOutOfBoundsException(position, size - 1);
    }
    return array[position];
}

// Get the size of the array
template <class T, bool append>
int Array<T, append>::getSize() {
    return size;
}

// Recursive helper for copying elements to new array
template <typename T>
void recursiveToArrayCopy(T* source, T* dest, int currentIndex, int maxIndex) {
    if (currentIndex >= maxIndex) return;
    dest[currentIndex] = source[currentIndex];
    recursiveToArrayCopy(source, dest, currentIndex + 1, maxIndex);
}

// Convert array elements to a dynamic array
template <class T, bool append>
T* Array<T, append>::toArray() {
    T* newArray = new T[size];
    recursiveToArrayCopy(array, newArray, 0, size);
    return newArray;
}

// Helper function to clone recursively
template <class T, bool append>
void cloneHelper(Array<T, append>* destArray, int index) {
    if (index >= size) return;
    *destArray += array[index];
    cloneHelper(destArray, index + 1);
}

// Clone the current array (deep copy)
template <class T, bool append>
DataStructure<T, append>* Array<T, append>::clone() {
    Array<T, append>* newArray = new Array<T, append>();
    cloneHelper(newArray, 0);
    return newArray;
}

// Recursive helper for printing elements as a comma-separated list
template <typename T>
void recursivePrint(std::ostream &out, T* array, int currentIndex, int maxIndex) {
    if (currentIndex >= maxIndex) return;
    out << array[currentIndex];
    if (currentIndex < maxIndex - 1) out << ",";
    recursivePrint(out, array, currentIndex + 1, maxIndex);
}

// Print elements as a comma-separated list
template <class T, bool append>
std::ostream& Array<T, append>::printToStream(std::ostream &outStream) {
    recursivePrint(outStream, array, 0, size);
    return outStream;
}

// Explicit instantiation for Array<int, false> as required
template class Array<int, false>;
