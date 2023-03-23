#pragma once
#include "Term.h"
#include "ArrayBag.h"
#include <iostream>

using namespace std;

class Polynomial{
    public:
    ArrayBag<Term> poly;

    Polynomial(){};
    ~Polynomial(){};


    int degree();
    int coefficient(int);
    void changeCoefficient(int, int);
    Polynomial operator+(const Polynomial &_poly);
    friend ostream &operator << (ostream &strm, const Polynomial &_poly);
    friend istream &operator >>(istream &strm, Polynomial &_poly);

};
int Polynomial::degree(){
    int max = 0;
    for(int i = 0;i < poly.getCurrentSize(); i++){
        if(poly.getElement(i).getExp() > max)
            max = poly.getElement(i).exp;
    }
    return max;
}
int Polynomial::coefficient(int _power){
    for(int i = 0; i < poly.getCurrentSize(); i++){
        if(poly.getElement(i).getExp() == _power){
            return poly.getElement(i).getCoef();
        }
    }
    return 0;
}
void Polynomial::changeCoefficient(int newcoef, int _power){
    Term temp;
    for(int i = 0; i < poly.getCurrentSize(); i++){
        if(poly.getElement(i).getExp() == _power){
            poly.remove(poly.getElement(i));
            temp.set(newcoef, _power);
            poly.add(temp);
            return;
        }
    }
    Term newterm(newcoef,_power);
    poly.add(newterm);
}
Polynomial Polynomial::operator+(const Polynomial &_poly){
    Polynomial result;

    for (int i = 0; i < poly.getCurrentSize(); i++) { //añadiendo los terminos del primer resultado 
        result.poly.add(poly.getElement(i));
    }

	for (int i = 0; i < _poly.poly.getCurrentSize(); i++) //iterando sobre el sugndo termino
	{
        bool found = false; //flag para salir si ya encontramos el termino
		for (int j = 0; j < result.poly.getCurrentSize(); j++) //loop sobre la mano izquierda de la suma 
		{
			if (result.poly.getElement(j).getExp() == _poly.poly.getElement(i).getExp()) // si los exponentes son igual suma 
			{
				result.poly.add(result.poly.getElement(j) += _poly.poly.getElement(i));
                result.poly.remove(result.poly.getElement(j));
                found = true;
                break;
			}
				
		}
        if (!found) // si no se encontro un termino con la misma potencia los añadimos al final
            result.poly.add(_poly.poly.getElement(i));
    }
    return result; //retornar resultado
}
ostream &operator<<(ostream &strm, const Polynomial &_poly){
    for (int i = 0; i < _poly.poly.getCurrentSize(); i++){
        if (i > 0 && _poly.poly.getElement(i).getCoef() > 0 )
            strm << " + ";
        strm << _poly.poly.getElement(i);
    }
    return strm;
}
istream &operator>>(istream &strm, Polynomial &_poly){
    int cap;
    cout << "Enter how many terms your polynomial has:";
    strm >> cap;
    for (int i = 0; i < cap; i++){
        Term temp;
        cout << "Term " << i + 1 << endl;
        strm >> temp;

        _poly.poly.add(temp);
    }
    return strm;
}