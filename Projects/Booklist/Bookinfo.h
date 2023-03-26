#ifndef BOOKINFO_H
#define BOOKINFO_H
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class BookInfo{
    private:
        string title;
        string author;
        string publisher;
    public:
        //constructor and destructor 
        BookInfo();
        BookInfo(string, string, string);
        BookInfo(const BookInfo& );
        ~BookInfo();

        //metodos
        void setTItle(string);
        void setAuthor(string);
        void setPublisher(string);
        void setBookInfo(string, string, string);
        string getTitle() const;
        string getAuthor();
        string getPublisher();

        //overloaded operators
        friend ostream& operator<<(ostream& out, const BookInfo&);
        friend istream& operator>>(istream& in, BookInfo&);
    
};

BookInfo::BookInfo()
{
    title = "";
    author = "";
    publisher = "";

}

BookInfo::BookInfo(string newtitle, string newauthor, string newpublisher)
{
    title = newtitle;
    author = newauthor;
    publisher = newpublisher;
}

BookInfo::BookInfo(const BookInfo &obj)
{
    this->setTItle(obj.title);
    this->setAuthor(obj.author);
    this->setPublisher(obj.publisher);
}

BookInfo::~BookInfo()
{
    cout<<"Book information was succesfully removed."<<endl;
}

void BookInfo::setTItle(string newtitle)
{
    title = newtitle;
}

void BookInfo::setAuthor(string newauthor)
{
    author = newauthor;
}

void BookInfo::setPublisher(string newpublisher)
{
    publisher = newpublisher;
}
void BookInfo::setBookInfo(string newtitle, string newauthor, string newpublisher)
{
    this->setTItle(newtitle);
    this->setAuthor(newauthor);
    this->setPublisher(newpublisher);
}
string BookInfo::getTitle() const
{
    return title;
}

string BookInfo::getAuthor()
{
    return author;
}

string BookInfo::getPublisher()
{
    return publisher;
}

ostream &operator<<(ostream &out, const BookInfo &obj)
{
    out << setw(10) << "Book information: " <<endl; 
    out<< setw(15) << "Title: " << setw(20) << obj.title << endl;
    out<< setw(15) << "Author: " << setw(20) << obj.author << endl;
    out<< setw(15) << "Publisher: " << setw(20) << obj.publisher << endl;

    return out;
}

istream &operator>>(istream &in, BookInfo &obj)
{
    cout << "Please enter the pertinent information for the book: "<<endl;
    cout << "Title: ";
    getline(in, obj.title);
    cout << "Author: ";
    getline(in, obj.author);
    cout << "Publisher: ";
    getline(in, obj.publisher);

    return in;
}

#endif