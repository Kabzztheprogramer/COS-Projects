#ifndef TESTING_FRAMEWORK_H
#define TESTING_FRAMEWORK_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void changePrintMode(int pMode);
void assert(const int& expected, const int& received);
void assert(const string& expected, const string& received);
void assertArray(int* expected, int* received, int size);
void assertNULL(int* received, bool isNULL = true);
void assertNULL(int** received, bool isNULL = true);
void startSuite(string taskName = "Unnamed task");
void endSuite();
void startSection(string sectionName = "Unnamed section");

#endif