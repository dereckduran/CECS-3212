#pragma once
#include <iostream>
#include <string>
#include "PrecondViolatedExcep.h"
using namespace std;
class RainFallMonth
{
    private:
        string monthName = "";
        float rainFall = 0;
    public:
        RainFallMonth();
        RainFallMonth(string, float);
        RainFallMonth(const RainFallMonth &_aMonth);
        ~RainFallMonth();
        void setRainFall(float );
        void setMonthName(string );
        float getRainFall() const ;
        string getMonthName() const;

        bool operator>(const RainFallMonth &) const;
        bool operator<(const RainFallMonth &) const ;
        bool operator==(const RainFallMonth &) const;
        bool operator!=(const RainFallMonth &) const;

        friend ostream &operator<<(ostream &output, const RainFallMonth &);
};

RainFallMonth::RainFallMonth()
{

}

RainFallMonth::RainFallMonth(string _monthName, float _rainFall)
{
    setRainFall(_rainFall);
    setMonthName(_monthName);
}

RainFallMonth::RainFallMonth(const RainFallMonth &_aMonth)
{
    monthName = _aMonth.monthName;
    rainFall = _aMonth.rainFall;
}

RainFallMonth::~RainFallMonth()
{

}

void RainFallMonth::setRainFall(float _rainfall)
{
    if (_rainfall < 0)
    {
        throw(PrecondViolatedExcep("Rainfall cannot be negative."));
    } 
    else
        rainFall = _rainfall;
}

void RainFallMonth::setMonthName(string _monthName)
{
    monthName = _monthName;
}

float RainFallMonth::getRainFall() const 
{
    return rainFall;
}

string RainFallMonth::getMonthName() const 
{
    return monthName;
}

bool RainFallMonth::operator<(const RainFallMonth &_aMonth) const
{
    return rainFall < _aMonth.rainFall;
}

bool RainFallMonth::operator>(const RainFallMonth &_aMonth) const
{
    return rainFall > _aMonth.rainFall;
}

bool RainFallMonth::operator==(const RainFallMonth &_aMonth) const
{
    return ((rainFall == _aMonth.rainFall) && (monthName == _aMonth.getMonthName()));
}

bool RainFallMonth::operator!=(const RainFallMonth &_aMonth) const
{
    return ((getMonthName() != _aMonth.getMonthName()) && (getRainFall() != _aMonth.getRainFall()));
}

ostream &operator<<(ostream &output, const RainFallMonth &_aMonth)
{
    output << "Month: " << _aMonth.getMonthName() << "   Rainfall: " << _aMonth.getRainFall();
    return output;
}