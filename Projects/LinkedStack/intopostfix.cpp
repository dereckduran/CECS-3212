#include "LinkedStack.h"
#include <iostream>
#include <string>

using namespace std;

string toPostfix(LinkedStack<char>&, string&);
int precendence(char);

int main()
{
    LinkedStack<char> myOperands;
    string infixed, post;
    char choice;
    cout << "This program turns infix expressions to postfix algebraic expressions..." << endl;
    do {
        cout << "Would you like to run the program (Y/N): ";
        cin >> choice;
       
        if (toupper(choice) == 'Y'){
        cout << endl << "Please enter the algebraic experession you would like to turn to post fix: ";
        cin >> infixed;

        post = toPostfix(myOperands, infixed);
        cout << post << endl;
        }
        else 
            break;

    } while (toupper(choice) != 'N');

    cout << "Thank you for your patience..." << endl << endl;

    return 0;
}
int precendence(char sign)
{
    if (sign == '*' || sign == '/')
        return 2;
    else if (sign == '+' || sign == '-')
        return 1;
    else 
        return 0;
}
string toPostfix(LinkedStack<char>& _aStack, string& infixexp){
    string postfixed;
    int i = 0;
    while(infixexp[i] != '\0')
    {
        char c = infixexp[i];
        if(isalnum(c))
            postfixed += c;
        else if (c == '(')
            _aStack.push(c);
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            while(!_aStack.isEmpty() && _aStack.peek() != '(' && precendence(c) <= precendence(_aStack.peek()))
            {
                postfixed += _aStack.peek(); 
                _aStack.pop();
            }
            _aStack.push(c);
        }
        else if (c == ')')
        {
            while(_aStack.peek() != '(' && !_aStack.isEmpty())
            {
                postfixed += _aStack.peek();
                _aStack.pop();
            }
            _aStack.pop();
        }
        i++;
    }
    while(!_aStack.isEmpty())
    {
        postfixed += _aStack.peek();
        _aStack.pop();
    }
    return postfixed;
}
/*
This program turns infix expressions to postfix algebraic expressions...
Would you like to run the program (Y/N): y

Please enter the algebraic experession you would like to turn to post fix: a-b+c
ab-c+
Would you like to run the program (Y/N): y

Please enter the algebraic experession you would like to turn to post fix: a-(b/c*d)
abc/d*-
Would you like to run the program (Y/N): y

Please enter the algebraic experession you would like to turn to post fix: a/(b*c)
abc
Would you like to run the program (Y/N): y

Please enter the algebraic experession you would like to turn to post fix: a/b/c-(d+e)*f
ab/c/de+f*-
Would you like to run the program (Y/N): y

Please enter the algebraic experession you would like to turn to post fix: (a+b)*c
ab+c*
Would you like to run the program (Y/N): y

Please enter the algebraic experession you would like to turn to post fix: a*(b/c/d)+e
abc/d/*e+
Would you like to run the program (Y/N): y

Please enter the algebraic experession you would like to turn to post fix: a-(b+c)
abc+-
Would you like to run the program (Y/N): y

Please enter the algebraic experession you would like to turn to post fix: a-(b+c*d)/e
abcd*+e/-
Would you like to run the program (Y/N): n
Thank you for your patience... 
*/