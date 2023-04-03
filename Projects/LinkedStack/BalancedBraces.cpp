#include <iostream>
#include "ArrayStack.h"
#include <string>
#include <iomanip>

using namespace std;

bool balanced(ArrayStack<char> &, string &);
string getString();

int main(){
    ArrayStack<char> myBraces;
    string s; 
    bool balance; 
    cout << setw(100) <<"The following program evaluates a string to determine if the braces are balances... " << endl;
    s = getString();
    balance = balanced(myBraces, s);
    cout << "Thank you for your patience."<< endl;

    return 0;
}


string getString(){
    string s;
    cout << "Please enter the string you would like to evaluate: ";
    getline(cin, s);
    return s;
}

bool balanced(ArrayStack<char> & myStack, string & _aString)
{
    int i = 0;
    bool balanced = true;

    //adding characters to stack
    while(_aString[i] != '\0')
    {   
        //pushing if character is a brace
        if((_aString[i] == '{') || (_aString[i] == '[') || (_aString[i] == '('))
            myStack.push(_aString[i]);
        //popping if it is not empty and is a closing brace 
        else if (_aString[i] == '}')
        {
            if(!myStack.isEmpty())
            {
                if(myStack.peek() != '{')
                    balanced = false;
                myStack.pop();
            }
        }
        else if(_aString[i] == ']'){
            if(!myStack.isEmpty())
            {
                if(myStack.peek() != '[')
                    balanced = false;
                myStack.pop();
            }
        }
         else if(_aString[i] == ')'){
            if(!myStack.isEmpty())
            {
                if(myStack.peek() != '(')
                    balanced = false;
                myStack.pop();
            }
        }

        i++;
    }
    if (myStack.isEmpty() && balanced == true)
    {
        cout << "Braces are balanced!" << endl;
        return balanced;
    }
    else 
    {   
        cout << "Braces are not balanced..." << endl;
        return balanced;
    }
}
/*
{ab(c[d])e} 

 The following program evaluates a string to determine if the braces are balances... 
Please enter the string you would like to evaluate: {ab(c[d])e} 
Braces are balanced!
Thank you for your patience.


The following program evaluates a string to determine if the braces are balances... 
Please enter the string you would like to evaluate: {ab(c))
Braces are not balanced...
Thank you for your patience.
*/