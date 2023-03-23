#include"ArrayBag.h"
#include<iostream>
using namespace std;

int main(){  
    ArrayBag<int> myArrayInteger;

    myArrayInteger.add(5);
    myArrayInteger.add(3);
    myArrayInteger.add(5);
    myArrayInteger.add(10);
    myArrayInteger.display();
    myArrayInteger.remove(5);
    myArrayInteger.display();
    myArrayInteger.add(3);
    myArrayInteger.add(3);
    cout << "El nuemo 3 esta " <<myArrayInteger.getFrequencyOf(3) << "veces repetido en el arreglo\n";
    if (myArrayInteger.contains(7)){
        cout <<"El numero 7 esta dentro del arreglo\n";
    }
    else{
        cout<<"El numero 7 no esta dentro del arreglo\n";
    }
    system("pause");
    return 0;
}//end main
