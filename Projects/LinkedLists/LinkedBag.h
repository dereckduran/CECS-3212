//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT bag: Link-based implementation.
    @file LinkedBag.h 
    Listing 4-3 */
#ifndef _LINKED_BAG
#define _LINKED_BAG
#include <cstddef>
#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node
   int itemCount;           // Current count of bag items
   
   // Returns either a pointer to the node containing a given entry
   // or the null pointer if the entry is not in the bag.
   Node<ItemType>* getPointerTo(const ItemType& target) const;
   
public:
   LinkedBag();
   LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
   virtual ~LinkedBag();                       // Destructor should be virtual
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool addToTail(const ItemType& newEntry);
   bool remove(const ItemType& anEntry);
   bool removeFromTail(const ItemType& anEntry);
   void clear();
   void display() const;
   bool contains(const ItemType& anEntry) const;
   int getFrequencyOf(const ItemType& anEntry) const;
   Node<ItemType>* getHeadPtr() const;
   vector<ItemType> toVector() const;
}; // end LinkedBag

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor
template<class ItemType>
void LinkedBag<ItemType>::display()const{
   Node<ItemType>* curPtr = headPtr;
   while(curPtr != nullptr){
      cout << curPtr->getItem() << endl;
      curPtr = curPtr->getNext();
   }
}
template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
   Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      
      while (origChainPtr != nullptr)
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
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
   // Add to beginning of chain: new node references rest of chain;
   // (headPtr is null if chain is empty)        
   Node<ItemType>* nextNodePtr = new Node<ItemType>();
   nextNodePtr->setItem(newEntry);
   nextNodePtr->setNext(headPtr);  // New node points to chain
//   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); // alternate code

   headPtr = nextNodePtr;          // New node is now first node
   itemCount++;
   
   return true;
}  // end add

template<class ItemType>
bool LinkedBag<ItemType>::addToTail(const ItemType & newEntry){
   // Add to end of chain: new node references rest of chain;
   // (headPtr is null if chain is empty)        
   Node<ItemType>* nextNodePtr = new Node<ItemType>();
   nextNodePtr->setItem(newEntry);
   nextNodePtr->setNext(nullptr);  // New node points to chain
//   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); // alternate code
   if(isEmpty())
   {
      headPtr = nextNodePtr;
      itemCount++;
   }
   else {
      Node<ItemType>* curPtr = headPtr;
      while(curPtr->getNext() != nullptr) //iterando hacia el final de la lista
         curPtr = curPtr->getNext();
      curPtr->setNext(nextNodePtr);     //añadiendo NewEntry al final
      itemCount++;
   }
   
   return true;
}
template<class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const
{
   vector<ItemType> bagContents;
   Node<ItemType>* curPtr = headPtr;
   int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
   {
		bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }  // end while
   
   return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
   Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());
      
      // Delete first node
      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      itemCount--;
   } // end if
   
	return canRemoveItem;
}  // end remove
template <class ItemType>
bool LinkedBag<ItemType>::removeFromTail(const ItemType& anEntry){
   Node<ItemType>* entryNodePtr = getPointerTo(anEntry); //buscamos el puntero donde este la info para eliminar
   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
   if (canRemoveItem)
   {
      Node<ItemType>* curPtr = headPtr; //un puntero actual para ir hacia el final de la lista 
      while(curPtr->getNext() != nullptr){
         curPtr = curPtr->getNext();
      }
      // Copy data from last node to located node
      entryNodePtr->setItem(curPtr->getItem());
      
      // Delete last node
      Node<ItemType>* nodeToDeletePtr = curPtr; // cant be current pointer because its already at the end 
      
      curPtr = headPtr;// resetting node to head 
      while (curPtr->getNext() != nodeToDeletePtr) //taking the node to the place before the last node 
         curPtr = curPtr->getNext();
      
      // Return node to the system
      curPtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      itemCount--;
   } // end if
   
	return canRemoveItem;
}
template<class ItemType>
void LinkedBag<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr
   
	itemCount = 0;
}  // end clear


template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
   int counter = 0;
   Node<ItemType>* curPtr = headPtr;
   while ((curPtr != nullptr) && (counter < itemCount))
   {
      if (anEntry == curPtr->getItem())
      {
         frequency++;
      } // end if
      
      counter++;
      curPtr = curPtr->getNext();
   } // end while
   
	return frequency;
}  // end getFrequencyOf

//funcion para acesar la cabeza de la lista
template <class ItemType>
Node<ItemType> *LinkedBag<ItemType>::getHeadPtr() const
{
    return headPtr;
}

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   
   while (!found && (curPtr != nullptr))
   {
      if (anEntry == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while
   
   return curPtr;
} // end getPointerTo



#endif