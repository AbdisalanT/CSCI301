#ifndef _OUR_QUEUE
#define _OUR_QUEUE

#include <queue>             // STL queue
#include "QueueInterface.h"  // Queue interface for our queue class

/**
 * A class that implements a queue using the Standard Template Library (STL) queue.
 * This class derives from QueueInterface and provides basic queue operations.
 *
 * @tparam ItemType The type of elements held in the queue
 */
template <class ItemType>
class OurQueue : public QueueInterface<ItemType> {
private:
    std::queue<ItemType> queue;  // Internal STL queue to manage items

public:
    /**
     * Default constructor.
     */
    OurQueue();

    /**
     * Checks whether the queue is empty.
     *
     * @return True if the queue is empty, false otherwise
     */
    bool isEmpty() const override;

    /**
     * Adds an item to the back of the queue.
     *
     * @param newEntry The item to add to the queue
     * @return True after adding the item
     */
    bool enqueue(const ItemType& newEntry) override;

    /**
     * Removes the front item from the queue.
     *
     * @return True if the item was successfully removed, false if the queue was empty
     */
    bool dequeue() override;

    /**
     * Returns the front item in the queue without removing it.
     *
     * @pre The queue is not empty.
     * @return The front item in the queue
     * @throws std::runtime_error if the queue is empty
     */
    ItemType peekFront() const override;
};

#include "OurQueue.cpp"  // Include implementation file for templates

#endif
