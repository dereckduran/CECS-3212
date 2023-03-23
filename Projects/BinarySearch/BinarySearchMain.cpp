#include <iostream>
using namespace std;

int binarysearch(const int [], int, int,int);
void getValues(int [], int);
void displayValues(int [], int);

const int MAX_SIZE = 6;

int main(){
    int len = 8;
    int numbers[len]; //1, 5, 9, 12, 15, 21, 29, 31
    getValues(numbers, len);

    int target = 5;
    int index = binarysearch(numbers, 0, len - 1, target);
    cout << "Target " << target << " was found at index: " << index << endl;

    target = 13;
    index = binarysearch(numbers, 0, len - 1, target);
    cout << "Target " << target << " was found at index: " << index << endl;

    target = 16;
    index = binarysearch(numbers, 0, len - 1, target);
    cout << "Target " << target << " was found at index: " << index << endl;

    return 0;
}

int binarysearch(const int anArray[], int first, int last ,int target){
    int index;
    if (first > last)
        index = -1;
    else 
    {
        // If target is in anArray,
        // anArray[first] <= target <= anArray[last] 
        int mid = first + (last - first) / 2;
        if (target == anArray[mid])
            index = mid; // target found at anArray[mid] else if (target < anArray[mid])
        // Point X
        else if (target < anArray[mid])
            index = binarysearch(anArray, first, mid -1, target);
        else
            index = binarysearch(anArray, mid+1, last, target);
    }  
    return index; 
}

void getValues(int _array[], int number){
    int value; 
    for(int i = 0; i < number; i++){
        cout << "Enter the value for index #" << i + 1 << ": ";
        cin >> value;
        _array[i] = value;
        cout << endl;
    }
}

void displayValues(int _array[], int number){
    for(int i = 0; i < number; i++){
        cout << _array[i] << " ";
    }
    cout << endl;
}

void merge(int theArray[], int first, int mid, int last) {
    int tempArray[MAX_SIZE]; // Temporary array
    // Initialize the local indices to indicate the subarrays
    int first1 = first; int last1 = mid;
    int first2 = mid + 1; int last2 = last;
    // Beginning of first subarray // End of first subarray
    // Beginning of second subarray // End of second subarray
    // While both subarrays are not empty, copy the
    // smaller item into the temporary array
    int index = first1; // Next available location in tempArray
    while ((first1 <= last1) && (first2 <= last2))
    {
    // At this point, tempArray[first..index-1] is in order
        if (theArray[first1] <= theArray[first2]) {
            tempArray[index] = theArray[first1];
            first1++; }
        else
        {
            tempArray[index] = theArray[first2]; 
            first2++;
        } // end if
        index++;
    } // end while
    // Finish off the first subarray, if necessary
    while (first1 <= last1) {
    }
    // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first1]; 
        first1++;
        index++;
    // end while
    // Finish off the second subarray, if necessary
    while (first2 <= last2) {
    // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first2]; first2++;
        index++;
    } // end for
    // Copy the result back into the original array
    for (index = first; index <= last; index++) 
        theArray[index] = tempArray[index];
    } // end merge

/* 

Enter the value for index #1: 1

Enter the value for index #2: 5

Enter the value for index #3: 9

Enter the value for index #4: 12

Enter the value for index #5: 15

Enter the value for index #6: 21

Enter the value for index #7: 29

Enter the value for index #8: 31

Target 5 was found at index: 1
Target 13 was found at index: -1
Target 16 was found at index: -1

*/