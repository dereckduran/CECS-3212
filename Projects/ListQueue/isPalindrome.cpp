#include <iostream>
#include "ListQueue.h"
#include "LinkedStack.h"
#include <string>

using namespace std;

bool isPalindrome(string &_aString);
int main() 
{
    string eval;
    getline(cin, eval);
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

    int length = _aString.length();
    int mid = length / 2;
    for (int index = 0; index < mid; index++)
    {
        char nextChar = _aString[index];
        myQ.enqueue(nextChar);
    }

    if (length % 2 == 0)
    {
        mid++;
    }

    for (int index = mid; index < length; index++)
    {
        char nextChar = _aString[index];
        myS.push(nextChar);
    }
    bool charAreEqual = true;

    while(!myQ.isEmpty() && charAreEqual)
    {
        char queueFront = myQ.peekFront();
        char stackTop = myS.peek();

        cout << "Q: " << char(queueFront) << ", S: "<< char(stackTop) << endl;
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
/*

radar
Q: r, S: r
Q: a, S: a
Palindrome.

abcda
Q: a, S: a
Q: b, S: d
Not palindrome.

*/