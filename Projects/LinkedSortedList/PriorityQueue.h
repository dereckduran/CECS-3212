//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT priority queue: ADT sorted list implementation.
 Listing 14-6.
 @file SL_PriorityQueue.h */

#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE

#include "PriorityQueueInterface.h"
#include "LinkedSortedList.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class SL_PriorityQueue : public PriorityQueueInterface<ItemType>
{
private:
   LinkedSortedList<ItemType>* slistPtr;  // Pointer to sorted list of
                                          // items in the priority queue
   LinkedSortedList<ItemType>* copyChain(const LinkedSortedList<ItemType>* origChainPtr);
public:
   SL_PriorityQueue();
   SL_PriorityQueue(const SL_PriorityQueue& pq);
   ~SL_PriorityQueue();

   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove();

   /** @throw PrecondViolatedExcep if priority queue is empty. */
   ItemType peek() const;
   void display() const;
}; // end SL_PriorityQueue

template<class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue()
{
   slistPtr = new LinkedSortedList<ItemType>();
}

template <class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue(const SL_PriorityQueue<ItemType> &pq)
{
   slistPtr = copyChain(pq->listPtr);
}
template<class ItemType>
SL_PriorityQueue<ItemType>::~SL_PriorityQueue()
{
}
template<class ItemType>
bool SL_PriorityQueue<ItemType>::isEmpty() const 
{
   return slistPtr->getLength() == 0;
}

template<class ItemType>
bool SL_PriorityQueue<ItemType>::add(const ItemType &newEntry)
{
   slistPtr->insertSorted(newEntry);
   return true;
}

template<class ItemType>
bool SL_PriorityQueue<ItemType>::remove()
{
   return slistPtr->remove(slistPtr->getLength());
}

template<class ItemType>
ItemType SL_PriorityQueue<ItemType>::peek() const
{
   int position = slistPtr->getLength();
   if (isEmpty())
      throw(PrecondViolatedExcep("The list is empty...\n"));
   else 
      return slistPtr->getEntry(position);
}

template<class ItemType>
LinkedSortedList<ItemType>* SL_PriorityQueue<ItemType>::copyChain(const LinkedSortedList<ItemType>* origChainPtr)
{
   LinkedSortedList<ItemType>* copiedChainPtr; 
   if(origChainPtr == nullptr)
   {
      copiedChainPtr = nullptr;
   }
   else
   {
      copiedChainPtr = new LinkedSortedList<ItemType>(origChainPtr->getItem());
      copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
   }
   return copiedChainPtr;
}
template<class ItemType>
void SL_PriorityQueue<ItemType>::display() const
{ 
   slistPtr->display();
   
}  // end add
#endif