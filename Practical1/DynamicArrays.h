#ifndef DYNAMICARRAYS_H
#define DYNAMICARRAYS_H

#include <sstream>
#include <string>

void createArray(int**& array, int*& numColumns, int& numRows, std::string input);
void destroyArray(int**& array, int*& numColumns, int& numRows);
std::string printArrayStructure(int**& array, int*& numColumns, int& numRows);
std::string printArray(int**& array, int*& numColumns, int& numRows);
void addRow(int**& array, int*& numColumns, int& numRows);
void addValueToRow(int**& array, int*& numColumns, int& numRows, int rowNumber, int value);
void removeRow(int**& array, int*& numColumns, int& numRows, int rowNumber);
void removeValueFromRow(int**& array, int*& numColumns, int& numRows, int rowNumber, int value);
int rowSum(int**& array, int*& numColumns, int& numRows, int rowNumber);
float rowAvg(int**& array, int*& numColumns, int& numRows, int rowNumber);
int rowMax(int**& array, int*& numColumns, int& numRows, int rowNumber);
int rowMin(int**& array, int*& numColumns, int& numRows, int rowNumber);

#endif