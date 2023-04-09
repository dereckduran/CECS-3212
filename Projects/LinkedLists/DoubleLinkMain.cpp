#include "DoublyLinkedBag.h"
#include <iostream>
void run();
void displayMenu();
using namespace std;

int main(){
    run();
    return 0;
}

void displayMenu()
{
    cout << "\n MENU\n";
    cout << "-----------------------------------------\n";
    cout << "A) Display the linked list from the head to tail\n";
    cout << "B) Display the linked list from the tail to head\n";
    cout << "C) Add an element \n";
    cout << "D) Remove an element from the head \n";
    cout << "E) Remove an element from the tail \n";
    cout << "F) Shift elements to the left \n";
    cout << "G) Shift elements to the right \n";
    cout << "H) Exit the program\n";
}
void run(){
    char choice;
    DoublyLinkedBag<int> mybag;
    int element;
    do {
        // Display the menu and get a valid selection. 
        displayMenu();
        cin >> choice;
        while (toupper(choice) < 'A' || toupper(choice) > 'H') 
        {
            cout << "Please make a choice in the range " << "of A through D:";
            cin >> choice;
        }
        // Process the user's menu selection. 
        switch(choice)
        {
            case 'a':
            case 'A': mybag.display();
            break;  

            case 'b':
            case 'B': mybag.displayFromTail();
                
                
            break;

            case 'c':
            case 'C': 
                cin.ignore();
                cout << "Enter the number you would like to enter: ";
                cin >> element;
                mybag.add(element);
            break;

            case 'd':
            case 'D': mybag.removeHead();
            break;

            case 'e':
            case 'E': mybag.removeTail();
            break;
            
            case 'f':
            case 'F': 
            
            mybag.shiftLeft();
            break;

            case 'g':
            case 'G':
            
            mybag.shiftRight();
            break;
        }
    } while (toupper(choice) != 'H');
}

/* 

 MENU
-----------------------------------------
A) Display the linked list from the head to tail
B) Display the linked list from the tail to head
C) Add an element 
D) Remove an element from the head 
E) Remove an element from the tail 
F) Shift an element to the left 
G) Shift an element to the right 
H) Exit the program
a
There are no elements in the list...
 MENU
-----------------------------------------
A) Display the linked list from the head to tail
B) Display the linked list from the tail to head
C) Add an element 
D) Remove an element from the head 
E) Remove an element from the tail 
F) Shift an element to the left 
G) Shift an element to the right 
H) Exit the program
b
There are no elements in the list...
 MENU
-----------------------------------------
A) Display the linked list from the head to tail
B) Display the linked list from the tail to head
C) Add an element 
D) Remove an element from the head 
E) Remove an element from the tail 
F) Shift an element to the left 
G) Shift an element to the right 
H) Exit the program
c
Enter the number you would like to enter: 3

 MENU
-----------------------------------------
A) Display the linked list from the head to tail
B) Display the linked list from the tail to head
C) Add an element 
D) Remove an element from the head 
E) Remove an element from the tail 
F) Shift an element to the left 
G) Shift an element to the right 
H) Exit the program
c
Enter the number you would like to enter: 2

 MENU
-----------------------------------------
A) Display the linked list from the head to tail
B) Display the linked list from the tail to head
C) Add an element 
D) Remove an element from the head 
E) Remove an element from the tail 
F) Shift an element to the left 
G) Shift an element to the right 
H) Exit the program
c
Enter the number you would like to enter: 1

 MENU
-----------------------------------------
A) Display the linked list from the head to tail
B) Display the linked list from the tail to head
C) Add an element 
D) Remove an element from the head 
E) Remove an element from the tail 
F) Shift an element to the left 
G) Shift an element to the right 
H) Exit the program
f
Enter the element you would like to shift to the left: 1
Cannot shift the head with nothing...1 2 3 

 MENU
-----------------------------------------
A) Display the linked list from the head to tail
B) Display the linked list from the tail to head
C) Add an element 
D) Remove an element from the head 
E) Remove an element from the tail 
F) Shift an element to the left 
G) Shift an element to the right 
H) Exit the program
f
Enter the element you would like to shift to the left: 2
2 1 3 

 MENU
-----------------------------------------
A) Display the linked list from the head to tail
B) Display the linked list from the tail to head
C) Add an element 
D) Remove an element from the head 
E) Remove an element from the tail 
F) Shift an element to the left 
G) Shift an element to the right 
H) Exit the program
g
Enter the element you would like to shift to the right: 2
1 2 3 

 MENU
-----------------------------------------
A) Display the linked list from the head to tail
B) Display the linked list from the tail to head
C) Add an element 
D) Remove an element from the head 
E) Remove an element from the tail 
F) Shift an element to the left 
G) Shift an element to the right 
H) Exit the program
g
Enter the element you would like to shift to the right: 3
Cannot shift the tail to nothing...1 2 3 

 MENU
-----------------------------------------
A) Display the linked list from the head to tail
B) Display the linked list from the tail to head
C) Add an element 
D) Remove an element from the head 
E) Remove an element from the tail 
F) Shift an element to the left 
G) Shift an element to the right 
H) Exit the program
d
2 3 

 MENU
-----------------------------------------
A) Display the linked list from the head to tail
B) Display the linked list from the tail to head
C) Add an element 
D) Remove an element from the head 
E) Remove an element from the tail 
F) Shift an element to the left 
G) Shift an element to the right 
H) Exit the program
e
2 

 MENU
-----------------------------------------
A) Display the linked list from the head to tail
B) Display the linked list from the tail to head
C) Add an element 
D) Remove an element from the head 
E) Remove an element from the tail 
F) Shift an element to the left 
G) Shift an element to the right 
H) Exit the program
h
*/

