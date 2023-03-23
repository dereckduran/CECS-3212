#include<iostream>
using namespace std;
#include "LinkedBag.h"
 
int main(){
      LinkedBag<int> list;
 
      list.add(2);
      list.add(4);
      list.add(8);
      list.add(3);
      list.display();
      list.addToTail(5);
      cout << "Lista con 5 añadido: ";
      list.display();
      list.removeFromTail(4);
      cout << "Lista con 4 removido: ";
      list.display();
      
      int x = 3;
      int frequency = list.getFrequencyOf(x);
      cout << "El elemento "<<x<<" esta " << frequency << "dentro de las lista" << endl;
      LinkedBag<int>  list2(list); //Copy Constructor
      cout << "Lista original\n";
      list.display();
      cout << "Lista copeada\n";
      list2.display();
 
      if (list.contains(x)){
           cout << "El elemento "<<x<<" esta dentro de la lista\n";
      }//end if
      else {
           cout << "El elemento " << x << " no se encuentra  dentro de la lista\n";
      }//end else
      system("pause");
      return 0;
}//end main