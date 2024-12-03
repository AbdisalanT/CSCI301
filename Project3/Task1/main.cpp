#include "LinkedDeque.h"
#include <iostream>
/*
@file Main.cpp
*/

int main() {
    LinkedDeque<int> deque;

    // Enqueue operations
    deque.enqueueFront(10);
    deque.enqueueBack(20);
    deque.enqueueFront(5);
    deque.enqueueBack(30);

    // Peek at the front and back
    std::cout << "Front: " << deque.peekFront() << std::endl; // 5
    std::cout << "Back: " << deque.peekBack() << std::endl;   // 30

    // Dequeue operations
    deque.dequeueFront(); // Removes 5
    deque.dequeueBack();  // Removes 30

    // Peek again
    std::cout << "Front: " << deque.peekFront() << std::endl; // 10
    std::cout << "Back: " << deque.peekBack() << std::endl;   // 20

    // Dequeue remaining
    deque.dequeueFront();
    deque.dequeueBack();

    // Check if empty
    std::cout << "Is empty: " << std::boolalpha << deque.isEmpty() << std::endl; // true

    return 0;
}
