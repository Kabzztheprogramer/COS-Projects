#include "Polynomial.h"
#include "Term.h"
#include <iostream>

Polynomial::Polynomial() : numTerms(0), terms(NULL) {}

Polynomial::Polynomial(const Polynomial& other) : numTerms(other.numTerms) {
    if (numTerms > 0) {
        terms = new Term*[numTerms];
        for (int i = 0; i < numTerms; i++) {
            terms[i] = new Term(*other.terms[i]);
        }
    } else {
        terms = NULL;
    }
}

Polynomial::~Polynomial() {
    for (int i = 0; i < numTerms; i++) {
        delete terms[i];
    }
    delete[] terms;
}

void Polynomial::addOrRemoveTerm(Term term) {
    if (term.getCoefficient() == 0) return;

    int index = termIndex(term);
    if (index != -1) {
        // If the term already exists, add the coefficients or modify variables
        *terms[index] *= term;  // Combine the terms by multiplying
    } else {
        // Otherwise, create a new term and add it
        Term** newTerms = new Term*[numTerms + 1];
        if (terms != NULL) {
            for (int i = 0; i < numTerms; i++) {
                newTerms[i] = terms[i];
            }
        }
        newTerms[numTerms] = new Term(term);
        delete[] terms;
        terms = newTerms;
        numTerms++;
        sortTerms();
    }
}

int Polynomial::termIndex(Term term) const {
    for (int i = 0; i < numTerms; i++) {
        if (*terms[i] == term) return i;
    }
    return -1;
}

// Sort the terms array using the overloaded < operator in Term
void Polynomial::sortTerms() {
    for (int i = 0; i < numTerms - 1; i++) {
        for (int j = i + 1; j < numTerms; j++) {
            if (*terms[i] < *terms[j]) {
                Term* temp = terms[i];
                terms[i] = terms[j];
                terms[j] = temp;
            }
        }
    }
}

Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        // Delete existing terms
        for (int i = 0; i < numTerms; i++) {
            delete terms[i];
        }
        delete[] terms;

        // Copy new terms
        numTerms = other.numTerms;
        terms = new Term*[numTerms];
        for (int i = 0; i < numTerms; i++) {
            terms[i] = new Term(*other.terms[i]);
        }
    }
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    Polynomial result(*this);
    for (int i = 0; i < other.numTerms; i++) {
        result.addOrRemoveTerm(*other.terms[i]);
    }
    return result;
}

Polynomial& Polynomial::operator+=(const Polynomial& other) {
    for (int i = 0; i < other.numTerms; i++) {
        addOrRemoveTerm(*other.terms[i]);
    }
    return *this;
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    Polynomial result(*this);
    for (int i = 0; i < other.numTerms; i++) {
        Term negTerm = *other.terms[i];
        negTerm.setCoefficient(-negTerm.getCoefficient());
        result.addOrRemoveTerm(negTerm);
    }
    return result;
}

Polynomial& Polynomial::operator-=(const Polynomial& other) {
    for (int i = 0; i < other.numTerms; i++) {
        Term negTerm = *other.terms[i];
        negTerm.setCoefficient(-negTerm.getCoefficient());
        addOrRemoveTerm(negTerm);
    }
    return *this;
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    Polynomial result;
    for (int i = 0; i < numTerms; i++) {
        for (int j = 0; j < other.numTerms; j++) {
            result.addOrRemoveTerm(*terms[i] * *other.terms[j]);
        }
    }
    return result;
}

Polynomial& Polynomial::operator*=(const Polynomial& other) {
    Polynomial result = (*this) * other;
    *this = result;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& polynomial) {
    if (polynomial.numTerms == 0) {
        os << "+0";
    } else {
        for (int i = 0; i < polynomial.numTerms; i++) {
            os << *polynomial.terms[i];
            if (i < polynomial.numTerms - 1) {
                os << "+";
            }
        }
    }
    return os;
}
