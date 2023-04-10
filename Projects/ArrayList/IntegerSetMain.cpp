#include "IntegerSet.h"
#include <iostream>

using namespace std;

int main()
{
    IntegerSet setA, setB, resultSet;
    cout << "Enter numbers for set A \n";
    cin >> setA;
    cout << "Set A: \n";
    cout << setA;
    cout << "Enter numbers for set B \n";
    cin >> setB;
    cout << "Set B: \n";
    cout << setB;

    cout << "The intersection of sets: \n"; 
    resultSet = setA.setUnion(setB);
    cout << resultSet;
    
    cout << "Getting the difference between sets (elements in A but not B): \n";
    setA = setA.difference(setB);
    cout << setA;
    return 0;
}
