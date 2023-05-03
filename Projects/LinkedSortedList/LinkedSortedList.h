//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Listing 12-2

/** ADT sorted list: Link-based implementation.
 @file LinkedSortedList.h */

#ifndef _LINKED_SORTED_LIST
#define _LINKED_SORTED_LIST

#include <cassert>
#include "SortedListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"
#include <iostream>
using namespace std;
template<class ItemType>
class LinkedSortedList : public SortedListInterface<ItemType>
{
    private:
        Node<ItemType>* headPtr; // Pointer to first node in the chain
        int itemCount;           // Current count of list items
        
        // Locates the node that is before the node that should or does
        // contain the given entry.
        // @param anEntry  The entry to find.
        // @return  Either a pointer to the node before the node that contains
        //    or should contain the given entry, or nullptr if no prior node exists.
        Node<ItemType>* getNodeBefore(const ItemType& anEntry) const;
        
        // Locates the node at a given position within the chain.
        Node<ItemType>* getNodeAt(int position) const;
        
        // Returns a pointer to a copy of the chain to which origChainPtr points.
        Node<ItemType>* copyChain(const Node<ItemType>* origChainPtr);
        Node<ItemType>* getPointerTo(const ItemType &anEntry) const;
    public:
        LinkedSortedList();
        LinkedSortedList(const LinkedSortedList<ItemType>& aList);
        virtual ~LinkedSortedList();   

        void insertSorted(const ItemType& newEntry);
        bool removeSorted(const ItemType& anEntry);
        int getPosition(const ItemType &anEntry);
        
        // The following methods are the same as given in ListInterface:
        bool isEmpty() const;
        int getLength() const;
        bool remove(int position);
        bool remove1(const ItemType &anEntry);
        void clear();
        ItemType getEntry(int position) const;
        void display() const;
}; // end LinkedSortedList

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// PARITALLY COMPLETE.


/** Implementation file for the class LinkedSortedList.
 @file LinkedSortedList.cpp */
  

template <class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList() : itemCount(0), headPtr(nullptr)
{
}
template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& aList)
{
	headPtr = copyChain(aList.headPtr);
}  // end copy constructor

template<class ItemType>
void LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry)
{
   Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
   Node<ItemType>* prevPtr = getNodeBefore(newEntry);
   
   if (isEmpty() || (prevPtr == nullptr)) // Add at beginning
   {
      newNodePtr->setNext(headPtr);
      headPtr = newNodePtr;
   }
   else // Add after node before
   {
      Node<ItemType>* aftPtr = prevPtr->getNext();
      newNodePtr->setNext(aftPtr);
      prevPtr->setNext(newNodePtr);
   } // end if
   
   itemCount++;
} // end insertSorted

template <class ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType &anEntry)
{
    bool ableToRemove = false;
    if(!isEmpty())
    {
        int position = getPosition(anEntry);
        ableToRemove = position > 0;
        if (ableToRemove)
        {
            ableToRemove = remove(position);
        }
    }
    return ableToRemove;
}

template<class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList()
{
    clear();
}
// Private Methods:

template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::copyChain(const Node<ItemType>* origChainPtr)
{
   Node<ItemType>* copiedChainPtr;
	if (origChainPtr == nullptr)
	{
      copiedChainPtr = nullptr;
   }
   else
   {
		// Build new chain from given one
		copiedChainPtr = new Node<ItemType>(origChainPtr->getItem());
		copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
	}  // end if
   
	return copiedChainPtr;
}  // end copyChain

template <class ItemType>
Node<ItemType> *LinkedSortedList<ItemType>::getPointerTo(const ItemType &anEntry) const
{
    bool found = false;
    Node<ItemType> *curPtr = headPtr;
    while (!found && (curPtr != nullptr))
    {
        if(anEntry == curPtr->getItem())
            found = true;
        else    
            curPtr = curPtr->getNext();
    }
    return curPtr;
}

template<class ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const
{
   Node<ItemType>* curPtr = headPtr;
   Node<ItemType>* prevPtr = nullptr;
   
   while ( (curPtr != nullptr) && (anEntry < curPtr->getItem()))
   {
      prevPtr = curPtr;
      curPtr = curPtr->getNext();
   } // end while
   
   return prevPtr;
} // end getNodeBefore

template <class ItemType>
Node<ItemType> *LinkedSortedList<ItemType>::getNodeAt(int position) const
{
    assert((position >= 1) && (position <= itemCount));
    Node<ItemType>* curPtr = headPtr;
    for(int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();
    return curPtr;
}

template<class ItemType>
int LinkedSortedList<ItemType>::getLength() const 
{
    return itemCount;
}
template<class ItemType>
bool LinkedSortedList<ItemType>::remove1(const ItemType &anEntry)
{
    Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
    if(canRemoveItem)
    {
        entryNodePtr->setItem(headPtr->getItem());
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        itemCount--;
    }
    return canRemoveItem;
}
template<class ItemType>
void LinkedSortedList<ItemType>::display() const
{   
    Node<ItemType>* currPtr = headPtr;
    while(currPtr != nullptr)
    {
        cout << currPtr->getItem() << endl;
        currPtr = currPtr->getNext();
    }
}

template <class ItemType>
bool LinkedSortedList<ItemType>::remove(int position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        Node<ItemType>* curPtr = nullptr;
        if (position == 1)
        {
            curPtr = headPtr;
            headPtr = headPtr->getNext();
        }
        else
        {
            Node<ItemType>* prevPtr = getNodeAt(position - 1);
            curPtr = prevPtr->getNext();
            prevPtr->setNext(curPtr->getNext());
        }
        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;
        itemCount--;
    }
    return ableToRemove;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template<class ItemType>
void LinkedSortedList<ItemType>::clear()
{
    while (!isEmpty())
        remove(1);
}

template <class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const
{
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if(ableToGet)
    {
        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else{
        string message = "getEntry called with an empty list or invalid position.";
        throw(PrecondViolatedExcep(message));
    }
}

template<class ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType & anEntry)
{
    int position = 1;
    int length = LinkedSortedList<ItemType>::getLength();

    while ((position <= length) && (anEntry != LinkedSortedList<ItemType>::getEntry(position)))
    {
        position++;
    }
    if ((position >length) || (anEntry != LinkedSortedList<ItemType>::getEntry(position)))
    {
        position = -position;
    }
    return position;
}

#endif