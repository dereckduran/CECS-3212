#pragma once
#include "MyString.h"
#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

class PersonInfo
{
    private:
        MyString name;
        Date birthday;
    public:
        PersonInfo();
        PersonInfo(MyString, Date);
        PersonInfo(const PersonInfo &);
        ~PersonInfo();

        void setBirthday(Date );
        void setName(MyString);

        MyString getName() const;
        Date getBirthday() const;

        bool operator>(const PersonInfo &) const;
        bool operator<(const PersonInfo &) const;
        bool operator==(const PersonInfo &) const;

        friend ostream &operator<<(ostream &, const PersonInfo &); 
        friend istream &operator>>(istream &, PersonInfo &);
};

PersonInfo::PersonInfo() 
{
    name = "";
    // birthday = 29/29/9999
}

PersonInfo::PersonInfo(MyString _name, Date _date)
{
    setName(_name);
    setBirthday(_date);
}
PersonInfo::PersonInfo(const PersonInfo &_person)
{
    setName(_person.name);
    setBirthday(_person.birthday);
}
PersonInfo::~PersonInfo()
{

}

void PersonInfo::setName(MyString _name)
{
    name = _name;
}

void PersonInfo::setBirthday(Date _date)
{
    birthday = _date;
}

MyString PersonInfo::getName() const
{
    return name;
}

Date PersonInfo::getBirthday() const
{
    return birthday;
}

bool PersonInfo::operator<(const PersonInfo &_person) const
{
    return birthday < _person.getBirthday();
}

bool PersonInfo::operator>(const PersonInfo &_person) const 
{
    return birthday > _person.getBirthday();
}

bool PersonInfo::operator==(const PersonInfo &_person) const 
{
    return birthday == _person.getBirthday() && name == _person.getName();
}

ostream &operator<<(ostream &output, const PersonInfo &aPerson)
{
    output << "Person's name: " << aPerson.getName() << " Birthday: " << aPerson.getBirthday() << endl;
    return output;
}
istream &operator>>(istream &input,PersonInfo &aPerson)
{
    cout << "Enter person's name: ";
    input >> aPerson.name;
    cout << "Enter " << aPerson.getName() << "'s birthday: \n";
    input >> aPerson.birthday;

    return input;
}