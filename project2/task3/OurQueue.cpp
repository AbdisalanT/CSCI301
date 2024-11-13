#include "OurQueue.h"
#include <stdexcept>  // For std::runtime_error

template <class ItemType>
OurQueue<ItemType>::OurQueue() = default;

template <class ItemType>
bool OurQueue<ItemType>::isEmpty() const {
    return queue.empty();  // Calls STL queue's empty() method
}

template <class ItemType>
bool OurQueue<ItemType>::enqueue(const ItemType& newEntry) {
    queue.push(newEntry);  // Calls STL queue's push() method
    return true;
}

template <class ItemType>
bool OurQueue<ItemType>::dequeue() {
    if (isEmpty()) {
        return false;  // Cannot dequeue from an empty queue
    }
    queue.pop();  // Calls STL queue's pop() method
    return true;
}

template <class ItemType>
ItemType OurQueue<ItemType>::peekFront() const {
    if (isEmpty()) {
        throw std::runtime_error("peekFront() called on empty queue");
    }
    return queue.front();  // Calls STL queue's front() method
}
