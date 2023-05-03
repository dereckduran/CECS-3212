#include "ArrayQueue.h"
#include <iostream>

using namespace std;

int main(){
    ArrayQueue <int> q;

    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);
    
    q.display();
    cout << q.peekFront() << endl;

    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(30);
    q.enqueue(35);
    q.dequeue();
    q.display();

    return 0;

}
/*
5,15,20,
5
15,20,
20,
30,35,


*/