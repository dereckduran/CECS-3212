#include <iostream>
using namespace::std;
#include "BinaryNodeTree.h"
template<class T>
void display(T & anItem){
cout << anItem << ",";
}
int main()
{
    BinaryNodeTree <char*> balanceTree;
    balanceTree.add("A");
    balanceTree.add("B");
    balanceTree.add("C");
    balanceTree.add("D");
    balanceTree.add("E");
    balanceTree.add("F");
    balanceTree.add("G");
    
    cout << "\nRecorrido Preorder:";
    balanceTree.preorderTraverse(display);
    //Caso de eliminar la raiz del arbol
    cout << "\nRecorrido InOrder:";
    balanceTree.inorderTraverse(display);
    cout << "\nRecorrido Preorder:";
    balanceTree.postorderTraverse(display);

    return 0;
}//end main
/*
Recorrido Preorder:A,B,D,G,F,C,E,
Recorrido InOrder:G,D,B,F,A,E,C,
Recorrido Preorder:G,D,F,B,E,C,A



*/