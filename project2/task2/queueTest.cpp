#include <iostream>
#include "OurQueue.h"

int main() {
    OurQueue<int> queue;

    std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;

    // Test push
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Front of queue after pushing 10, 20, 30: " << queue.peekFront() << std::endl;

    // Test pop
    queue.dequeue();
    std::cout << "Front of queue after one pop: " << queue.peekFront() << std::endl;

    // Clear the queue
    queue.dequeue();
    queue.dequeue();

    std::cout << "Is queue empty after popping all items? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;

    // Test front on an empty queue
    try {
        queue.peekFront();
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
