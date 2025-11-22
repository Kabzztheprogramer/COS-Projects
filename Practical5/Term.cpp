#include "Term.h"
#include <cstring>

// Utility function to manually copy arrays
void copyArray(char* dest, const char* src, int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

void copyArray(int* dest, const int* src, int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

// Utility function to manually sort arrays
void sortArray(char* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Default constructor
Term::Term() : coefficient(1), numVariables(0), variables(NULL), powers(NULL) {}

// Copy constructor
Term::Term(const Term& other) : coefficient(other.coefficient), numVariables(other.numVariables) {
    if (numVariables > 0) {
        variables = new char[numVariables];
        powers = new int[numVariables];
        copyArray(variables, other.variables, numVariables);
        copyArray(powers, other.powers, numVariables);
    } else {
        variables = NULL;
        powers = NULL;
    }
}

// Parameterized constructor
Term::Term(int coefficient, int numVariables, char* variables, int* powers) : coefficient(coefficient), numVariables(numVariables) {
    if (numVariables > 0) {
        this->variables = new char[numVariables];
        this->powers = new int[numVariables];
        copyArray(this->variables, variables, numVariables);
        copyArray(this->powers, powers, numVariables);
        sortArray(this->variables, numVariables);
    } else {
        this->variables = NULL;
        this->powers = NULL;
    }
}

// Destructor
Term::~Term() {
    delete[] variables;
    delete[] powers;
}

// Add variable with null checks
void Term::addVariable(char var, int pow) {
    if (coefficient == 0 || pow == 0) return;

    for (int i = 0; i < numVariables; i++) {
        if (variables[i] == var) {
            powers[i] += pow;
            return;
        }
    }

    char* newVariables = new char[numVariables + 1];
    int* newPowers = new int[numVariables + 1];
    
    if (variables != NULL) {
        copyArray(newVariables, variables, numVariables);
        copyArray(newPowers, powers, numVariables);
    }
    
    newVariables[numVariables] = var;
    newPowers[numVariables] = pow;

    delete[] variables;
    delete[] powers;
    
    variables = newVariables;
    powers = newPowers;
    numVariables++;
    sortArray(variables, numVariables);
}

// Remove variable with null checks
void Term::removeVariable(char var) {
    if (numVariables == 0) return;
    
    for (int i = 0; i < numVariables; i++) {
        if (variables[i] == var) {
            char* newVariables = new char[numVariables - 1];
            int* newPowers = new int[numVariables - 1];
            
            copyArray(newVariables, variables, i);
            copyArray(newPowers, powers, i);
            copyArray(newVariables + i, variables + i + 1, numVariables - i - 1);
            copyArray(newPowers + i, powers + i + 1, numVariables - i - 1);
            
            delete[] variables;
            delete[] powers;
            
            variables = newVariables;
            powers = newPowers;
            numVariables--;
            return;
        }
    }
}

int Term::getVarIndex(char var) const {
    for (int i = 0; i < numVariables; i++) {
        if (variables[i] == var) return i;
    }
    return -1;
}

// Operator overload for multiplication
Term Term::operator*(const Term& other) const {
    Term result;
    result.coefficient = coefficient * other.coefficient;

    for (int i = 0; i < numVariables; i++) {
        for (int j = 0; j < other.numVariables; j++) {
            char var = variables[i] > other.variables[j] ? variables[i] : other.variables[j];
            int pow = powers[i] + other.powers[j];
            result.addVariable(var, pow);
        }
    }

    return result;
}

Term& Term:: operator*=(const Term& other) {
    *this = *this * other;
    return *this;
}

bool Term::operator==(const Term& other)  {
    if (coefficient != other.coefficient) return false;
    if (numVariables != other.numVariables) return false;

    for (int i = 0; i < numVariables; i++) {
        if (variables[i] != other.variables[i] || powers[i] != other.powers[i]) {
            return false;
        }
    }
    return true;
}

bool Term::operator<(const Term& other)  {
    if (numVariables == 0) return false;
    if (other.numVariables == 0) return true;

    for (int i = 0; i < (numVariables < other.numVariables ? numVariables : other.numVariables); i++) {
        if (variables[i] != other.variables[i]) return variables[i] < other.variables[i];
        if (powers[i] != other.powers[i]) return powers[i] < other.powers[i];
    }
    return numVariables < other.numVariables;
}

bool Term::operator>(const Term& other) {
    return other < *this;
}
