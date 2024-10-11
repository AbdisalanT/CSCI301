#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <cmath>   // For pow
#include <utility> // For std::pair
#include "Node.h"  // Assuming your Node class is in a separate file

// Polynomial Class Template
template<class T>
class Polynomial {
private:
    Node<std::pair<T, unsigned int>>* head;  // Linked list of terms (coeff, power)
    char indeterminate;                      // Variable for the polynomial (e.g., 'X')

public:
    // Default constructor, uses 'X' as the indeterminate
    Polynomial();

    // Constructor with a custom indeterminate (e.g., 'y')
    Polynomial(char var);

    // Copy constructor (deep copy)
    Polynomial(const Polynomial<T>& other);

    // Destructor to free memory
    ~Polynomial();

    // Clear the polynomial (delete all nodes)
    void clear();

    // Add a term (coefficient, power) to the polynomial
    void addTerm(T coefficient, unsigned int power);

    // Multiply the polynomial by a scalar
    void scalarMultiply(T scalar);

    // Evaluate the polynomial for a given value of x
    T evaluate(T x) const;

    // Sum two polynomials (this + other)
    Polynomial<T> add(const Polynomial<T>& other) const;

    // Display the polynomial in the specified format
    void display() const;
};

#include "Polynomial.cpp" // Include the implementation here

#endif
