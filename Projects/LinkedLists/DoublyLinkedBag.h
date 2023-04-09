//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT bag: Link-based implementation.
    @file LinkedBag.h 
    Listing 4-3 */
#ifndef _DOUBLY_LINKED_BAG
#define _DOUBLY_LINKED_BAG
#include <cstddef>
#include "BagInterface.h"
#include "Node.h"
#include <iostream>

using namespace std;

template<class ItemType>
class DoublyLinkedBag : public BagInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node
   Node<ItemType>* tailPtr; // Pointer to last node
   int itemCount;           // Current count of bag items
   
   // Returns either a pointer to the node containing a given entry
   // or the null pointer if the entry is not in the bag.
   Node<ItemType>* getPointerTo(const ItemType& target) const;
   
public:
   DoublyLinkedBag();
   DoublyLinkedBag(const DoublyLinkedBag<ItemType>& aBag); // Copy constructor
   virtual ~DoublyLinkedBag();                       // Destructor should be virtual
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool addToTail(const ItemType& newEntry);
   bool remove(const ItemType& anEntry);
   void removeHead();
   void removeTail();
   bool removeFromTail(const ItemType& anEntry);
   void shiftRight(); 
   void shiftLeft();
   void clear();
   void display() const;
   void displayFromTail() const;
   bool contains(const ItemType& anEntry) const;
   int getFrequencyOf(const ItemType& anEntry) const;
   Node<ItemType>* getHeadPtr() const;
   Node<ItemType>* getTailPtr() const;
   vector<ItemType> toVector() const;
}; // end LinkedBag

template<class ItemType>
DoublyLinkedBag<ItemType>::DoublyLinkedBag() : headPtr(nullptr), tailPtr(nullptr), itemCount(0)
{
}
template <class ItemType>
void DoublyLinkedBag<ItemType>::removeHead()
{
   Node<ItemType>* nodeToDelete = headPtr;
   headPtr = headPtr->getNext();
   headPtr->setPrev(nullptr);

   nodeToDelete->setNext(nullptr);
   nodeToDelete->setPrev(nullptr);
   delete nodeToDelete;
   nodeToDelete = nullptr;

   display();
}

template<class ItemType>
void DoublyLinkedBag<ItemType>::removeTail()
{
   Node<ItemType>* nodeToDelete = tailPtr;
   tailPtr = tailPtr->getPrev();
   tailPtr->setNext(nullptr);

   nodeToDelete->setNext(nullptr);
   nodeToDelete->setPrev(nullptr);
   delete nodeToDelete;
   nodeToDelete = nullptr;

   display();
}

template<class ItemType>
void DoublyLinkedBag<ItemType>::display()const{

   if (isEmpty())
      cout << "There are no elements in the list...";
   else {
      Node<ItemType>* curPtr = headPtr;
      while(curPtr != nullptr){
         cout << curPtr->getItem() << " ";
         curPtr = curPtr->getNext();
      }
      cout << endl;
   }
}

template<class ItemType>
void DoublyLinkedBag<ItemType>::displayFromTail()const{
   if (isEmpty())
      cout << "There are no elements in the list...";
   else{
      Node<ItemType>* curPtr = tailPtr;
      while(curPtr != nullptr){
         cout << curPtr->getItem() << " ";
         curPtr = curPtr->getPrev();
      }
      cout<<endl;
   }
}

template<class ItemType>
DoublyLinkedBag<ItemType>::DoublyLinkedBag(const DoublyLinkedBag<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
    Node<ItemType>* origChainHeadPtr = aBag.headPtr;  // Points to nodes in original chain
    Node<ItemType>* origChainTailPtr = aBag.tailPtr;
   
   if (origChainHeadPtr == nullptr)
      headPtr = nullptr;  // Original bag is empty
      tailPtr = nullptr;
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      tailPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainHeadPtr->getNext();     // Advance original-chain pointer
      
      while (origChainHeadPtr != origChainTailPtr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainHeadPtr->getItem();
         
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);

         // Colocando el puntero presente como el previo del nuevo nodo 
         newNodePtr->setPrev(newChainPtr);

         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();
         
         // Advance original-chain pointer
         origChainHeadPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
void DoublyLinkedBag<ItemType>::shiftRight()
{
   Node<ItemType>* shift = tailPtr;
   Node<ItemType>* _temp = tailPtr;
   ItemType itemCont = shift->getItem();

   if (isEmpty())
      cout << "Cannot shift nothing...";
   else 
   {
      while(shift->getPrev() != nullptr)
      {
         shift = shift->getPrev(); 
         _temp->setItem(shift->getItem());
         _temp = shift; 
         _temp->setItem(itemCont);
      }
   }
   display();
}

template<class ItemType>
void DoublyLinkedBag<ItemType>::shiftLeft()
{
   Node<ItemType>* shift = headPtr;
   Node<ItemType>* _temp = headPtr;
   ItemType itemCont = shift->getItem();
   if (isEmpty()){
      cout << "Cannot shift nothing...";
   }
   else 
   {
      while(shift->getNext() != nullptr)
      {
         shift = shift->getNext();
         _temp->setItem(shift->getItem());
         _temp = shift;
         _temp->setItem(itemCont);
      }
   }
   display();
}

template<class ItemType>
DoublyLinkedBag<ItemType>::~DoublyLinkedBag()
{
   clear();
}  // end destructor

template<class ItemType>
bool DoublyLinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int DoublyLinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool DoublyLinkedBag<ItemType>::add(const ItemType& newEntry)
{
   // Add to beginning of chain: new node references rest of chain;
   // (headPtr is null if chain is empty)       
   Node<ItemType>* nextNodePtr = new Node<ItemType>();
   nextNodePtr->setItem(newEntry);
   nextNodePtr->setNext(nullptr);
   if(isEmpty()){
      headPtr = nextNodePtr;
      tailPtr = nextNodePtr;
      
   } 
   else{
      headPtr->setPrev(nextNodePtr);  // heads prev will now be the new node 
      nextNodePtr->setNext(headPtr);
      headPtr = nextNodePtr;          // head pointer is the new node 
      headPtr->setPrev(nullptr);
      
   }
//   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); // alternate code
   itemCount++;

   return true;
}  // end add

template<class ItemType>
bool DoublyLinkedBag<ItemType>::addToTail(const ItemType & newEntry){
   // Add to end of chain: new node references rest of chain;
   // (headPtr is null if chain is empty)        
   Node<ItemType>* nextNodePtr = new Node<ItemType>();
   nextNodePtr->setItem(newEntry);
   nextNodePtr->setNext(nullptr);  // New node points to chain
   nextNodePtr->setPrev(nullptr);
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
      nextNodePtr->setPrev(curPtr);
      curPtr->setNext(nextNodePtr);     //añadiendo NewEntry al final
      itemCount++;
   }
   
   return true;
}
template<class ItemType>
vector<ItemType> DoublyLinkedBag<ItemType>::toVector() const
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
bool DoublyLinkedBag<ItemType>::remove(const ItemType& anEntry)
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
      nodeToDeletePtr->setPrev(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      itemCount--;
   } // end if
   
	return canRemoveItem;
}  // end remove
template <class ItemType>
bool DoublyLinkedBag<ItemType>::removeFromTail(const ItemType& anEntry){
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
      curPtr->setPrev(nullptr);
      delete curPtr;
      curPtr = nullptr;
      
      itemCount--;
   } // end if
   
	return canRemoveItem;
}
template<class ItemType>
void DoublyLinkedBag<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr->getNext() != tailPtr)
   {
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      nodeToDeletePtr->setPrev(nullptr);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr 
   delete tailPtr;
	itemCount = 0;
}  // end clear


template<class ItemType>
int DoublyLinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
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
Node<ItemType> *DoublyLinkedBag<ItemType>::getHeadPtr() const
{
    return headPtr;
}
template <class ItemType>
Node<ItemType> *DoublyLinkedBag<ItemType>::getTailPtr() const
{
    return tailPtr;
}
template<class ItemType>
bool DoublyLinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* DoublyLinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
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
} // end getPointerT


#endif