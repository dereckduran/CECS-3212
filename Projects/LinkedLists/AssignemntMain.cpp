#include "Assignment.h"
#include "AssignmentList.h"
#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

void displayMenu();
void run();

int main(){
    run();
    return 0;
}



void displayMenu()
{
    cout << "\n MENU\n";
    cout << "-----------------------------------------\n";
    cout << "A) Display the assignment list in order added to list\n";
    cout << "B) Add an assignment\n";
    cout << "C) Remove an assignment \n";
    cout << "D) Get assignment(s) with earliest due date \n";
    cout << "E) Exit the program \n";
    cout << "Enter your choice: ";
}
void run(){
    AssignmentList myhomework;
    Assignment _asgn;
    char choice;
    do {
        // Display the menu and get a valid selection. 
        displayMenu();
        cin >> choice;
        while (toupper(choice) < 'A' || toupper(choice) > 'E') 
        {
        cout << "Please make a choice in the range " << "of A through D:";
        cin >> choice;
        }
        // Process the user's menu selection. 
        switch(choice)
        {
            case 'a':
            case 'A': myhomework.show();
            break;

            case 'b':
            case 'B':
                cin.ignore();
                myhomework.addA();
            break;

            case 'c':
            case 'C': 
                cin.ignore();
                myhomework.removeA();
            break;

            case 'd':
            case 'D':
            //Assignment 
            myhomework.due();
            break;
        }
    } while (toupper(choice) != 'E');
}


/*


 MENU
-----------------------------------------
A) Display the assignment list in order added to list
B) Add an assignment
C) Remove an assignment 
D) Get assignment(s) with earliest due date 
E) Exit the program 
Enter your choice: b
Please enter the details for the new assignemnt: 
Enter the description for the assignment: lab
Enter the due date for this assignment: 
Month: 4
Day: 1
Year:2023
Assignment added to list succesfully...

 MENU
-----------------------------------------
A) Display the assignment list in order added to list
B) Add an assignment
C) Remove an assignment 
D) Get assignment(s) with earliest due date 
E) Exit the program 
Enter your choice: b
Please enter the details for the new assignemnt: 
Enter the description for the assignment: examen de fisica
Enter the due date for this assignment: 
Month: 4
Day: 1
Year:2023
Assignment added to list succesfully...

 MENU
-----------------------------------------
A) Display the assignment list in order added to list
B) Add an assignment
C) Remove an assignment 
D) Get assignment(s) with earliest due date 
E) Exit the program 
Enter your choice: a
Current assignments: 
Description ------------------------------- Due Date
lab---------------------------------------4 / 1 / 2023
examen de fisica---------------------------------------4 / 1 / 2023

 MENU
-----------------------------------------
A) Display the assignment list in order added to list
B) Add an assignment
C) Remove an assignment 
D) Get assignment(s) with earliest due date 
E) Exit the program 
Enter your choice: b
Please enter the details for the new assignemnt: 
Enter the description for the assignment: hacer apunter 
Enter the due date for this assignment: 
Month: 5
Day: 1
Year:2023
Assignment added to list succesfully...

 MENU
-----------------------------------------
A) Display the assignment list in order added to list
B) Add an assignment
C) Remove an assignment 
D) Get assignment(s) with earliest due date 
E) Exit the program 
Enter your choice: a
Current assignments: 
Description ------------------------------- Due Date
lab---------------------------------------4 / 1 / 2023
examen de fisica---------------------------------------4 / 1 / 2023
hacer apunter ---------------------------------------5 / 1 / 2023

 MENU
-----------------------------------------
A) Display the assignment list in order added to list
B) Add an assignment
C) Remove an assignment 
D) Get assignment(s) with earliest due date 
E) Exit the program 
Enter your choice: d
The earliest assignment(s) found: 
lab---------------------------------------4 / 1 / 2023
examen de fisica---------------------------------------4 / 1 / 2023

 MENU
-----------------------------------------
A) Display the assignment list in order added to list
B) Add an assignment
C) Remove an assignment 
D) Get assignment(s) with earliest due date 
E) Exit the program 
Enter your choice: c
Please enter the details for the assignemnt you would like to remove: 
Enter the description for the assignment: lab
Enter the due date for this assignment: 
Month: 4
Day: 1
Year:2023
The assignment was succesfully removed from the list. 

 MENU
-----------------------------------------
A) Display the assignment list in order added to list
B) Add an assignment
C) Remove an assignment 
D) Get assignment(s) with earliest due date 
E) Exit the program 
Enter your choice: a
Current assignments: 
Description ------------------------------- Due Date
hacer apunter ---------------------------------------5 / 1 / 2023
examen de fisica---------------------------------------4 / 1 / 2023

 MENU
-----------------------------------------
A) Display the assignment list in order added to list
B) Add an assignment
C) Remove an assignment 
D) Get assignment(s) with earliest due date 
E) Exit the program 
Enter your choice: d
The earliest assignment(s) found: 
examen de fisica---------------------------------------4 / 1 / 2023

 MENU
-----------------------------------------
A) Display the assignment list in order added to list
B) Add an assignment
C) Remove an assignment 
D) Get assignment(s) with earliest due date 
E) Exit the program 
Enter your choice: e
*/