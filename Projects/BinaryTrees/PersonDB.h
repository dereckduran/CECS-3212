#pragma once
#include <iostream>
#include "BinarySearchTree.h"
#include "PersonInfo.h"
#include "MyString.h"
#include <functional>
using namespace std;


template<class T>
void display(T & anItem){
cout << anItem << "\n";
}

class PeopleDatabase
{
    private:
        BinarySearchTree<PersonInfo> contacts;
        int numberOfPeople;
    public:
        PeopleDatabase();
        PeopleDatabase(const PeopleDatabase &);

        bool search(PersonInfo &);
        bool removePerson(PersonInfo &);
        void modifyPerson(PersonInfo &);

        bool isEmpty();

        friend istream &operator>>(istream &, PeopleDatabase &);
        friend ostream &operator<<(ostream &, const PeopleDatabase &);
};

PeopleDatabase::PeopleDatabase() : numberOfPeople(0)
{}
PeopleDatabase::PeopleDatabase(const PeopleDatabase &_contacts)
{
    contacts = _contacts.contacts;
    numberOfPeople = _contacts.numberOfPeople;
}

bool PeopleDatabase::search(PersonInfo &aPerson)
{
    bool found = contacts.contains(aPerson);
    if (!found)
        cout << "The person was not found in your contacts...\n";
    else
        cout << aPerson.getName() << " was found in your contacts!\n";
    return found;
}

inline bool PeopleDatabase::removePerson(PersonInfo &aPerson)
{
    bool removed = contacts.remove(aPerson);

    if(!removed)
        cout << "The person was not removed...\n";
    else
        cout << "Goodbye " << aPerson.getName() << "...\n";
    return removed;
}

inline void PeopleDatabase::modifyPerson(PersonInfo &aPerson)
{
    bool found = contacts.contains(aPerson);
    if(!found)
        cout << "The person was not found in the tree...";
    else 
    {   
        cin.ignore();
        cout << "Enter the details you would like to modify: \n";
        //get new information 
        PersonInfo tempPerson;
        cin >> tempPerson;

        //look for node where the person to modify is and set data to match tempPerson
        //how do I find the address?
        // i could remove the node and re enter 
        contacts.remove(aPerson);  
        contacts.add(tempPerson);
    }

}

inline bool PeopleDatabase::isEmpty()
{
    return numberOfPeople == 0;
}

istream &operator>>(istream &input, PeopleDatabase &_people)
{
    PersonInfo tempPerson;

    cout << "Please enter the person you would like to add to your contacts...\n";
    input >> tempPerson;
    _people.contacts.add(tempPerson);

    _people.numberOfPeople++;
    return input;

} 
ostream &operator<<(ostream &output, const PeopleDatabase &_people)
{
    if(_people.contacts.isEmpty())
        cout << "Your contacts are empty...";
    else
        _people.contacts.inorderTraverse(display);
    return output;
}