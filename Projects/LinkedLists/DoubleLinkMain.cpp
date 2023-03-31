#include "DoublyLinkedBag.h"
#include <iostream>

using namespace std;

int main(){
    DoublyLinkedBag<int> mybag;

    mybag.add(1);
    mybag.add(2);
    mybag.add(3);

    mybag.display();
    mybag.displayFromTail();

    mybag.shiftRight(2);
    mybag.display();
    

    return 0;
}