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

    cout << "The average rainfall for the year...\n";
    myYear.avgRainFall();

    return 0;
}
/*
Enter the rainfall for each month of the year 
Enter the month name: Jan
Enter the rainfall for the month: 10
Enter the month name: Feb
Enter the rainfall for the month: 8
Enter the month name: March
Enter the rainfall for the month: 6
Enter the month name: April
Enter the rainfall for the month: 4
Enter the month name: May
Enter the rainfall for the month: 3
Enter the month name: June
Enter the rainfall for the month: 2
Enter the month name: July
Enter the rainfall for the month: 2
Enter the month name: August
Enter the rainfall for the month: 5
Enter the month name: September
Enter the rainfall for the month: 6
Enter the month name: October
Enter the rainfall for the month: 10
Enter the month name: November
Enter the rainfall for the month: 9
Enter the month name: December
Enter the rainfall for the month: 10
Month: December   Rainfall: 10
Month: October   Rainfall: 10
Month: Jan   Rainfall: 10
Month: November   Rainfall: 9
Month: Feb   Rainfall: 8
Month: September   Rainfall: 6
Month: March   Rainfall: 6
Month: August   Rainfall: 5
Month: April   Rainfall: 4
Month: May   Rainfall: 3
Month: July   Rainfall: 2
Month: June   Rainfall: 2
75
The months with the most rain fall...
Month: June   Rainfall: 2
Month: July   Rainfall: 2
The months with the least rain fall...
Month: Jan   Rainfall: 10
Month: October   Rainfall: 10
Month: December   Rainfall: 10
The average rainfall for the year...
6.25
*/