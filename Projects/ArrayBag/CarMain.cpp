#include <iostream>
#include<string>
using namespace std;
#include "ArrayBag.h"
#include "Car.h"
int main()
{
    ArrayBag<Car> bagCars;
    Car carrito;
    int i,n ;
    cout<< "Pleas enter amount of cars: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> carrito;
        bagCars.add(carrito);
    }
        cout << "El contenido del bag: ";
    for (i = 0; i < bagCars.getCurrentSize(); i++)
    {
        cout << bagCars.getElement(i) << endl;
    }
    system("pause");
    return 0;
}