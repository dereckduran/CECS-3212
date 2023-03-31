#pragma once 
#include "Assignment.h"
#include "LinkedBag.h"
#include "Node.h"
#include <iostream>

using namespace std;

class AssignmentList{
    public:
    LinkedBag<Assignment> myAsig;

    AssignmentList();
    AssignmentList(const LinkedBag<Assignment> &);
    AssignmentList(const AssignmentList &);
    ~AssignmentList();

    bool removeA(); 
    void addA(); 
    void show(); // imprimir de acuerdo al orden que fueron añadidos 
    Assignment due(); //retorna un o varias asignaciones con la feche de entrega mas proxima 
    //tendria que redefinir <= y >= tambien?
    //haré un arreglo de assignment para almacenar asignaciones con la misma fecha?
};

AssignmentList::AssignmentList()
{} //constructor 

AssignmentList::AssignmentList(const LinkedBag<Assignment> &)
{

} // constructor con parametros 
AssignmentList::AssignmentList(const AssignmentList &)
{

} //copy constructor 

AssignmentList::~AssignmentList()
{} //destructor 

void AssignmentList::addA()
{
    Assignment newassignemt;
    cout << "Please enter the details for the new assignemnt: " << endl;
    cin >> setw (2) >> newassignemt;

    myAsig.addToTail(newassignemt);
    cout << "Assignment added to list succesfully..." << endl;
}

bool AssignmentList::removeA()
{   
    bool removed = false;
    Assignment _asgn;
    if (myAsig.isEmpty())
        cout << "There are no assignments in the list currently..." << endl;
    else {
        cout << "Please enter the details for the assignemnt you would like to remove: " << endl;
        cin >> _asgn;
        removed = myAsig.removeFromTail(_asgn);
        if (!removed) 
            cout << "The assignment was not found in the list..." << endl;
        else 
            cout << "The assignment was succesfully removed from the list. " << endl;
    }
    return removed;
}

// Debe mostrar la lista de acuerdo al orden que fueron asignados; el orden que fueron añadidos a la lista 
void AssignmentList::show()
{
    cout << "Current assignments: " << endl;
    cout << "Description " << setfill('-') << setw(40) << " Due Date" << endl;
    myAsig.display();
}

// Funcion debe retornar una o varias instancias de Assignment que con contengan la fecha mas proxima de entrega
Assignment AssignmentList::due()
{
    //haciendo una lista temporera para almacenar todas las asignaciones si tienen la misma fecha de entrega 
    //no la hago Assignment List porque la funcion de AssignmentList no recibe argumentos 
    LinkedBag<Assignment> _tempList;

    //creando un objeto para aguantar la info requerida 
    Assignment _earlyassignment; 

    //creando un puntero a la cabeza de la lista
    Node<Assignment>* curPtr = myAsig.getHeadPtr(); 

    //verificando si hay elementos en la lista 
    if (myAsig.isEmpty())
        cout << "There are no assignments in the list currently..." << endl;
    else{
        //mintras haiga elementos en la lista 
        while(curPtr != nullptr){
            //si la fecha de la asignacion es menor entonces cambia la info del objeto
            if (curPtr->getItem().getDueDate() < _earlyassignment.getDueDate())
            {
                _earlyassignment = curPtr->getItem();
                _tempList.clear();
                _tempList.add(_earlyassignment);
            }
            // si hay otra asignacion con la misma fecha de entrega se debe añadir a una lista temporera
            //need a conditional that evaluates after the fact
            else if (curPtr->getItem().getDueDate() == _earlyassignment.getDueDate()) 
            {
                _tempList.addToTail(curPtr->getItem());
            }
            //mover el puntero al resto de la lista 
            curPtr = curPtr->getNext();
        } //salir del while 
        cout << "The earliest assignment(s) found: " << endl;
        _tempList.display();
    }
    //retornar la informacion sin cambiar nada en la lista 
    return _earlyassignment;
}