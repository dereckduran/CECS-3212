#include "PersonInfo.h"
#include "PersonDB.h"
#include <iostream>
using namespace std;

void displayMenu();
void run();
int main()
{
    run();
    return 0;
}


void displayMenu()
{
    cout << "\n MENU\n";
    cout << "-----------------------------------------\n";
    cout << "A) Disponer los contactos por orden de cumpleaños\n";
    cout << "B) Añadir un contacto\n";
    cout << "C) Remover un contacto\n";
    cout << "D) Modificar un contacto\n";
    cout << "E) Buscar una persona\n";
    cout << "F) Exit the program \n";
    cout << "Enter your choice: ";
}
void run(){
    PeopleDatabase contacts;
    PersonInfo tempPerson;
    char choice;
    do {
        // Display the menu and get a valid selection. 
        displayMenu();
        cin >> choice;
        while (toupper(choice) < 'A' || toupper(choice) > 'F') 
        {
        cout << "Please make a choice in the range " << "of A through E:";
        cin >> choice;
        }
        // Process the user's menu selection. 
        switch(choice)
        {
            case 'a':
            case 'A':   cout << contacts;
                        break;

            case 'b':
            case 'B':
                        cin.ignore();
                        cin >> contacts;
                
                        break;

            case 'c':
            case 'C': 
                        cout << "Enter the person to be removed from the contacts: \n";
                        cin.ignore();
                        cin >> tempPerson;
                        contacts.removePerson(tempPerson);
  
                        break;

            case 'd':
            case 'D':
                        cin.ignore();
                        cout << "Enter the information of the person you would like to modify: \n";
                        cin >> tempPerson;
                        contacts.modifyPerson(tempPerson);
                        break;

            case 'e':
            case 'E':
                        cin.ignore();
                        cout << "Enter the details of the person you would like to search for: \n";
                        cin >> tempPerson;
                        contacts.search(tempPerson);
                        break;
                
        }
    } while (toupper(choice) != 'F');
}


/* 
 MENU
-----------------------------------------
A) Disponer los contactos por orden de cumpleaños
B) Añadir un contacto
C) Remover un contacto
D) Modificar un contacto
E) Buscar una persona
F) Exit the program 
Enter your choice: a
Your contacts are empty...
 MENU
-----------------------------------------
A) Disponer los contactos por orden de cumpleaños
B) Añadir un contacto
C) Remover un contacto
D) Modificar un contacto
E) Buscar una persona
F) Exit the program 
Enter your choice: b
Please enter the person you would like to add to your contacts...
Enter person's name: Dereck Duran
Enter Dereck Duran's birthday: 
Month: 3
Day: 21
Year:2020

 MENU
-----------------------------------------
A) Disponer los contactos por orden de cumpleaños
B) Añadir un contacto
C) Remover un contacto
D) Modificar un contacto
E) Buscar una persona
F) Exit the program 
Enter your choice: a
Person's name: Dereck Duran Birthday: 3 / 21 / 2020


 MENU
-----------------------------------------
A) Disponer los contactos por orden de cumpleaños
B) Añadir un contacto
C) Remover un contacto
D) Modificar un contacto
E) Buscar una persona
F) Exit the program 
Enter your choice: b
Please enter the person you would like to add to your contacts...
Enter person's name: Khiry   
Enter Khiry's birthday: 
Month: 5
Day: 5
Year:1989

 MENU
-----------------------------------------
A) Disponer los contactos por orden de cumpleaños
B) Añadir un contacto
C) Remover un contacto
D) Modificar un contacto
E) Buscar una persona
F) Exit the program 
Enter your choice: a
Person's name: Khiry Birthday: 5 / 5 / 1989

Person's name: Dereck Duran Birthday: 3 / 21 / 2020


 MENU
-----------------------------------------
A) Disponer los contactos por orden de cumpleaños
B) Añadir un contacto
C) Remover un contacto
D) Modificar un contacto
E) Buscar una persona
F) Exit the program 
Enter your choice: b
Please enter the person you would like to add to your contacts...
Enter person's name: Adam 
Enter Adam's birthday: 
Month: 10
Day: 31
Year:2015

 MENU
-----------------------------------------
A) Disponer los contactos por orden de cumpleaños
B) Añadir un contacto
C) Remover un contacto
D) Modificar un contacto
E) Buscar una persona
F) Exit the program 
Enter your choice: a
Person's name: Khiry Birthday: 5 / 5 / 1989

Person's name: Adam Birthday: 10 / 31 / 2015

Person's name: Dereck Duran Birthday: 3 / 21 / 2020


 MENU
-----------------------------------------
A) Disponer los contactos por orden de cumpleaños
B) Añadir un contacto
C) Remover un contacto
D) Modificar un contacto
E) Buscar una persona
F) Exit the program 
Enter your choice: e
Enter the details of the person you would like to search for: 
Enter person's name: Dereck Duran
Enter Dereck Duran's birthday: 
Month: 3
Day: 21
Year:2020
Dereck Duran was found in your contacts!

 MENU
-----------------------------------------
A) Disponer los contactos por orden de cumpleaños
B) Añadir un contacto
C) Remover un contacto
D) Modificar un contacto
E) Buscar una persona
F) Exit the program 
Enter your choice: d
Enter the information of the person you would like to modify: 
Enter person's name: Dereck Duran
Enter Dereck Duran's birthday: 
Month: 3
Day: 21
Year:2020
Enter the details you would like to modify: 
Enter person's name: Dereck Duran
Enter Dereck Duran's birthday: 
Month: 3
Day: 21
Year:2001

 MENU
-----------------------------------------
A) Disponer los contactos por orden de cumpleaños
B) Añadir un contacto
C) Remover un contacto
D) Modificar un contacto
E) Buscar una persona
F) Exit the program 
Enter your choice: a
Person's name: Khiry Birthday: 5 / 5 / 1989

Person's name: Dereck Duran Birthday: 3 / 21 / 2001

Person's name: Adam Birthday: 10 / 31 / 2015


 MENU
-----------------------------------------
A) Disponer los contactos por orden de cumpleaños
B) Añadir un contacto
C) Remover un contacto
D) Modificar un contacto
E) Buscar una persona
F) Exit the program 
Enter your choice: f
*/