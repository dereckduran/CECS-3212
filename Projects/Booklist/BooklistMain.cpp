#include "Booklist.h"
#include <iostream>
#include <string>

using namespace std;

void displayMenu();
int main(){
    Book myBooks;
    char choice;
    string bookTitle;

    do {
        // Display the menu and get a valid selection. 
        displayMenu();
        cin >> choice;
        while (toupper(choice) < 'A' || toupper(choice) > 'F') {
        cout << "Please make a choice in the range " << "of A through G:";
        cin >> choice; }
        // Process the user's menu selection. 
        switch(choice)
        {
            case 'a':
            case 'A': cout << myBooks <<endl;
            break;

            case 'b':
            case 'B': 
                cout << "Enter the title of the book you would like to add: ";
                cin.ignore();
                getline(cin, bookTitle);
                myBooks.add(bookTitle);
                cout << myBooks;
            break;

            case 'c':
            case 'C':
                cout <<"Enter the title of the book you would like to search for: ";
                cin.ignore();
                getline(cin, bookTitle);
                if(myBooks.contains(bookTitle) == -1){
                    cout << "Book not found." << endl;
                }
                else{
                    cout << "Book found at position: " << myBooks.contains(bookTitle) + 1 << endl;
                }
            break;

            case 'd':
            case 'D':
                cout << "The current size of the list is: " << myBooks.getCurrentSize() << ". The current max capcity is: "<< MAX_CAPACITY;
                
            break;
            case 'e':
            case 'E':
                
                cout << "Enter the title of the book you would like to remove: ";
                cin.ignore();
                getline(cin, bookTitle);
                myBooks.remove(bookTitle);
                cout << myBooks;
            break; }
        }
        while (toupper(choice) != 'F');
    return 0;
}

void displayMenu()
{
    cout << "\n MENU\n";
    cout << "-----------------------------------------\n";
    cout << "A) Display the book list\n";
    cout << "B) Add a book\n";
    cout << "C) Constains a book title\n";
    cout << "D) Current Size of the list\n";
    cout << "E) Remove a book\n";
    cout << "F) Exit the program\n";
    cout << "Enter your choice: ";
}
/*
MENU
-----------------------------------------
A) Display the book list
B) Add a book
C) Constains a book title
D) Current Size of the list
E) Remove a book
F) Exit the program
Enter your choice: b
Enter the title of the book you would like to add: Cocina Criolla
List of books:
 No. 1                      Vagabond
 No. 2          Cien Anos de Soledad
 No. 3                       Berserk
 No. 4        Thinking Fast and Slow
 No. 5                Cocina Criolla
 MENU
-----------------------------------------
A) Display the book list
B) Add a book
C) Constains a book title
D) Current Size of the list
E) Remove a book
F) Exit the program
Enter your choice: a
List of books:
 No. 1                      Vagabond
 No. 2          Cien Anos de Soledad
 No. 3                       Berserk
 No. 4        Thinking Fast and Slow
 No. 5                Cocina Criolla
 MENU
-----------------------------------------
A) Display the book list
B) Add a book
C) Constains a book title
D) Current Size of the list
E) Remove a book
F) Exit the program
Enter your choice: c
Enter the title of the book you would like to search for: Berserk
Book found at position: 3
 MENU
-----------------------------------------
A) Display the book list
B) Add a book
C) Constains a book title
D) Current Size of the list
E) Remove a book
F) Exit the program
Enter your choice: d
The current size of the list is: 5. The current max capcity is: 5
 MENU
-----------------------------------------
A) Display the book list
B) Add a book
C) Constains a book title
D) Current Size of the list
E) Remove a book
F) Exit the program
Enter your choice: e
Enter the title of the book you would like to remove: Berserk
The book has succesfully been removed.
List of books:
 No. 1                      Vagabond
 No. 2          Cien Anos de Soledad
 No. 3        Thinking Fast and Slow
 No. 4                Cocina Criolla
 MENU
-----------------------------------------
A) Display the book list
B) Add a book
C) Constains a book title
D) Current Size of the list
E) Remove a book
F) Exit the program
Enter your choice: e
Enter the title of the book you would like to remove: Berserk
The title was not found in the list. 
List of books:
 No. 1                      Vagabond
 No. 2          Cien Anos de Soledad
 No. 3        Thinking Fast and Slow
 No. 4                Cocina Criolla
 MENU
-----------------------------------------
A) Display the book list
B) Add a book
C) Constains a book title
D) Current Size of the list
E) Remove a book
F) Exit the program
Enter your choice: f
*/