#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_CAPACITY = 5;
template <class T>
class BookList{
    private:
        int top;
        T books[MAX_CAPACITY];
        
    public:
        //constructors and destructor
        BookList();
        BookList(T [], int);
        BookList(const BookList<T>&);
        ~BookList();

        //methods 
        bool isEmpty();
        bool isFull();
        int getCurrentSize();
        void add(T );
        int contains(string ) const;
        bool remove(string );
        void display();


        //overloaded operators
        string &operator[](int );
        template <class U>
        friend ostream& operator<<(ostream& out, const BookList<U>& );
        template <class U>
        friend istream& operator>>(istream& in, BookList<U>&); 

};
template <class T>
BookList<T>::BookList(){
    top = 0;
    
}
template <class T>
BookList<T>::BookList(T list[], int n){
    if(n > MAX_CAPACITY){
        cout<<"The number of books cannot exceed the maximum capacity of the list: " << MAX_CAPACITY << endl;
    } else{
        top = n;
        for(int i = 0; i < n; i++){
            books[i] = list[i];
        }
    }
}
template <class T>
BookList<T>::BookList(const BookList<T>& temp){
    top = temp.top;
    for(int i = 0; i < temp.top; i ++){
        books[i] = temp.books[i];
    }
}
template <class T>
BookList<T>::~BookList(){
    
}
template <class T>
bool BookList<T>::isEmpty(){
   return top == 0;
    
}

template <class T>
bool BookList<T>::isFull()
{   
    return top == MAX_CAPACITY;
        
}
template <class T>
int BookList<T>::getCurrentSize()
{
    return top;
}
template <class T>
void BookList<T>::add(T newtitle)
{
    if(!isFull()){
        books[top] = newtitle;
        top++;
    } else {
        cout<< "The book list is currently full. Cannot exceed: " << MAX_CAPACITY << endl;
    }

}
template <class T>
int BookList<T>::contains(string title) const
{
    for (int i = 0; i < top; i++){
        if (books[i].getTitle() == title){
            return i;
        }
    }
    return -1;
}
template <class T>
bool BookList<T>::remove(string _title)
{
    //making a flag to return whether the title was removed 
    bool removed;
    //verificando si la lista tiene elementos
    if(isEmpty()){
        cout << "There are no books in the list." << endl;
        removed = false;
        return removed;
    }

    //buscando la posición del libro en la lista
    int pos = contains(_title);
    if(pos == -1){
        cout<<"The book was not found in the list."<<endl;
        removed = false;
        return removed;
    }
    //lista temporera
    BookList<T> temp; 
    
    //empezamos despues de la posicion para anadir los libros que estan encima a la lista temporera
    for (int i = pos + 1; i < top; i++){
        temp.add(books[i]);
    }
    //decrementando el valor de top que indica la cnatidad de libros
    top--;
    //ahora de nuevo copiamos los elementos de la lista temporero de nuevo a books 
    for(int i = 0; i < temp.top; i++){
        books[i] = temp.books[i];
    }
    
    cout<< "Book title removed successfully."<< endl;
    return removed;
}
template <class T>
void BookList<T>::display()
{
    if(isEmpty()){
        cout<< "There are no books in the list." <<endl;
    }
    else {
        for(int i = top; i > 0; i--){
            cout<< books[i] << endl;
        }
    }
}
template <class T>
string& BookList<T>::operator[](int index){
    //is this correct?
    if (index > top){
        cout<< "Index out of bounds."<<endl;
        exit(1);
    }
    return books[index];
}
template <class T>
ostream& operator<<(ostream& out, const BookList<T>& obj){
    //verificando si hay libros en la lista primero 
    if (obj.top == 0){
        out<< "There are no books in the list." <<endl;
    }
    else{
        out << "List of books:" << endl;
        for(int i = 0; i < obj.top; i++) {
            out << obj.books[i];
        }
    }
    return out;
}
template <class T>
istream& operator>>(istream& in, BookList<T>& obj){
    T book;
    int numofbooks;
    cout <<"Enter the amount of books you would like to add to the list: " <<endl;
    in>>numofbooks;

    in.ignore();
    if (obj.isFull() || numofbooks > MAX_CAPACITY || numofbooks + obj.top > MAX_CAPACITY){
        cout<< "The list cannot exceed max capacity: " << MAX_CAPACITY <<endl;
        while (numofbooks > MAX_CAPACITY){
            cout << "Please try again." << endl;
            in >> numofbooks;
        }
    }
    in.ignore();
    for (int i = 0; i < numofbooks; i++){
        in>> book;
        obj.add(book);
    }
    return in;
}
#endif