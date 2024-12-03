#include "LinkedDeque.h"

// Constructor
template <typename ItemType>
LinkedDeque<ItemType>::LinkedDeque() : frontPtr(nullptr), backPtr(nullptr) {}

// Destructor
template <typename ItemType>
LinkedDeque<ItemType>::~LinkedDeque() {
    while (!isEmpty()) {
        dequeueFront();
    }
}

// Check if the deque is empty
template <typename ItemType>
bool LinkedDeque<ItemType>::isEmpty() const noexcept {
    return frontPtr == nullptr;
}

// Add a new node to the front of the deque
template <typename ItemType>
bool LinkedDeque<ItemType>::enqueueFront(const ItemType& someItem) {
    auto newNode = std::make_shared<DoubleLinkNode<ItemType>>(someItem, backPtr, frontPtr);

    if (isEmpty()) {
        frontPtr = newNode;
        backPtr = newNode;
        frontPtr->next = frontPtr;
        frontPtr->previous = frontPtr;
    } else {
        frontPtr->previous = newNode;
        backPtr->next = newNode;
        frontPtr = newNode;
    }

    return true;
}

// Add a new node to the back of the deque
template <typename ItemType>
bool LinkedDeque<ItemType>::enqueueBack(const ItemType& someItem) {
    auto newNode = std::make_shared<DoubleLinkNode<ItemType>>(someItem, backPtr, frontPtr);

    if (isEmpty()) {
        frontPtr = newNode;
        backPtr = newNode;
        frontPtr->next = frontPtr;
        frontPtr->previous = frontPtr;
    } else {
        backPtr->next = newNode;
        frontPtr->previous = newNode;
        backPtr = newNode;
    }

    return true;
}

// Remove a node from the front of the deque
template <typename ItemType>
bool LinkedDeque<ItemType>::dequeueFront() noexcept {
    if (isEmpty()) {
        return false;
    }

    if (frontPtr == backPtr) {
        frontPtr.reset();
        backPtr.reset();
    } else {
        auto temp = frontPtr;
        frontPtr = frontPtr->next;
        backPtr->next = frontPtr;
        frontPtr->previous = backPtr;
        temp.reset();
    }

    return true;
}

// Remove a node from the back of the deque
template <typename ItemType>
bool LinkedDeque<ItemType>::dequeueBack() noexcept {
    if (isEmpty()) {
        return false;
    }

    if (frontPtr == backPtr) {
        frontPtr.reset();
        backPtr.reset();
    } else {
        auto temp = backPtr;
        backPtr = backPtr->previous;
        backPtr->next = frontPtr;
        frontPtr->previous = backPtr;
        temp.reset();
    }

    return true;
}

// Retrieve the front item
template <typename ItemType>
ItemType LinkedDeque<ItemType>::peekFront() const {
    if (isEmpty()) {
        throw std::runtime_error("Deque is empty");
    }
    return frontPtr->item;
}

// Retrieve the back item
template <typename ItemType>
ItemType LinkedDeque<ItemType>::peekBack() const {
    if (isEmpty()) {
        throw std::runtime_error("Deque is empty");
    }
    return backPtr->item;
}
