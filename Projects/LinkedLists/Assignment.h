#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"

using namespace std;

class Assignment{
    private:
        string description;
        Date duedate;

    public:
        //constructores y destructor 
        Assignment();
        Assignment(string, Date);
        Assignment(const Assignment &);
        ~Assignment();

        //mutuadores y accesores 
        void setDescription(string );
        void setDueDate(Date );
        string getDescription() const;
        Date getDueDate() const;
        
        bool operator>(const Assignment &);
        bool operator<(const Assignment &);
        bool operator==(const Assignment &) const;
        friend istream &operator>>(istream &in, Assignment &);
        friend ostream &operator<<(ostream &out, const Assignment &);

};

Assignment::Assignment(): description("")
{} //terminar default contructor 

Assignment::Assignment(string _desc, Date _date): description(_desc), duedate(_date)
{}// terminar constructor con parametros

Assignment::Assignment(const Assignment &_temp): description(_temp.description), duedate(_temp.duedate)
{}// end copy 

Assignment::~Assignment() 
{} //end destructor 

void Assignment::setDescription(string _desc)
{
    description = _desc;
} // end description mutator 

void Assignment::setDueDate(Date _aDate) //quizas tendra que utilizar checkmonth y checkDay de Date class
{
    duedate = _aDate; //might give errors operator= is not defined for Date class
} 

string Assignment::getDescription() const
{
    return description;
} // end description accesor

Date Assignment::getDueDate() const 
{
    return duedate;
}// end date accessor

bool Assignment::operator>(const Assignment &_temp)
{
    return (duedate > _temp.getDueDate());
} //end operator>

bool Assignment::operator<(const Assignment &_temp)
{
    return (duedate < _temp.getDueDate());
} //end opearator<

bool Assignment::operator==(const Assignment &_temp) const
{
    return (duedate == _temp.getDueDate() && description == _temp.getDescription());
} //end operator==

istream &operator>>(istream &in, Assignment &_tempassignment) //getlines
{
    cout << "Enter the description for the assignment: ";
    getline(in, _tempassignment.description);
    cout << "Enter the due date for this assignment: " << endl;
    in >> _tempassignment.duedate;

    return in;
}

ostream &operator<<(ostream &out, const Assignment& _tempassignment)
{
    //out << setfill('-') << setw(10) << "";
    out << _tempassignment.description << setw(40) << _tempassignment.duedate;
    return out;
}
