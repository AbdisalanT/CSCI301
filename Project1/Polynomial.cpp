#ifndef POLYNOMIAL_CPP
#define POLYNOMIAL_CPP

#include "Polynomial.h"

// Default constructor, uses 'X' as the indeterminate
template<class T>
Polynomial<T>::Polynomial() : head(nullptr), indeterminate('X') {}

// Constructor with a custom indeterminate (e.g., 'y')
template<class T>
Polynomial<T>::Polynomial(char var) : head(nullptr), indeterminate(var) {}

// Copy constructor (deep copy)
template<class T>
Polynomial<T>::Polynomial(const Polynomial<T>& other) : head(nullptr), indeterminate(other.indeterminate) {
    Node<std::pair<T, unsigned int>>* current = other.head;
    while (current) {
        addTerm(current->getItem().first, current->getItem().second);
        current = current->getNext();
    }
}

// Destructor to free memory
template<class T>
Polynomial<T>::~Polynomial() {
    clear();
}

// Clear the polynomial (delete all nodes)
template<class T>
void Polynomial<T>::clear() {
    while (head) {
        Node<std::pair<T, unsigned int>>* toDelete = head;
        head = head->getNext();
        delete toDelete;
    }
}

// Add a term (coefficient, power) to the polynomial
template<class T>
void Polynomial<T>::addTerm(T coefficient, unsigned int power) {
    if (coefficient == 0) {
        return;
    }

    std::pair<T, unsigned int> newTerm = std::make_pair(coefficient, power);

    if (!head || head->getItem().second < power) {
        head = new Node<std::pair<T, unsigned int>>(newTerm, head);
        return;
    }

    Node<std::pair<T, unsigned int>>* current = head;
    Node<std::pair<T, unsigned int>>* previous = nullptr;

    while (current && current->getItem().second > power) {
        previous = current;
        current = current->getNext();
    }

    if (current && current->getItem().second == power) {
        current->setItem(std::make_pair(current->getItem().first + coefficient, power));
    } else {
        Node<std::pair<T, unsigned int>>* newNode = new Node<std::pair<T, unsigned int>>(newTerm);
        if (previous) {
            previous->setNext(newNode);
        }
        newNode->setNext(current);
    }
}

// Multiply the polynomial by a scalar
template<class T>
void Polynomial<T>::scalarMultiply(T scalar) {
    Node<std::pair<T, unsigned int>>* current = head;
    while (current) {
        current->setItem(std::make_pair(current->getItem().first * scalar, current->getItem().second));
        current = current->getNext();
    }
}

// Evaluate the polynomial for a given value of x
template<class T>
T Polynomial<T>::evaluate(T x) const {
    T result = 0;
    Node<std::pair<T, unsigned int>>* current = head;
    while (current) {
        result += current->getItem().first * std::pow(x, current->getItem().second);
        current = current->getNext();
    }
    return result;
}

// Sum two polynomials (this + other)
template<class T>
Polynomial<T> Polynomial<T>::add(const Polynomial<T>& other) const {
    Polynomial<T> result(indeterminate);

    Node<std::pair<T, unsigned int>>* current = head;
    while (current) {
        result.addTerm(current->getItem().first, current->getItem().second);
        current = current->getNext();
    }

    current = other.head;
    while (current) {
        result.addTerm(current->getItem().first, current->getItem().second);
        current = current->getNext();
    }

    return result;
}

// Display the polynomial in the specified format
template<class T>
void Polynomial<T>::display() const {
    Node<std::pair<T, unsigned int>>* current = head;
    bool first = true;

    while (current) {
        T coefficient = current->getItem().first;
        unsigned int power = current->getItem().second;

        if (coefficient != 1 && coefficient != -1) {
            if (!first && coefficient > 0) {
                std::cout << " + ";
            } else if (coefficient < 0 && !first) {
                std::cout << " ";
            }
            std::cout << "(" << coefficient << ")";
        } else {
            if (coefficient == -1) {
                std::cout << "(-1)";
            } else if (first || power == 0) {
                std::cout << "(" << coefficient << ")";
            }
        }

        if (power == 0) {
            if (coefficient == 1) std::cout << "(1)";
        } else if (power == 1) {
            std::cout << indeterminate;
        } else {
            std::cout << indeterminate << "^" << power;
        }

        current = current->getNext();
        first = false;
    }

    std::cout << std::endl;
}

#endif
