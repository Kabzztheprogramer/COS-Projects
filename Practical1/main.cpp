#include <cstdio>
#include <iostream>

#include "DynamicArrays.h"
#include "testingFramework.h"

using namespace std;

void createAndDestroyTest() {
    int** array = NULL;
    int* numColumns = NULL;
    int numRows = 0;
    startSuite("createAndDestroy");

    startSection("Blank String");
    createArray(array, numColumns, numRows, "");
    int numColumnsAns[] = {0};
    int row0Ans[] = {};
    assert(1, numRows);
    assertArray(numColumnsAns, numColumns, 1);
    assertArray(row0Ans, array[0], 0);
    destroyArray(array, numColumns, numRows);
    assertNULL(array);
    assertNULL(numColumns);
    assert(0, numRows);

    startSection("Easy example");
    createArray(array, numColumns, numRows, "1,2|3,4|5,6");
    int numColumnsAns2[] = {2, 2, 2};
    int row0Ans2[] = {1, 2}, row1Ans2[] = {3, 4}, row2Ans2[] = {5, 6};
    assert(3, numRows);
    assertArray(numColumnsAns2, numColumns, 3);
    assertArray(row0Ans2, array[0], 2);
    assertArray(row1Ans2, array[1], 2);
    assertArray(row2Ans2, array[2], 2);
    destroyArray(array, numColumns, numRows);
    assertNULL(array);
    assertNULL(numColumns);
    assert(0, numRows);

    endSuite();
}

void printTest() {
    int** array = NULL;
    int* numColumns = NULL;
    int numRows = 0;

    startSuite("print");

    startSection("Empty String");
    createArray(array, numColumns, numRows, "");
    assert("numRows : 1\nrow[0] : 0", printArrayStructure(array, numColumns, numRows));
    assert("", printArray(array, numColumns, numRows));
    destroyArray(array, numColumns, numRows);

    startSection("Easy Example");
    createArray(array, numColumns, numRows, "1,2|3,4|5,6");
    assert("numRows : 3\nrow[0] : 2\nrow[1] : 2\nrow[2] : 2", printArrayStructure(array, numColumns, numRows));
    assert("1,2\n3,4\n5,6", printArray(array, numColumns, numRows));
    destroyArray(array, numColumns, numRows);

    endSuite();
}

/*
Printmode
    0 -> Normal printing
    1 -> Test Passed/Failed
*/
int main(int argc, char* argv[]) {
    changePrintMode(1);
    createAndDestroyTest();
    printTest();
    return 0;
}