#include <iostream>
using namespace std;

int fact(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    return n * fact(n - 1);
}
int sumUpTo(int n){
    int sum = 0;
    if(n==1)
        sum = 1;
    else 
        sum = n + sumUpTo(n-1);
    return sum;
}
void displayOctal(int n){
    if(n>0){
        if(n / 8 > 0)
            displayOctal(n / 8);
        cout << n % 8;
    }
}
void displayBinary(int n){
    if(n>0){
        if(n / 2 > 0)
            displayBinary(n / 2);
        cout << n % 2;
    }
}
int Acker(int m, int n){
    if(m == 0)
        return n + 1;
    else if(n == 0)
        return Acker(m - 1, 1);
    else 
        return Acker(m - 1, Acker(m, n - 1));
}
int getNumberEqual(const int x[], int n, int desiredValue)

{
    int count = 0;
    if (n <= 0)
       return 0;
    else{
        if (x[n - 1] == desiredValue)
            count = 1;
        return getNumberEqual(x, n - 1, desiredValue) + count;
    }  // end else
} // end getNumberEqual
int main(){
   
    int numbers[] = {1,1,2,3,4,5};
    int len =  sizeof(numbers)/sizeof(numbers[0]);
    int instances = getNumberEqual(numbers, len, 1);
    cout << "Number of instances: " << instances << endl;
    cout << Acker(1,2) << endl;
    return 0;
}
/* 
Number of instances: 2
*/