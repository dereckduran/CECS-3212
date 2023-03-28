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