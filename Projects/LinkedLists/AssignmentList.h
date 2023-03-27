#pragma once 
#include "Assignment.h"
#include "LinkedBag.h"
#include <iostream>

using namespace std;

class AssignmentList{
    public:
    LinkedBag<Assignment> myAsig;

    AssignmentList();
    AssignmentList(const LinkedBag<Assignment> &);
    AssignmentList(const AssignmentList &);
    ~AssignmentList();

    bool removeA(string ); // debe recibir un string o un objeto de Assignment
    bool addA(string );// what should parameter be 
    void display(); // imprimir de acuerdo al orden que fueron añadidos 
    Assignment due(); //retorna un o varias asignaciones con la feche de entrega mas proxima 
    //tendria que redefinir <= y >= tambien?
    //haré un arreglo de assignment para almacenar asignaciones con la misma fecha?
};