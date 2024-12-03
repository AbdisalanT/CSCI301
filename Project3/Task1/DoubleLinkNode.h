#ifndef DOUBLE_LINK_NODE_H
#define DOUBLE_LINK_NODE_H

#include <memory>

/**
 @file DoubleLinkNode.h
 */
template <typename ItemType>
class DoubleLinkNode {
public:
    ItemType item;
    std::shared_ptr<DoubleLinkNode<ItemType>> next;
    std::shared_ptr<DoubleLinkNode<ItemType>> previous;

    DoubleLinkNode(const ItemType& anItem, 
                   std::shared_ptr<DoubleLinkNode<ItemType>> prev = nullptr, 
                   std::shared_ptr<DoubleLinkNode<ItemType>> nextNode = nullptr);
};

#include "DoubleLinkNode.cpp" // Include implementation file for templates

#endif // DOUBLE_LINK_NODE_H
