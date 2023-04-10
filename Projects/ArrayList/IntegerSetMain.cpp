#include "IntegerSet.h"
#include <iostream>

using namespace std;

int main()
{
    IntegerSet setA, setB, resultSet;
    bool setareequal;
    cout << "Enter numbers for set A \n";
    cin >> setA;
    cout << "Set A: \n";
    cout << setA;
    cout << "Enter numbers for set B \n";
    cin >> setB;
    cout << "Set B: \n";
    cout << setB;

    
    setareequal = setA == setB;
    if (setareequal)
        cout << "Sets are equal \n";
    else 
        cout << "Sets are not equal \n";
    
    return 0;
}
