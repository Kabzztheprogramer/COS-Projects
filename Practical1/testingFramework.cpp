#ifndef TESTING_FRAMEWORK_CPP
#define TESTING_FRAMEWORK_CPP

#include "testingFramework.h"

const string ANSI_RED = "\u001b[31;1m";
const string ANSI_GREEN = "\u001b[32;1m";
const string ANSI_BLUE = "\033[0;34m";
const string ANSI_RESET = "\u001b[0m";
int SUITES_RUN = 0;
int SUITES_PASSED = 0;
int TESTS_RUN = 0;
int TESTS_PASSED = 0;
int SECTION_NUM = 0;

int printMode = 0;
/*
Printmode
    0 -> Normal printing
    1 -> Test Passed/Failed
*/
void changePrintMode(int pMode) {
    printMode = pMode;
}

void assert(const int& expected, const int& received) {
    if (printMode == 1) {
        TESTS_RUN++;
        if (expected == received) {
            TESTS_PASSED++;
            cout << ANSI_GREEN << "Test " << TESTS_RUN << " Passed " << ANSI_RESET << endl;
        } else {
            cout << ANSI_RED << "Test " << TESTS_RUN << " Failed: Expected\n"
                 << expected << " but got\n"
                 << received << ANSI_RESET << endl;
        }
    } else {
        cout << received << endl;
    }
}

void assert(const std::string& expected, const std::string& received) {
    if (printMode == 1) {
        TESTS_RUN++;
        if (expected == received) {
            TESTS_PASSED++;
            cout << ANSI_GREEN << "Test " << TESTS_RUN << " Passed " << ANSI_RESET << endl;
        } else {
            cout << ANSI_RED << "Test " << TESTS_RUN << " Failed: Expected\n"
                 << expected << " but got\n"
                 << received << ANSI_RESET << endl;
        }
    } else {
        cout << received << endl;
    }
}

void assertArray(int* expected, int* received, int size) {
    TESTS_RUN++;
    bool equal = true;
    for (int i = 0; i < size; i++) {
        if (printMode == 1) {
            if (expected[i] != received[i]) {
                equal = false;
                cout << ANSI_RED << "Test " << TESTS_RUN << "." << i << " Failed: Expected " << expected[i] << " but got " << received[i] << ANSI_RESET << endl;
            }
        } else {
            if (i != 0) {
                cout << ",";
            }
            cout << received[i];
        }
    }
    if (equal) {
        TESTS_PASSED++;
        if (printMode == 1) {
            cout << ANSI_GREEN << "Test " << TESTS_RUN << " Passed " << ANSI_RESET << endl;
        }
    } else {
        if (printMode == 1) {
            cout << ANSI_RED << "Test " << TESTS_RUN << " Failed" << ANSI_RESET << endl;
        }
    }
    if (printMode != 1) {
        cout << endl;
    }
}

void assertNULL(int* received, bool isNULL) {
    if (printMode == 1) {
        TESTS_RUN++;
        if ((received && !isNULL) || (!received && isNULL)) {
            TESTS_PASSED++;
            cout << ANSI_GREEN << "Test " << TESTS_RUN << " Passed " << ANSI_RESET << endl;
        } else {
            cout << ANSI_RED << "Test " << TESTS_RUN << " Failed: Expected " << (isNULL ? "NULL" : "NOT NULL") << " but got " << (isNULL ? "NOT NULL" : "NULL") << ANSI_RESET << endl;
        }
    } else {
        cout << received << endl;
    }
}

void assertNULL(int** received, bool isNULL) {
    if (printMode == 1) {
        TESTS_RUN++;
        if ((received && !isNULL) || (!received && isNULL)) {
            TESTS_PASSED++;
            cout << ANSI_GREEN << "Test " << TESTS_RUN << " Passed " << ANSI_RESET << endl;
        } else {
            cout << ANSI_RED << "Test " << TESTS_RUN << " Failed: Expected " << (isNULL ? "NULL" : "NOT NULL") << " but got " << (isNULL ? "NOT NULL" : "NULL") << ANSI_RESET << endl;
        }
    } else {
        cout << received << endl;
    }
}

void startSuite(std::string taskName) {
    SUITES_RUN++;
    cout << "===================\nStarting: " << taskName << "\n===================" << endl;
}

void endSuite() {
    if (printMode == 1) {
        if (TESTS_RUN == TESTS_PASSED) {
            SUITES_PASSED++;
            cout << ANSI_GREEN + "All Tests Passed " + ANSI_RESET + "\n===================\n";
        } else {
            cout << ANSI_RED << "Tests Failed: " << (TESTS_RUN - TESTS_PASSED) << "\n===================\n" + ANSI_RESET;
        }
        TESTS_RUN = 0;
        TESTS_PASSED = 0;
    }
}

void startSection(std::string sectionName) {
    SECTION_NUM++;
    if (printMode == 1) {
        cout << ANSI_BLUE << "Starting Section " << SECTION_NUM << ": " << sectionName << ANSI_RESET << endl;
    } else {
        cout << "Starting Section " << SECTION_NUM << ": " << sectionName << endl;
    }
}

#endif