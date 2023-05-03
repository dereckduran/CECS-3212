#pragma once 
#include <iostream>
#include <math.h>
#include "LinkedSortedList.h"
#include "RainFallMonth.h"
using namespace std;

class RainFallYear 

{
    private:
    LinkedSortedList<RainFallMonth> yearlyRainFall;
    //unordered_map<string, int> monthNames = {"January":0 ,"February": 1, "March":2,"April":3, "May":4, "June":5, "July":6, "August":7, "September":8, "October":9, "November":10, "December":11};

    public:

    RainFallYear();
    RainFallYear(const RainFallYear &);
    virtual ~RainFallYear();
    float totalRainFall();
    float avgRainFall();
    void maxRainFallMonths();
    void minRainFallMonths();

    friend ostream &operator<<(ostream &output, const RainFallYear &);
    friend istream &operator>>(istream &input, RainFallYear &);

};

RainFallYear::RainFallYear()
{}

RainFallYear::~RainFallYear()
{}

float RainFallYear::totalRainFall()
{
    float totalRain = 0;
    int index = 1;
    while(index < 13)
    {
        totalRain += yearlyRainFall.getEntry(index).getRainFall();
        index++;
    }
    return totalRain;
}
inline float RainFallYear::avgRainFall()
{

    float totalRain = 0;
    int index = 1;
    while(index < 13)
    {
        totalRain += yearlyRainFall.getEntry(index).getRainFall();
        index++;
    }
    cout << totalRain / 12;
    return totalRain / 12;
}
void RainFallYear::maxRainFallMonths()
{
    LinkedSortedList<RainFallMonth> maxMonths;

    int index = 1;
    int maxItemIndex = yearlyRainFall.getLength();
    while(index < 13)
    {
        if(yearlyRainFall.getEntry(index).getRainFall() == yearlyRainFall.getEntry(maxItemIndex).getRainFall())
        {
            maxMonths.insertSorted(yearlyRainFall.getEntry(index));
        }
        index++;
    }
    
    maxMonths.display();
}
void RainFallYear::minRainFallMonths()
{
    LinkedSortedList<RainFallMonth> minMonths;
    int index = 1;
    while(index < 13)
    {
        if (yearlyRainFall.getEntry(index).getRainFall() == yearlyRainFall.getEntry(1).getRainFall())
        {
            minMonths.insertSorted(yearlyRainFall.getEntry(index));
        }
        index++;
    }
    minMonths.display();
}
/*
RainFallMonth RainFallYear::operator[](int position) const
{
    if(position < 0)
        return yearlyRainFall.getEntry(-1);
    return yearlyRainFall.getEntry(position);
}*/
istream &operator>>(istream &input, RainFallYear &aYear)
{
    string monthname;
    float rainfall;
    RainFallMonth _aMonth;
    
    cout << "Enter the rainfall for each month of the year \n";
    for(int index = 0; index < 12; index++)
    {
        cout << "Enter the month name: ";
        input >>  monthname;

        cout << "Enter the rainfall for the month: ";
        input >> rainfall; 

        RainFallMonth _aMonth(monthname, rainfall);

        aYear.yearlyRainFall.insertSorted(_aMonth);
    }
    
    return input;
    
}
ostream &operator<<(ostream &output, const RainFallYear &_aYear)
{
    _aYear.yearlyRainFall.display();
    return output;
}