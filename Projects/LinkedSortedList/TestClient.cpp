#include <iostream>

#include "Client.h"
#include "PriorityQueue.h"
#include "ListQueue.h"

using namespace std;
void Process_Arrival(ListQueue<Client>& waitingLine, SL_PriorityQueue<Client>& eventLine, bool& teller, Client& client);
void Process_Departure(ListQueue<Client>& waitingLine, SL_PriorityQueue<Client>& eventLine, bool& teller, int& timer);


int main() {
    // Performs the simulation.
    ListQueue<Client> Bankline;//Create an empty queue bankQueue to represent the bank line
    SL_PriorityQueue<Client> Eventlist; //Create an empty priority queue eventListPQueue for the event list
    bool tellerAvailable = true;
    
    Client next;
    int currentTime;
    int ActualTime = 0;
    // Create and add arrival events to event lis


    Client a('A', 1, 5);
    Client b('A', 2, 5);

    Eventlist.add(b);
    Eventlist.add(a);
   

     cout << "Simulation begins:\n";

     while (!Eventlist.isEmpty())//(eventListPQueue is not empty)
     {         
         if (ActualTime == Eventlist.peek().getArrival())
         {
             next = Eventlist.peek();
             // Get current time
             currentTime = next.getArrival();
             if (next.getStatus() == 'A')
                 //(newEvent is an arrival event)
             //processArrival(newEvent, eventListPQueue, bankQueue)
                Process_Arrival(Bankline, Eventlist, tellerAvailable, next);
            else if (next.getStatus() == 'D')
             //    //processDeparture(newEvent, eventListPQueue, bankQueue)
                Process_Departure(Bankline, Eventlist, tellerAvailable, currentTime);
                
         }
         else
             ActualTime++;
     }
    
    cout << "Simulation ends.\n";

    return 0;
}


void Process_Arrival(ListQueue<Client>& waitingLine, SL_PriorityQueue<Client>& eventLine, bool& teller,Client& client )
{
    
    eventLine.remove();
    if (waitingLine.isEmpty() && teller)
    {
        //cout << client;
        int DepartureEvent = client.getArrival() + client.getTransTime();
        Client UpdateNext('D', DepartureEvent, 1);
        eventLine.add(UpdateNext);
        teller = false;
    }
    else
    {
        waitingLine.enqueue(client);
    }
    cout << "Processed arrival at: " << client.getArrival() << endl;

}

void Process_Departure(ListQueue<Client>& waitingLine, SL_PriorityQueue<Client>& eventLine, bool& teller, int& timer)
{   
    eventLine.remove(); // Remove the departure event from the event list

// Update the bank line
    if (!waitingLine.isEmpty()) { // bank line is not empty
        // Remove customer C from the front of the bank line
        Client Update = waitingLine.peekFront();
        waitingLine.dequeue();

        // Departure time of customer C is current time + transaction length
        int departureTime = timer + Update.getTransTime();
        // Add a departure event for customer C to the event list
        Client departureEvent('D', departureTime, 1);
        eventLine.add(departureEvent);

    }
    else { // bank line is empty
        // Mark the teller as available.
        teller = true;
    }

    cout << "Processed departure at " << timer << endl;
}