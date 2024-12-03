#include "DoubleLinkNode.h"
/*
@file DoubleLinkNode.cpp
*/
// Constructor for DoubleLinkNode
template <typename ItemType>
DoubleLinkNode<ItemType>::DoubleLinkNode(const ItemType& anItem, 
                                         std::shared_ptr<DoubleLinkNode<ItemType>> prev, 
                                         std::shared_ptr<DoubleLinkNode<ItemType>> nextNode)
    : item(anItem), previous(prev), next(nextNode) {}
