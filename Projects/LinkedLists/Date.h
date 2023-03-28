#pragma once 
#include <iostream>
#include <iomanip>
using namespace std;
class Date{
    private:
        int month,day, year;
        int checkDay(int) const; //utility function 
        int checkMonth(int) const;
    public:
        Date(int =29,int=29,int=9999); 
        Date(const Date &);
        ~Date();
        void setValues(int,int,int);
        void setMonth(int);
        void setDay(int); 
        void setYear(int);
        int getMonth() const; 
        int getDay() const; 
        int getYear() const;
        friend ostream &operator<<(ostream &, const Date &); 
        friend istream &operator>>(istream &, Date &);
        bool operator>(const Date &) const;
        bool operator==(const Date &) const;
        bool operator<(const Date &) const;
}; //end class Date

ostream &operator<<(ostream &output, const Date &tempDate) {
    output << tempDate.month<<" / "<<tempDate.day<<" / "<<tempDate.year;
    return output;
}//end function operator<<

istream &operator>>(istream &input, Date &tempDate) {
    cout<<"Month: ";
    input>>setw(2)>>tempDate.month; 
    tempDate.month = tempDate.checkMonth(tempDate.month); // verificando entrada de usuario 
    input.ignore();//skip / 
    cout<<"Day: ";
    input>>setw(2)>>tempDate.day; 
    tempDate.day = tempDate.checkDay(tempDate.day); //verificando la entrada del usuario
    input.ignore(); // skip / 
    cout<<"Year:";
    input>>setw(4) >> tempDate.year; 
    return input;
}//end function operator>>

Date::Date(int tempMonth,int tempDay,int tempYear):month(tempMonth),day(tempDay),year(tempYear)
{
}//end constructor

Date::Date(const Date &tempDate):month(tempDate.month),day(tempDate.day),year(tempDate.year)
{
}//end Date constructor

Date::~Date() {}//end ~Date

void Date::setValues(int tempMonth,int tempDay,int tempYear) {
    setMonth(tempMonth); 
    setDay(tempDay); 
    setYear(tempYear);
}//end setValues

void Date::setMonth(int tempMonth) {
    this->checkMonth(tempMonth); } //end setMonth

void Date::setDay(int tempDay) {
    this->day = checkDay(tempDay); }//end setDay

void Date::setYear(int tempYear) {
    this->year = tempYear; }//end setYear

int Date::getMonth() const {
    return this->month; }//end getMonth

int Date::getDay() const {
    return this->day; }//end getDay
int Date::getYear() const {
    return this->year; }//end getYear

int Date:: checkMonth(int tempMonth) const //utility function 
{
    if(tempMonth >=1 && tempMonth <= 12) {
        return(tempMonth);
    }//end if 
    else
    {
        cout<<"Invalid month ("<<tempMonth<<") set to 1\n";
        return 1; }//end if
}//end checkMonth

bool Date::operator>(const Date &_date) const
{
    return ((year > _date.getYear()) || (year > _date.getYear() && month > _date.getMonth()) || (year > _date.getYear() && month > _date.getMonth() && day > _date.getDay()));
}

 bool Date::operator==(const Date &_date) const
{
    return (year == _date.getYear() && month == _date.getMonth() && day == _date.getDay());
}

 bool Date::operator<(const Date &_date) const
{
    return (getYear() < _date.getYear() || (getYear() == _date.getYear() && getMonth() < _date.getMonth()) || (getYear() == _date.getYear() && getMonth() == _date.getMonth() && getDay() < _date.getDay()));
}

int Date::checkDay(int tempDay) const // utility function
{
    static const int dayPerMonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; 
    if(tempDay > 0 && tempDay<= dayPerMonth[month])
    {
        return tempDay; 
    }//end if
    if(month == 2 && tempDay==29 &&
    (year % 400 == 0 || (year %4 == 0 && year %100 !=0 ) ) )
    {
        return tempDay;
    }
    cout<<"Invalid Day ("<<tempDay<<") set to 1\n"; 
    return 1;
}//end checkDay