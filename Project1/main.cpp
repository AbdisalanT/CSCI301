#include "Polynomial.h"

int main() {
    Polynomial<double> p1;
    p1.addTerm(5, 3);
    p1.addTerm(1, 2);
    p1.addTerm(-1, 1);
    p1.addTerm(-7, 0);

    Polynomial<double> p2;
    p2.addTerm(3, 2);
    p2.addTerm(4, 1);

    std::cout << "P1(x): ";
    p1.display();

    std::cout << "P2(x): ";
    p2.display();

    // Test addition
    Polynomial<double> sum = p1.add(p2);
    std::cout << "P1(x) + P2(x): ";
    sum.display();

    // Test evaluation
    double x = 2.0;
    std::cout << "P1(" << x << ") = " << p1.evaluate(x) << std::endl;

    // Test scalar multiplication
    p1.scalarMultiply(2);
    std::cout << "2 * P1(x): ";
    p1.display();

    return 0;
}
