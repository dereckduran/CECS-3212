#include <iostream>
#include "ArrayStack.h"
using namespace std;

int main() {
    ArrayStack<int> stack1, stack2; 
    int stackTop;
    stack1.push(1);
    stack1.push(2);
    stack2.push(3); 
    stack2.push(4); 
    stack1.pop();
    stackTop = stack2.peek(); 
    stack1.push(stackTop); 
    stack1.push(5); 
    stack2.pop(); 
    stack2.push(6);
    stack1.display();
    stack2.display();
    return 0;
}


/*
// Checks the string aString to verify that braces match.
// Returns true if aString contains matching braces, false otherwise. checkBraces(aString: string): boolean
aStack = a new empty stack balancedSoFar = true
i= 0
while (balancedSoFar and i < length of aString) {
ch = character at position i in aString i++
// Push an open brace if (ch is a '{')
             aStack.push('{')
// Close brace
else if (ch is a '}') {
if (!aStack.isEmpty())
aStack.pop() // Pop a matching open brace
else // No matching open brace balancedSoFar = false
}
// Ignore all characters other than braces }
if (balancedSoFar and aStack.isEmpty()) aString has balanced braces
else
aString does not have balanced braces
*/