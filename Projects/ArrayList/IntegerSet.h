#pragma once
#include <iostream>
#include "ArrayList.h"
using namespace std;

class IntegerSet
{   
    private:
        ArrayList<bool> set;

    public:
        IntegerSet();
        IntegerSet(int []);
        IntegerSet copyconstructor(const IntegerSet &);

        virtual ~IntegerSet();

        void setSet(int []);
        ArrayList<bool> getSet() const;

        IntegerSet setUnion(const IntegerSet &) const;
        IntegerSet intersection(IntegerSet &);
        IntegerSet difference(IntegerSet &);
        IntegerSet symmetricDifference(IntegerSet &);

        IntegerSet operator-(IntegerSet &);
        bool operator==(IntegerSet &) const;
        IntegerSet &operator=(const IntegerSet&); 
        friend istream &operator>>(istream& input, IntegerSet& );
        friend ostream &operator<<(ostream& output, const IntegerSet& );

};

IntegerSet::IntegerSet(){}
IntegerSet::IntegerSet(int boolArray[])
{
    for (int index = 0; index < set.getLength(); index++)
    {
        if (boolArray[index])
            set.setEntry(index, true);
    }
}

IntegerSet::~IntegerSet(){}

void IntegerSet::setSet(int boolSet[])
{
    
}

ArrayList<bool> IntegerSet::getSet() const
{
    return set;
}


IntegerSet IntegerSet::setUnion(const IntegerSet & secondSet) const
{
    IntegerSet resultSet;
    for(int index = 0; index < secondSet.getSet().getLength(); index++)
    {
        if(set.getEntry(index) || secondSet.getSet().getEntry(index))
            resultSet.set.setEntry(index, true);
    }
    return resultSet;
}

IntegerSet IntegerSet::intersection(IntegerSet & secondSet)
{
    IntegerSet resultSet;
    for(int index = 0; index < secondSet.getSet().getLength(); index++)
    {
        if(set.getEntry(index) && secondSet.getSet().getEntry(index))
            resultSet.getSet().setEntry(index, true); 
    }
    return resultSet;
}

IntegerSet IntegerSet::difference(IntegerSet & secondSet)
{
    IntegerSet resultSet = *this - secondSet;
    return resultSet;
}

IntegerSet IntegerSet::symmetricDifference(IntegerSet & secondSet)
{
    IntegerSet differenceA, differenceB, resultSet;

    differenceA = *this - secondSet;

    differenceB = secondSet - *this;

    resultSet = differenceA.setUnion(differenceB);

    return resultSet;
}

bool IntegerSet::operator==(IntegerSet & secondSet) const
{
    for (int index = 0; index < secondSet.getSet().getLength(); index++)
    {
        if( set.getEntry(index) != secondSet.getSet().getEntry(index))
            return false;
    }
    return true;
}

IntegerSet& IntegerSet::operator=(const IntegerSet & copySet) 
{
    for(int index = 0; index < copySet.getSet().getLength(); index++)
    {
        this->getSet().setEntry(index, copySet.getSet().getEntry(index));
    }
    return *this;
}

IntegerSet IntegerSet::operator-(IntegerSet & subtractingSet)
{
    IntegerSet resultSet;
    for (int index = 0; index < subtractingSet.getSet().getLength(); index++)
        if (set.getEntry(index) && subtractingSet.set.getEntry(index))
            resultSet.getSet().setEntry(index, false);

    return resultSet;
}

istream &operator>>(istream &input, IntegerSet & _mySet)
{
    try
    {
        int sizeOfSet, number;
        cout << "Enter the amount of numbers in your set:";
        input >> sizeOfSet;
        if (sizeOfSet < 0 || sizeOfSet > 100)
            throw(PrecondViolatedExcep("Index out of range"));

        cout << "Enter the numbers in your set (1-100): " << endl;
        for(int i = 0; i < sizeOfSet; i++)
        {
            cout << "Enter a number: ";
            input >> number;
            if (number < 0 || number > 100)
                throw(PrecondViolatedExcep("Index out of range"));
            
            _mySet.set.insert(number , true);
        }
    }
    catch(PrecondViolatedExcep())
    {
        throw "Invalid size...";
    }
    return input;
    
}

ostream &operator<<(ostream & output, IntegerSet & _mySet)
{
    
    output << "The set contents.." << endl;
    for(int index = 0; index < _mySet.getSet().getLength(); index++)
    {
        if(_mySet.getSet().getEntry(index + 1))
            output << index + 1 << " ";
    }
    cout <<'\n';
    return output;
}