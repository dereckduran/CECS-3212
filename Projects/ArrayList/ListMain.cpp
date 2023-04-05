#include<iostream>
#include<string>
using namespace::std;
#include "LinkedList.h"
int main(){
      LinkedList<string> myArray;
 
      myArray.insert(1, "Mayonesa");
      myArray.insert(2, "Papitas");
      myArray.insert(3, "Galletas");
      myArray.insert(4, "Sodas");
      myArray.insert(2, "Gomitas");
      myArray.remove(3);
      myArray.setEntry(2, "Chocolates");
      for (int index = 1; index <= myArray.getLength(); index++){
           cout << myArray.getEntry(index) << endl;
      }//end for
 
    return 0;
}//end main