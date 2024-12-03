// Deque.cpp - Implementation file for Deque class
#include "Deque.h"
#include <cassert>

/**
 * @brief Default constructor initializes an empty deque.
 */
template<class ItemType>
Deque<ItemType>::Deque() : frontPtr(nullptr), backPtr(nullptr), itemCount(0) {}

/**
 * @brief Destructor deallocates all dynamically allocated nodes.
 */
template<class ItemType>
Deque<ItemType>::~Deque() {
    while (!isEmpty()) {
        popFront();
    }
}

/**
 * @brief Checks whether the deque is empty.
 * @return True if the deque is empty, otherwise false.
 */
template<class ItemType>
bool Deque<ItemType>::isEmpty() const {
    return itemCount == 0;
}

/**
 * @brief Returns the number of items in the deque.
 * @return The size of the deque.
 */
template<class ItemType>
int Deque<ItemType>::size() const {
    return itemCount;
}

/**
 * @brief Adds a new item to the front of the deque.
 * @param newItem The item to add.
 */
template<class ItemType>
void Deque<ItemType>::pushFront(const ItemType& newItem) {
    Node* newNode = new Node(newItem, frontPtr, nullptr);
    if (isEmpty()) {
        backPtr = newNode;
    } else {
        frontPtr->prev = newNode;
    }
    frontPtr = newNode;
    itemCount++;
}

/**
 * @brief Adds a new item to the back of the deque.
 * @param newItem The item to add.
 */
template<class ItemType>
void Deque<ItemType>::pushBack(const ItemType& newItem) {
    Node* newNode = new Node(newItem, nullptr, backPtr);
    if (isEmpty()) {
        frontPtr = newNode;
    } else {
        backPtr->next = newNode;
    }
    backPtr = newNode;
    itemCount++;
}

/**
 * @brief Removes the front item from the deque.
 * @return True if the operation was successful, otherwise false.
 */
template<class ItemType>
bool Deque<ItemType>::popFront() {
    if (isEmpty()) {
        return false;
    }
    Node* nodeToDelete = frontPtr;
    frontPtr = frontPtr->next;
    if (frontPtr == nullptr) {
        backPtr = nullptr; // Deque is now empty
    } else {
        frontPtr->prev = nullptr;
    }
    delete nodeToDelete;
    itemCount--;
    return true;
}

/**
 * @brief Removes the back item from the deque.
 * @return True if the operation was successful, otherwise false.
 */
template<class ItemType>
bool Deque<ItemType>::popBack() {
    if (isEmpty()) {
        return false;
    }
    Node* nodeToDelete = backPtr;
    backPtr = backPtr->prev;
    if (backPtr == nullptr) {
        frontPtr = nullptr; // Deque is now empty
    } else {
        backPtr->next = nullptr;
    }
    delete nodeToDelete;
    itemCount--;
    return true;
}

/**
 * @brief Retrieves the item at the front of the deque.
 * @return The item at the front.
 * @throw std::runtime_error If the deque is empty.
 */
template<class ItemType>
ItemType Deque<ItemType>::peekFront() const {
    if (isEmpty()) {
        throw std::runtime_error("peekFront() called on empty deque.");
    }
    return frontPtr->item;
}

/**
 * @brief Retrieves the item at the back of the deque.
 * @return The item at the back.
 * @throw std::runtime_error If the deque is empty.
 */
template<class ItemType>
ItemType Deque<ItemType>::peekBack() const {
    if (isEmpty()) {
        throw std::runtime_error("peekBack() called on empty deque.");
    }
    return backPtr->item;
}

// End of implementation file.
