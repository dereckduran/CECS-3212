#pragma once 

template<class ItemType>
class PriorityQueueInterface
{
    public: 
    virtual bool isEmpty() const = 0;
    virtual bool add(const ItemType &newEntry) = 0;
    virtual bool remove() = 0;
    virtual ItemType peek() const = 0;
    virtual void display() const = 0; 
};