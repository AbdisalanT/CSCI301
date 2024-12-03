// Deque.h - Header file for Deque class
#ifndef _DEQUE
#define _DEQUE

#include <stdexcept>

/**
 * @brief A double-ended queue (deque) implementation.
 * @tparam ItemType The type of elements stored in the deque.
 */
template<class ItemType>
class Deque {
private:
    struct Node {
        ItemType item;   // Data stored in the node
        Node* next;      // Pointer to the next node
        Node* prev;      // Pointer to the previous node

        /**
         * @brief Constructs a Node with item and optional next/prev pointers.
         * @param anItem The data for the node.
         * @param nextNode Pointer to the next node in the deque.
         * @param prevNode Pointer to the previous node in the deque.
         */
        Node(const ItemType& anItem, Node* nextNode = nullptr, Node* prevNode = nullptr)
            : item(anItem), next(nextNode), prev(prevNode) {}
    };

    Node* frontPtr; // Pointer to the front of the deque
    Node* backPtr;  // Pointer to the back of the deque
    int itemCount;  // Number of items in the deque

public:
    // Constructor and Destructor
    Deque();
    ~Deque();

    // Deque operations
    bool isEmpty() const;
    int size() const;
    void pushFront(const ItemType& newItem);
    void pushBack(const ItemType& newItem);
    bool popFront();
    bool popBack();
    ItemType peekFront() const;
    ItemType peekBack() const;
};

#include "Deque.cpp"
#endif
