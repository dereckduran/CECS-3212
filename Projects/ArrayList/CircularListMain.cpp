
#include <iostream>
#include "CircularList.h"
using namespace std;

void menu(int &choice)
{
    cout << "---Menu---" << endl;
    cout <<"1. Add item"<< endl
    <<"2. Remove" << endl
    <<"3. Reverse List" << endl
    <<"4. Display" << endl
    <<"5. Quit" << endl;
    
    cin>> choice;
}

int main()
{
    CircularList<int> myCircle;
    int choice, num, pos = 0;
    
    do {
        menu(choice);
        switch (choice)
        {
            case 1:
                cout<< "---------------" << endl;
                pos++;
                cout << "Enter number: ";
                cin>> num;
                myCircle.insert(pos, num);
                myCircle.display();
                break;
            case 2:
                cout<< "---------------" << endl;
                cout << "Enter node to remove: ";
                cin>> num;
                myCircle.remove(num);
                myCircle.display();
                pos--;
                break;
            case 3:
                cout << "Reversing List..." << endl;
                myCircle.reverseList();
                break;
            case 4:
                cout<< "---------------" << endl;
                cout << "Displaying list..." << endl;
                myCircle.display();
                break;
            case 5:
                break;
            default:
                break;
        }
    } while (choice != 5);
    return 0;
}

/* 

OUTPUT 

---Menu---
1. Add item
2. Remove
3. Reverse List
4. Display
5. Quit
1
---------------
Enter number: 30
30 
---Menu---
1. Add item
2. Remove
3. Reverse List
4. Display
5. Quit
1
---------------
Enter number: 40
30 40 
---Menu---
1. Add item
2. Remove
3. Reverse List
4. Display
5. Quit
1
---------------
Enter number: 50
30 40 50 
---Menu---
1. Add item
2. Remove
3. Reverse List
4. Display
5. Quit
1
---------------
Enter number: 60
30 40 50 60 
---Menu---
1. Add item
2. Remove
3. Reverse List
4. Display
5. Quit
2
---------------
Enter node to remove: 60
30 40 50 60 
---Menu---
1. Add item
2. Remove
3. Reverse List
4. Display
5. Quit
4
---------------
Displaying list...
30 40 50 60 
---Menu---
1. Add item
2. Remove
3. Reverse List
4. Display
5. Quit
2
---------------
Enter node to remove: 4
30 40 50 
---Menu---
1. Add item
2. Remove
3. Reverse List
4. Display
5. Quit
3
Reversing List...
---Menu---
1. Add item
2. Remove
3. Reverse List
4. Display
5. Quit
4
---------------
Displaying list...
50 40 30 
---Menu---
1. Add item
2. Remove
3. Reverse List
4. Display
5. Quit

5
*/