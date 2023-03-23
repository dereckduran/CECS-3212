#include "Term.h"
#include "Polynomial.h"
#include <iostream>
using namespace std;


int main(){
    Polynomial poly1, poly2, result;

    cin >> poly1;
    cout << poly1 << endl;
    cout << "The degree is: "<< poly1.degree() <<endl;

    cout <<"Changing coefficient with the power of three..."<<endl;
    poly1.changeCoefficient(2,3);

    cout << "The polynomial: " << poly1 << endl;
    cout << "Fetching coefficient with power of three...";
    cout << poly1.coefficient(3) << endl;;

    cout << "The polynomial: ";

    cout << poly1 << endl;

    cout << "Enter the information for the second polynomial: " << endl;
    cin >> poly2;

    cout << "The polynomials:" << endl << poly1 << endl << poly2 << endl; 

    cout << "Summing..." << endl << endl;
    result = poly1 + poly2;

    cout << "Result: " << result << endl;

    return 0;

}

/*

Enter how many terms your polynomial has:5
Term 1
Enter the coefficient for the term: 1
Enter the exponent of the term: 2
Term 2
Enter the coefficient for the term: 1
Enter the exponent of the term: 3
Term 3
Enter the coefficient for the term: 1
Enter the exponent of the term: 4
Term 4
Enter the coefficient for the term: 1
Enter the exponent of the term: 5
Term 5
Enter the coefficient for the term: 1
Enter the exponent of the term: 6
1x^2 + 1x^3 + 1x^4 + 1x^5 + 1x^6
The degree is: 6
Changing coefficient with the power of three...
The polynomial: 1x^2 + 1x^6 + 1x^4 + 1x^5 + 2x^3
Fetching coefficient with power of three...2
The polynomial: 1x^2 + 1x^6 + 1x^4 + 1x^5 + 2x^3
Enter the information for the second polynomial: 
Enter how many terms your polynomial has:5
Term 1
Enter the coefficient for the term: 3
Enter the exponent of the term: 2
Term 2
Enter the coefficient for the term: 3
Enter the exponent of the term: 3
Term 3
Enter the coefficient for the term: 3
Enter the exponent of the term: 4
Term 4
Enter the coefficient for the term: 3
Enter the exponent of the term: 5
Term 5
Enter the coefficient for the term: 3
Enter the exponent of the term: 6
The polynomials:
1x^2 + 1x^6 + 1x^4 + 1x^5 + 2x^3
3x^2 + 3x^3 + 3x^4 + 3x^5 + 3x^6

Result: 4x^2 + 4x^6 + 4x^4 + 4x^5 + 5x^3
*/