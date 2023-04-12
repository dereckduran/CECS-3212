#include "IntegerSet.h"
#include <iostream>

using namespace std;

void run();
void displayMenu();

int main()
{
    run();
    return 0;
}

void displayMenu()
{
    cout << "\n MENU\n";
    cout << "-----------------------------------------\n";
    cout << "A) Union of your set with another\n";
    cout << "B) Intersection of a set with another\n";
    cout << "C) Difference between sets \n";
    cout << "D) Symmetric difference between sets \n";
    cout << "E) Verify if two sets are equal \n";
    cout << "F) Print your current set \n";
    cout << "G) Exit the program \n";
    cout << "Enter your choice: ";
}
void run(){
    IntegerSet mySet, secondSet, resultSet;
    char choice;
    bool setsAreEqual;
    cout << "Enter the numbers in your set: \n";
    cin >> mySet;
    do {
        // Display the menu and get a valid selection. 
        displayMenu();
        cin >> choice;
        while (toupper(choice) < 'A' || toupper(choice) > 'G') 
        {
        cout << "Please make a choice in the range " << "of A through G:";
        cin >> choice;
        }
        // Process the user's menu selection. 
        switch(choice)
        {
            case 'a':
            case 'A': 
                cout << "Enter the numbers in your second set: \n";
                cin >> secondSet;
                resultSet = mySet.setUnion(secondSet);
                cout << resultSet;
                break;

            case 'b':
            case 'B':
                cout << "Enter the numbers in your second set: \n";
                cin >> secondSet;
                resultSet = mySet.intersection(secondSet);
                cout << resultSet;
                
                break;

            case 'c':
            case 'C': 
                cout << "Enter the numbers in your second set: \n";
                cin >> secondSet;
                resultSet = mySet - secondSet;
                cout << resultSet;
                
            break;

            case 'd':
            case 'D':
                cout << "Enter the numbers in your second set: \n";
                cin >> secondSet;
                resultSet = mySet.symmetricDifference(secondSet);
                cout << resultSet;
            
            break;

            case 'e':
            case 'E':
                cout << "Enter the numbers in your second set: \n";
                cin >> secondSet;
                setsAreEqual = mySet == secondSet;
                if(setsAreEqual)
                    cout << "Sets are equal!";
                else   
                    cout << "Sets are not equal...";

            break;

            case 'f':
            case 'F':
                cout << mySet;

            break;

        }
        secondSet.clear();
        resultSet.clear();
    } while (toupper(choice) != 'G');
}

/*
Enter the numbers in your set: 
Enter the amount of numbers in your set:3
Enter the numbers in your set (1-100): 
Enter a number: 1
Enter a number: 2
Enter a number: 3

 MENU
-----------------------------------------
A) Union of your set with another
B) Intersection of a set with another
C) Difference between sets 
D) Symmetric difference between sets 
E) Verify if two sets are equal 
F) Print your current set 
G) Exit the program 
Enter your choice: d
Enter the numbers in your second set: 
Enter the amount of numbers in your set:3
Enter the numbers in your set (1-100): 
Enter a number: 2
Enter a number: 3
Enter a number: 4
The set contents..
1 4 

 MENU
-----------------------------------------
A) Union of your set with another
B) Intersection of a set with another
C) Difference between sets 
D) Symmetric difference between sets 
E) Verify if two sets are equal 
F) Print your current set 
G) Exit the program 
Enter your choice: a
Enter the numbers in your second set: 
Enter the amount of numbers in your set:3
Enter the numbers in your set (1-100): 
Enter a number: 4
Enter a number: 5
Enter a number: 6
The set contents..
1 2 3 4 5 6 

 MENU
-----------------------------------------
A) Union of your set with another
B) Intersection of a set with another
C) Difference between sets 
D) Symmetric difference between sets 
E) Verify if two sets are equal 
F) Print your current set 
G) Exit the program 
Enter your choice: b
Enter the numbers in your second set: 
Enter the amount of numbers in your set:3
Enter the numbers in your set (1-100): 
Enter a number: 2
Enter a number: 3
Enter a number: 4
The set contents..
2 3 

 MENU
-----------------------------------------
A) Union of your set with another
B) Intersection of a set with another
C) Difference between sets 
D) Symmetric difference between sets 
E) Verify if two sets are equal 
F) Print your current set 
G) Exit the program 
Enter your choice: c
Enter the numbers in your second set: 
Enter the amount of numbers in your set:3
Enter the numbers in your set (1-100): 
Enter a number: 2
Enter a number: 3
Enter a number: 4
The set contents..
1 

 MENU
-----------------------------------------
A) Union of your set with another
B) Intersection of a set with another
C) Difference between sets 
D) Symmetric difference between sets 
E) Verify if two sets are equal 
F) Print your current set 
G) Exit the program 
Enter your choice: e
Enter the numbers in your second set: 
Enter the amount of numbers in your set:3
Enter the numbers in your set (1-100): 
Enter a number: 1
Enter a number: 2
Enter a number: 3
Sets are equal!
 MENU
-----------------------------------------
A) Union of your set with another
B) Intersection of a set with another
C) Difference between sets 
D) Symmetric difference between sets 
E) Verify if two sets are equal 
F) Print your current set 
G) Exit the program 
Enter your choice: f
The set contents..
1 2 3 

 MENU
-----------------------------------------
A) Union of your set with another
B) Intersection of a set with another
C) Difference between sets 
D) Symmetric difference between sets 
E) Verify if two sets are equal 
F) Print your current set 
G) Exit the program 
Enter your choice: g
*/ 