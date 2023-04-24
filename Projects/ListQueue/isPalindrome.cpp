#include <iostream>
#include "ListQueue.h"
#include "LinkedStack.h"
#include <string>

using namespace std;

bool isPalindrome(string &_aString);
int main() 
{
    string eval = "lope";
    bool pali = isPalindrome(eval);

    if(pali)
        cout << "Palindrome.\n"; 
    else 
        cout << "Not palindrome.\n";

    return 0;
}


bool isPalindrome(string &_aString)
{
    ListQueue<char> myQ;
    LinkedStack<char> myS;

    int index = 0;
    while (_aString[index] != '\0')
    {
        char nextChar = _aString[index];
        myQ.enqueue(nextChar);
        myS.push(nextChar);
        index++;
    }

    bool charAreEqual = true;

    while(!myQ.isEmpty() and charAreEqual)
    {
        char queueFront = myQ.peekFront();
        char stackTop = myS.peek();

        if( queueFront == stackTop)
        {
            myQ.dequeue();
            myS.pop();
        }
        else 
            charAreEqual = false;
    }
    return charAreEqual;

}