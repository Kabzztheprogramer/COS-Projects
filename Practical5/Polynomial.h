#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <sstream>
#include <string>

#include "Term.h"

using namespace std;

class Polynomial {
    private:
    int numTerms;
    Term** terms;

    void sortTerms();

public:
    Polynomial();
    Polynomial(const Polynomial& other);
    Polynomial(Term** terms, int numTerms);
    ~Polynomial();

    void addOrRemoveTerm(Term term);
    int termIndex(Term term) const;

    Polynomial& operator=(const Polynomial& other);
    friend ostream& operator<<(ostream& os, const Polynomial& polynomial);

    Polynomial operator+(const Polynomial& other) const;
    Polynomial& operator+=(const Polynomial& other);

    Polynomial operator-(const Polynomial& other) const;
    Polynomial& operator-=(const Polynomial& other);

    Polynomial operator*(const Polynomial& other) const;
    Polynomial& operator*=(const Polynomial& other);
};
#endif