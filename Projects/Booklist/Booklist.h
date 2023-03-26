#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int MAX_CAPACITY = 5;
class BookList{
    private:
    int top;
    string books[MAX_CAPACITY];
    public:
    
    //constructors and destructor
    
    BookList();
    
    BookList(string [], int);
    
    BookList(const BookList&);
    
    ~BookList();
    
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
    
    friend ostream& operator<<(ostream& out, const BookList& obj);
    
    friend istream& operator>>(istream& in, BookList& obj); 
};
BookList::BookList(){
    
    for(int i = 0; i < MAX_CAPACITY; i++){
    
    books[i] = " ";
    
    }
 
    top = 0;
}
BookList::BookList(string list[], int n){
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
BookList::BookList(const BookList& temp){
    top = temp.top;
    for(int i = 0; i < temp.top; i++){
        books[i] = temp.books[i];
    }
}
BookList::~BookList(){}

bool BookList::isEmpty(){
    return (top == 0);
}
bool BookList::isFull(){
    return (top == MAX_CAPACITY);
}

int BookList::getCurrentSize(){
    return top;
}

void BookList::add(string newtitle){
    if(isFull()){
        cout << "The book list is full. Cannot exceed: " << MAX_CAPACITY << endl;
    }
    else {
        books[top] = newtitle;
        top++;
    }
}
int BookList::contains(string _title){
    for(int i = 0; i < top; i++){
        if (books[i] == _title){
            return i;
        }
    }
    return -1;
}
bool BookList::remove(string &remtitle){
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
    BookList temp;

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

void BookList::display(){
    if(isEmpty()){
        cout<< "There are no books in the list. " << endl;
    }
    else{
        for(int i = 0; i < top; i++){
            cout << books[i] << endl;
        }
    }
}

string& BookList::operator[](int index){
    if(index  > top){
        cout << "Index out of bounds."<<endl;
        exit(1);
    }
    return books[index];
}

ostream& operator<<(ostream& out, const BookList& obj){
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
istream& operator>>(istream& in, BookList& obj){
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