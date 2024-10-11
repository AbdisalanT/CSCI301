#include "Polynomial.h"

int main() {
    // Create a polynomial P(x) = 5x^3 + x^2 - x - 7
    Polynomial<double> p;
    p.addTerm(5, 3);
    p.addTerm(1, 2);
    p.addTerm(-1, 1);
    p.addTerm(-7, 0);

    // Display the polynomial
    std::cout << "P(x) = ";
    p.display();  // Output: (5)X^3 + X^2 + (-1)X + (-7)

    // Evaluate the polynomial at x = 2
    double value = 2;
    std::cout << "P(" << value << ") = " << p.evaluate(value) << std::endl;

    // Multiply the polynomial by a scalar
    p.scalarMultiply(2);
    std::cout << "After multiplying by 2, P(x) = ";
    p.display();  // Output: (10)X^3 + (2)X^2 + (-2)X + (-14)

    return 0;
}
