#pragma once 
#include "Node.h"
#include "PrecondViolatedExcep.h"
#include <cassert>

template<class ItemType>
class CircularList
{
    private:
        Node<ItemType>* headPtr; 
        Node<ItemType>* dummy;
                           
        int itemCount;          
        Node<ItemType>* getNodeAt(int position) const;

public:
   CircularList();
   CircularList(const LinkedList<ItemType>& aList);
   virtual ~CircularList();

   bool isEmpty() const;
   int getLength() const;
   bool insert(int newPosition, const ItemType& newEntry);
   bool remove(int position);
   void clear();
   void display() const;
   
   /** @throw PrecondViolatedExcep if position < 1 or 
                                      position > getLength(). */
   ItemType getEntry(int position) const noexcept(false);

   /** @throw PrecondViolatedExcep if position < 1 or 
                                      position > getLength(). */
   void setEntry(int position, const ItemType& newEntry)
                               noexcept(false);
};