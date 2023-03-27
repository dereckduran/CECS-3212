#include "Book.h"
#include "Bookinfo.h"
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
    cout << "A) Display the book list\n";
    cout << "B) Add a book\n";
    cout << "C) Constains a book title\n";
    cout << "D) Current Size of the list\n";
    cout << "E) Remove a book\n";
    cout << "F) Exit the program\n";
    cout << "Enter your choice: ";
}
void run(){
    BookList<BookInfo> myBooks;
    BookInfo bookTitle;
    string _title;
    char choice;
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
                if (myBooks.isFull()){
                    cout << "Cannot add more books because the list is full. Max capacity: 5" << endl; 
                }
                else {
                cout << "Enter the title of the book you would like to add: " <<endl;
                cin.ignore();
                cin >> bookTitle;
                myBooks.add(bookTitle);
                cout << myBooks;}
            break;

            case 'c':
            case 'C':
                cout <<"Enter the title of the book you would like to search for: " << endl;
                cin.ignore();
                cin >> _title;
                if(myBooks.contains(_title) == -1){
                    cout << "Book not found." << endl;
                }
                else{
                    cout << "Book found at position: " << myBooks.contains(_title) + 1 << endl;
                }
            break;

            case 'd':
            case 'D':
                cout << "The current size of the list is: " << myBooks.getCurrentSize() << ". The current max capcity is: "<< MAX_CAPACITY;
                
            break;
            case 'e':
            case 'E':
                if (!myBooks.isEmpty()){
                    cout << "Enter the title of the book you would like to remove: " <<endl;
                    cin.ignore();
                    cin >> _title;
                    myBooks.remove(_title);
                    cout << myBooks;
                    }
                else    
                    cout << "Cannot remove books from an empty list..." << endl;
            break; }
        }
        while (toupper(choice) != 'F');
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
Enter the title of the book you would like to add: 
Please enter the pertinent information for the book: 
Title: vagabond
Author: f
Publisher: f
Book information was succesfully removed.
List of books:
Book information: 
        Title:             vagabond
       Author:                    f
    Publisher:                    f

 MENU
-----------------------------------------
A) Display the book list
B) Add a book
C) Constains a book title
D) Current Size of the list
E) Remove a book
F) Exit the program
Enter your choice: b
Enter the title of the book you would like to add: 
Please enter the pertinent information for the book: 
Title: cocina criolla
Author: f
Publisher: f
Book information was succesfully removed.
List of books:
Book information: 
        Title:             vagabond
       Author:                    f
    Publisher:                    f
Book information: 
        Title:       cocina criolla
       Author:                    f
    Publisher:                    f

 MENU
-----------------------------------------
A) Display the book list
B) Add a book
C) Constains a book title
D) Current Size of the list
E) Remove a book
F) Exit the program
Enter your choice: b
Enter the title of the book you would like to add: 
Please enter the pertinent information for the book: 
Title: cien anos de soledad
Author: f
Publisher: f
Book information was succesfully removed.
List of books:
Book information: 
        Title:             vagabond
       Author:                    f
    Publisher:                    f
Book information: 
        Title:       cocina criolla
       Author:                    f
    Publisher:                    f
Book information: 
        Title: cien anos de soledad
       Author:                    f
    Publisher:                    f

 MENU
-----------------------------------------
A) Display the book list
B) Add a book
C) Constains a book title
D) Current Size of the list
E) Remove a book
F) Exit the program
Enter your choice: b
Enter the title of the book you would like to add: 
Please enter the pertinent information for the book: 
Title: berserk
Author: f
Publisher: f
Book information was succesfully removed.
List of books:
Book information: 
        Title:             vagabond
       Author:                    f
    Publisher:                    f
Book information: 
        Title:       cocina criolla
       Author:                    f
    Publisher:                    f
Book information: 
        Title: cien anos de soledad
       Author:                    f
    Publisher:                    f
Book information: 
        Title:              berserk
       Author:                    f
    Publisher:                    f

 MENU
-----------------------------------------
A) Display the book list
B) Add a book
C) Constains a book title
D) Current Size of the list
E) Remove a book
F) Exit the program
Enter your choice: b
Enter the title of the book you would like to add: 
Please enter the pertinent information for the book: 
Title: thinking fast and slow
Author: f
Publisher: f
Book information was succesfully removed.
List of books:
Book information: 
        Title:             vagabond
       Author:                    f
    Publisher:                    f
Book information: 
        Title:       cocina criolla
       Author:                    f
    Publisher:                    f
Book information: 
        Title: cien anos de soledad
       Author:                    f
    Publisher:                    f
Book information: 
        Title:              berserk
       Author:                    f
    Publisher:                    f
Book information: 
        Title: thinking fast and slow
       Author:                    f
    Publisher:                    f

 MENU
-----------------------------------------
A) Display the book list
B) Add a book
C) Constains a book title
D) Current Size of the list
E) Remove a book
F) Exit the program
Enter your choice: b
Cannot add more books because the list is full. Max capacity: 5

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
Book information: 
        Title:             vagabond
       Author:                    f
    Publisher:                    f
Book information: 
        Title:       cocina criolla
       Author:                    f
    Publisher:                    f
Book information: 
        Title: cien anos de soledad
       Author:                    f
    Publisher:                    f
Book information: 
        Title:              berserk
       Author:                    f
    Publisher:                    f
Book information: 
        Title: thinking fast and slow
       Author:                    f
    Publisher:                    f


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
Enter the title of the book you would like to remove: 
vagabond
Book information was succesfully removed.
Book information was succesfully removed.
Book information was succesfully removed.
Book information was succesfully removed.
Book title removed successfully.
Book information was succesfully removed.
Book information was succesfully removed.
Book information was succesfully removed.
Book information was succesfully removed.
Book information was succesfully removed.
List of books:
Book information: 
        Title:       cocina criolla
       Author:                    f
    Publisher:                    f
Book information: 
        Title: cien anos de soledad
       Author:                    f
    Publisher:                    f
Book information: 
        Title:              berserk
       Author:                    f
    Publisher:                    f
Book information: 
        Title: thinking fast and slow
       Author:                    f
    Publisher:                    f

 MENU
-----------------------------------------
A) Display the book list
B) Add a book
C) Constains a book title
D) Current Size of the list
E) Remove a book
F) Exit the program
Enter your choice: e
Enter the title of the book you would like to remove: 
vagabond
The book was not found in the list.
List of books:
Book information: 
        Title:       cocina criolla
       Author:                    f
    Publisher:                    f
Book information: 
        Title: cien anos de soledad
       Author:                    f
    Publisher:                    f
Book information: 
        Title:              berserk
       Author:                    f
    Publisher:                    f
Book information: 
        Title: thinking fast and slow
       Author:                    f
    Publisher:                    f

 MENU
-----------------------------------------
A) Display the book list
B) Add a book
C) Constains a book title
D) Current Size of the list
E) Remove a book
F) Exit the program
Enter your choice: f
Book information was succesfully removed.
Book information was succesfully removed.
Book information was succesfully removed.
Book information was succesfully removed.
Book information was succesfully removed.
Book information was succesfully removed.*/