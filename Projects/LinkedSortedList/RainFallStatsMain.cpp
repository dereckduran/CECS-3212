#include "RainFallStatistics.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{
    RainFallYear myYear;

    cin >> myYear;
    cout << myYear;

    float totalRain = myYear.totalRainFall();

    cout << totalRain << endl;

    cout << "The months with the most rain fall...\n";
    myYear.maxRainFallMonths();

    cout << "The months with the least rain fall...\n";
    myYear.minRainFallMonths();

    return 0;
}