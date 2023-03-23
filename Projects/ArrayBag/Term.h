#ifndef TERM_H
#define TERM_H
#include <iostream>

using namespace std;

class Term{
    public:
        Term(){};
        Term(int _coef, int _exp){
            coef = _coef;
            exp = _exp;
        }
        ~Term(){};
        int coef, exp;
        void setCoef(int _coef){
            coef = _coef;
        }
        void set(int _coef, int _exp){
            coef = _coef;
            exp = _exp;
        }

        int getExp()const
        {return exp;}
        int getCoef() const 
        {return coef;}
        friend istream &operator >>(istream &strm, Term &obj);
        friend ostream &operator << (ostream &strm, const Term &obj);
        Term operator +=(const Term & _term);
        bool operator==(const Term & _term) const;
};

istream &operator>>(istream &strm, Term &obj){
    cout << "Enter the coefficient for the term: ";
    strm >> obj.coef;
    cout << "Enter the exponent of the term: ";
    strm >> obj.exp;

    return strm;
}
ostream &operator<<(ostream &strm, const Term &obj){
    strm << obj.coef << "x^" << obj.exp;
    return strm;
}
Term Term::operator+=(const Term &_term){
    if(exp == _term.exp){
        coef += _term.coef;
    }
    return *this;
}
bool Term::operator==(const Term & _term) const{
    return exp == _term.exp;
}
#endif 
