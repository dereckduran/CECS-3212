#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int MAX_CAPACITY = 5;
class Book{
    private:
    int top;
    string books[MAX_CAPACITY];
    public:
    
    //constructors and destructor
    
    Book();
    
    Book(string [], int);
    
    Book(const Book&);
    
    ~Book();
    
    //methods 
    
    bool isEmpty();
    
    bool isFull();
    
    int getCurrentSize();
    
    void add(string );
    
    int contains(string );
    
    bool remove(string &);
    
    void display();
    
    //overloaded operators
    
    string &operator[](int );
    
    friend ostream& operator<<(ostream& out, const Book& obj);
    
    friend istream& operator>>(istream& in, Book& obj); 
};
Book::Book(){
    
    for(int i = 0; i < MAX_CAPACITY; i++){
        books[i] = " ";
    }
 
    top = 0;
}
Book::Book(string list[], int n){
    if (n > MAX_CAPACITY){
        cout << "The number of books cannot exceed the maximum capacity: " << MAX_CAPACITY << endl;
    }
    else{
        top = n;
        for(int i = 0; i < n; i++){
            books[i] = list[i];
        }
    }
        
}
Book::Book(const Book& temp){
    top = temp.top;
    for(int i = 0; i < temp.top; i++){
        books[i] = temp.books[i];
    }
}
Book::~Book(){}

bool Book::isEmpty(){
    return (top == 0);
}
bool Book::isFull(){
    return (top == MAX_CAPACITY);
}

int Book::getCurrentSize(){
    return top;
}

void Book::add(string newtitle){
    if(isFull()){
        cout << "The book list is full. Cannot exceed: " << MAX_CAPACITY << endl;
    }
    else {
        books[top] = newtitle;
        top++;
    }
}
int Book::contains(string _title){
    for(int i = 0; i < top; i++){
        if (books[i] == _title){
            return i;
        }
    }
    return -1;
}
bool Book::remove(string &remtitle){
    bool removed; 
    if(isEmpty()){
        cout << "There are no books in the list. "<< endl;
        removed = false;
        return removed;
    }
    int pos = contains(remtitle);
    if(pos == -1){
        cout << "The title was not found in the list. "<< endl;
        removed = false;
        return removed;
    }
    Book temp;

    //traspasando los libros que estan encima al arreglo temporero
    for(int i = pos + 1; i < top; i++){
        temp.add(books[i]);
    }
    //disminuyendo top 
    top--;

    //traspasando el contenido del objeto temporero de nuevo a la lista original usando el .top de la lista temporera
    for (int i = pos; i < temp.top; i ++){
        books[i] = temp.books[i];
        removed = true;
    }
    cout <<"The book has succesfully been removed." <<endl;
    return removed;
}

void Book::display(){
    if(isEmpty()){
        cout<< "There are no books in the list. " << endl;
    }
    else{
        for(int i = 0; i < top; i++){
            cout << books[i] << endl;
        }
    }
}

string& Book::operator[](int index){
    if(index  > top){
        cout << "Index out of bounds."<<endl;
        exit(1);
    }
    return books[index];
}

ostream& operator<<(ostream& out, const Book& obj){
    if(obj.top == 0){
        out << "There are no books in the list. " << endl;
        
    }
    else{
        out<< "List of books:" <<endl;
        for (int i = 0; i < obj.top; i++){
            out << setw(5) << "No. " << i + 1;
            out << setw(30) << obj.books[i] << endl;
        }
    }
    return out;
}
istream& operator>>(istream& in, Book& obj){
    int numOfBooks, i;
    string bookTitle;

    cout << "Enter the amount of books you would like to add:";
    in>> numOfBooks;

    if(numOfBooks > MAX_CAPACITY || numOfBooks + obj.top > MAX_CAPACITY){
        cout << "The number of books cannot exceed the maximum capacity for the list: " << MAX_CAPACITY << endl;
        exit(1);
    }
    else{
        in.ignore();
        for(i = obj.top; i < numOfBooks; i++){
            cout<< "Enter the book title you would like to add:";
            getline(in, bookTitle);
            obj.add(bookTitle);
        }
    }
    return in;
}

#endif 