#include "Client.h"
#include "ListQueue.h"
#include "PriorityQueue.h"
#include "LinkedSortedList.h"
#include <iostream>

using namespace std;

int main()
{
    ListQueue<Client> tellerWaitingList;
    SL_PriorityQueue<Client> eventList;
    
    bool teller = true;

    Client n1('a', 1 ,5);
    Client n2('a', 2 ,5);
    Client n3('a', 4 ,5);
    Client n4('a', 20 ,5);
    Client n5('a', 22 ,5);
    Client n6('a', 24 ,5);
    Client n7('a', 26 ,5);
    Client n8('a', 28 ,5);
    Client n9('a', 30 ,5);
    Client n10('a', 88 ,3);

    eventList.add(n10);
    eventList.add(n9);
    eventList.add(n8);
    eventList.add(n7);
    eventList.add(n6);
    eventList.add(n5);
    eventList.add(n4);
    eventList.add(n3);
    eventList.add(n2);
    eventList.add(n1);

    cout << "Simulation begins: \n";
    while(!eventList.isEmpty())
    {
        Client nextClient = eventList.peek();
        int timer = nextClient.getArrival();

        if (nextClient.getStatus() == 'a')
        {
            eventList.remove();
            if (tellerWaitingList.isEmpty() && teller) {
                int departureTime = timer + nextClient.getTransTime();
                Client departureEvent('D', departureTime, 1);
                eventList.add(departureEvent);
                teller = false;
            }
            else {
                tellerWaitingList.enqueue(nextClient);
            }
            cout << "Processing an arrival event at time: " << nextClient.getArrival() << endl;
        }
        else {
            eventList.remove();
            if (!tellerWaitingList.isEmpty()) {
                Client nextWaitingClient = tellerWaitingList.peekFront();
                tellerWaitingList.dequeue();
                int departureTime = timer + nextWaitingClient.getTransTime();
                Client departureEvent('D', departureTime, 1);
                eventList.add(departureEvent);
            }
            else {
                teller = true;
            }
            cout << "Processing a departure event at time: " << timer << endl;
        }
    }

    cout << "Simulation ends.\n";
    return 0;
}

/*
Simulation begins: 
Processing an arrival event at time: 1
Processing an arrival event at time: 2
Processing an arrival event at time: 4
Processing a departure event at time: 6
Processing a departure event at time: 11
Processing a departure event at time: 16
Processing an arrival event at time: 20
Processing an arrival event at time: 22
Processing an arrival event at time: 24
Processing a departure event at time: 25
Processing an arrival event at time: 26
Processing an arrival event at time: 28
Processing an arrival event at time: 30
Processing a departure event at time: 30
Processing a departure event at time: 35
Processing a departure event at time: 40
Processing a departure event at time: 45
Processing a departure event at time: 50
Processing an arrival event at time: 88
Processing a departure event at time: 91
Simulation ends.
*/