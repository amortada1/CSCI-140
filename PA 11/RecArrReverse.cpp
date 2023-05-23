/* 
    Program: Recursive Find in an Array
    Author: Ali Mortada
    Class: CSCI 140
    Date: 5/23/23
    Description: Uses a recursive function to reverse the elements of an int array.
    I certify that the code below is my own work.
    Exception(s): N/A
*/

#include <iostream>
using namespace std;

void recArrReverse(int a[], int start, int end) {
    
    // Once array has been iterated through, exit the function
    if (start >= end) {
        return;
    } else {
        // Swap first and last values
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;

        // Recursively call function to swap second/second-last, third/third-last, etc.
        recArrReverse(a, start + 1, end - 1);
    }
}

// Function to print arrays
void printArray(int a[], int size) {
    
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }

    cout << endl;
}

int main() {

    cout << "Author: Ali Mortada" << endl << endl;

    int values[7] = {5, 7, 3, 2, 6, 2, 15};
    cout << "Regular array: ";
    printArray(values, 7);   // 5 7 3 2 6 2 15
    cout << endl;

    recArrReverse(values, 0, 6);
    cout << "Reversed array: ";
    printArray(values, 7);   // 15 2 6 2 3 7 5
    
    return 0;
}