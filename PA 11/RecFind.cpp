/* 
    Program: Recursive Find in an Array
    Author: Ali Mortada
    Class: CSCI 140
    Date: 5/23/23
    Description: Uses a recursive function to find the location of the first found element in
    an array. Returns location of the element if found or -1 if element is not found.
    I certify that the code below is my own work.
    Exception(s): N/A
*/

#include <iostream>
using namespace std;

int recFind(const int a[], int key, int start, int n) {

    // If value is not found, return -1
    if (n - start == 0) {
        return -1;
    }
    // If value is equal to key, return index of found value 
    else if (a[start] == key) {
        return start;
    }
    // Else, recursively call function to keep searching
    return recFind(a, key, start + 1, n);    
}

int main() {

    cout << "Author: Ali Mortada" << endl << endl;

    int values[7] = {5, 7, 3, 2, 6, 2, 15};

    cout << "Index of 2 : " << recFind(values, 2, 0, 7) << endl;   //  3
    cout << "Index of 1 : " << recFind(values, 1, 0, 7) << endl;   // -1
    cout << "Index of 15: " << recFind(values, 15, 0, 7) << endl;  //  6
    cout << "Index of 5 : " << recFind(values, 5, 0, 7) << endl;   //  0


    return 0;
}