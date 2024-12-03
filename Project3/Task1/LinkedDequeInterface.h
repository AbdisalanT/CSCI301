#ifndef LINKED_DEQUE_INTERFACE_
#define LINKED_DEQUE_INTERFACE_

/**
 * @file Linked_Deque_
  Interface for the LinkedDeque ADT. 
 */
template <class ItemType>
class LinkedDequeInterface {
public:
    /**
     * @brief Virtual destructor to allow proper cleanup of derived classes.
     */
    virtual ~LinkedDequeInterface() {}

    /**
     * @brief Check if the deque is empty.
     * @return True if the deque is empty, false otherwise.
     */
    virtual bool isEmpty() const = 0;

    /**
     * @brief Add an item to the front of the deque.
     * @param item The item to add.
     * @return True if the operation is successful, false otherwise.
     */
    virtual bool enqueueFront(const ItemType& item) = 0;

    /**
     * @brief Add an item to the back of the deque.
     * @param item The item to add.
     * @return True if the operation is successful, false otherwise.
     */
    virtual bool enqueueBack(const ItemType& item) = 0;

    /**
     * @brief Remove the item at the front of the deque.
     * @return True if the operation is successful, false otherwise.
     */
    virtual bool dequeueFront() = 0;

    /**
     * @brief Remove the item at the back of the deque.
     * @return True if the operation is successful, false otherwise.
     */
    virtual bool dequeueBack() = 0;

    /**
     * @brief Get the item at the front of the deque without removing it.
     * @return The item at the front of the deque.
     * @throws std::runtime_error if the deque is empty.
     */
    virtual ItemType peekFront() const = 0;

    /**
     * @brief Get the item at the back of the deque without removing it.
     * @return The item at the back of the deque.
     * @throws std::runtime_error if the deque is empty.
     */
    virtual ItemType peekBack() const = 0;
};

#endif // LINKED_DEQUE_INTERFACE_
