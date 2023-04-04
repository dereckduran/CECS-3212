#include <iostream>
#include <string>
#include <cctype>
#include "LinkedStack.h"
using namespace std;

bool palindrome(LinkedStack<char> &, LinkedStack<char>&);
int main(){
    LinkedStack<char> stack1, stack2;
    int i = 0;

    string word;
    bool balanced;

    cout <<"Enter your word to be evaluated: ";
    cin >> word;
    for(i = 0; i < word.size() ; i++){
        stack1.push(word[i]);
    
    }

    while(!stack1.isEmpty()){
        stack2.push(stack1.peek());
        stack1.pop();
    }

    for(i = 0; i < word.size() ; i++){
        stack1.push(word[i]);
        
    }
    stack1.display();
    stack2.display();
    balanced = palindrome(stack1, stack2);
    if (!balanced) 
        cout << "Not palindrome" << endl;
    else
        cout << "Is a palindrome" << endl;
    
    return 0;
}

//palindrome
bool palindrome(LinkedStack<char> &stack1, LinkedStack<char> &stack2){
    while(!stack1.isEmpty()){
        if(tolower(stack1.pop()) != tolower(stack2.pop()))
            cout << "The word is not a palindrome"<<endl;
            return false;
    }
    cout << "The word is a palindrome." << endl;
    return true;
} 