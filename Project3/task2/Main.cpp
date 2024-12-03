#include <iostream>
#include "Deque.h"

int main() {
    Deque<int> deque;

    std::cout << "Initial deque size: " << deque.size() << "\n";

    // Push elements to the front and back
    deque.pushFront(10);
    deque.pushBack(20);
    deque.pushFront(5);
    deque.pushBack(25);

    std::cout << "Deque size after pushes: " << deque.size() << "\n";
    std::cout << "Front element: " << deque.peekFront() << "\n";
    std::cout << "Back element: " << deque.peekBack() << "\n";

    // Pop elements from the front and back
    deque.popFront();
    std::cout << "Deque size after popFront: " << deque.size() << "\n";
    std::cout << "Front element: " << deque.peekFront() << "\n";

    deque.popBack();
    std::cout << "Deque size after popBack: " << deque.size() << "\n";
    std::cout << "Back element: " << deque.peekBack() << "\n";

    // Check if deque is empty
    while (!deque.isEmpty()) {
        deque.popFront();
    }

    std::cout << "Deque size after clearing: " << deque.size() << "\n";
    std::cout << "Is deque empty? " << (deque.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}
