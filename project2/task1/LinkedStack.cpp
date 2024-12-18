//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file LinkedStack.cpp */

#include <cassert>        // For assert
#include "LinkedStack.h"  // Stack class specification file

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(NULL)
{
}  // end default constructor

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack)
{
   // Point to nodes in original chain
   Node<ItemType>* origChainPtr = aStack.topPtr;
   
   if (origChainPtr == NULL)
      topPtr = NULL;  // Original stack is empty
   else
   {
      // Copy first node
      topPtr = new Node<ItemType>();
      topPtr->setItem(origChainPtr->getItem());
      
      // Point to last node in new chain
      Node<ItemType>* newChainPtr = topPtr;
      
      // Advance original-chain pointer
      origChainPtr = origChainPtr->getNext();
      
      // Copy remaining nodes
      while (origChainPtr != NULL)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
         
      newChainPtr->setNext(NULL);               // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
	// Pop until stack is empty
	while (!isEmpty())
		pop();
}  // end destructor

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
	return topPtr == NULL;
}  // end isEmpty

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry) 
{
   Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry, topPtr);	
   topPtr = newNodePtr;
   newNodePtr = NULL;
   
	return true;
}  // end push

template<class ItemType>
bool LinkedStack<ItemType>::pop()
{
	bool result = false;
	if (!isEmpty())
	{
      // Stack is not empty; delete top
		Node<ItemType>* nodeToDeletePtr = topPtr;
		topPtr = topPtr->getNext();
		
		// Return deleted node to system
      nodeToDeletePtr->setNext(NULL);
		delete nodeToDeletePtr;
      nodeToDeletePtr = NULL;
      
      result = true;
	}  // end if
   
	return result;	
}  // end pop

template <class ItemType>
ItemType LinkedStack<ItemType>::peek() const {
    if (isEmpty()) {
        throw PrecondViolatedExcep("peek() called with empty stack.");
    }
    return topPtr->getItem();
}



// End of implementation file.