#ifndef LINKED_DEQUE_H
#define LINKED_DEQUE_H

#include <memory>
#include <stdexcept>
#include "DoubleLinkNode.h"
#include "LinkedDequeInterface.h"

/**
 * @file LinkedDeque.h
 * @brief LinkedDeque class definition, implements LinkedDequeInterface.
 */
template <typename ItemType>
class LinkedDeque : public LinkedDequeInterface<ItemType> {
private:
    std::shared_ptr<DoubleLinkNode<ItemType>> frontPtr;
    std::shared_ptr<DoubleLinkNode<ItemType>> backPtr;

public:
    LinkedDeque();
    ~LinkedDeque();

    bool isEmpty() const noexcept override;
    bool enqueueFront(const ItemType& someItem) override;
    bool enqueueBack(const ItemType& someItem) override;
    bool dequeueFront() noexcept override;
    bool dequeueBack() noexcept override;
    ItemType peekFront() const override;
    ItemType peekBack() const override;
};

#include "LinkedDeque.cpp" // Include implementation file for templates

#endif // LINKED_DEQUE_H
