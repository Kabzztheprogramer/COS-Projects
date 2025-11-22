#ifndef TERM_H
#define TERM_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Term {
    private:

    int  coefficient;
    int  numVariables;
    char *variables;
    int  *powers;

    public:
    Term();
    Term(const Term& other);
    Term(int coefficient,int  numVariables, char *variable, int *powers);
    ~Term();

    void addVariable(char var , int pow);
    void removeVariable(char var);
    int getVarIndex(char var);
    Term& operator=(const Term&  other);
    friend  ostream& operator<<(ostream& os, const Term& term);
    Term operator*(const Term&  other);
    Term operator*=(const Term&  other);
    Term& operator==(const Term&   other);
    bool operator<(const Term&);
    int& operator[](int idx);
    Term operator!() const ;
    bool operator>(const Term &other) ;
};

#endif