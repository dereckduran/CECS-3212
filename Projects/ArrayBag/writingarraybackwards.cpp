/** Writes the characters in an array backward.
@pre The array anArray contains size characters, where size >= 0. @post None.
@param anArray The array to write backward.
@param first The index of the first character in the array.
@param last The index of the last character in the array. */

#include <iostream>
#include <string>
using namespace std;
void writeArrayBackward(const char [], int , int);

int recursivepower(int , int);
int main(){
    char name[256];
    int number = recursivepower(2, 3);
    cout<< "Recursive power function output:" << number <<endl;

    cout<< "Please enter your name: ";
    cin>> name;
    cout<<"Your name backwards:";
    writeArrayBackward(name, 0, strlen(name) - 1);

    return 0; 
}
void writeArrayBackward(const char anArray[], int first, int last){
    if (first <= last) 
    {
        // Write the last character
        cout << anArray[last];
        // Write the rest of the array backward
        writeArrayBackward(anArray, first, last - 1); 
    } // end if
// first > last is the base case - do nothing 
} // end writeArrayBackward
/*Write a function that uses recursion to raise a number to a power. 
The function should accept two arguments: the number to be raised and the exponent. 
Assume that the exponent is a nonnegative integer. Demonstrate the function in a program.*/

int recursivepower(int number, int exponent){
    if (exponent == 0)
        return 1;
    else 
        return number * recursivepower(number, exponent - 1);
}

/* 
+++++++++++++++OUTPUT+++++++++++++++++
Recursive power function output:8
Please enter your name: Dereck
Your name backwards:kcereD
*/