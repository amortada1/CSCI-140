/* 
    Program: Timing Sorting Algorithm
    Author: Ali Mortada
    Class: CSCI 140
    Date: 5/4/23
    Description: Times the selection sort of two text files containing 10k values and
    50k values. Shows that the runtime of selection sort is O(N^2).
    I certify that the code below is my own work.
    Exception(s): N/A
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void selectionSort(int numbers[], int numbersSize);

int sortTime = 0;

int main() {
    
    ifstream inFS;
    ifstream inFS2;
    string value;
    string values10k[10000];
    string values50k[50000];
    int numValues = 0;
    
    cout << "Author: Ali Mortada" << endl << endl;
    
    // Attempt to open medium10k.txt
    cout << "Sorting file: medium10k.txt" << endl;
    inFS.open("medium10k.txt");
    if (!inFS.is_open()) {
        cout << "Could not open file medium10k.txt." << endl;
        return 1;
    }

    // Count number of values and input values into array
    for (int i = 0; i < 10000; i++) {
        getline(inFS, value);
        values10k[i] = value;
        numValues++;
    }
    cout << "Number of values: " << numValues << endl;

    // Output first and last 5 unsorted values
    cout << "First 5 (unsorted): ";
    for (int i = 0; i < 5; i++) {
        cout << values10k[i] << " ";
    }
    cout << endl;

    cout << "Last 5 (unsorted): ";
    for (int i = 9995; i < 10000; i++) {
        cout << values10k[i] << " ";
    }
    cout << endl;

    // Convert values10k to an int array
    int intvalues10k[10000];
    for (int i = 0; i < 10000; i++) {
        intvalues10k[i] = atoi(values10k[i].c_str());
    }

    // Sort medium10k.txt
    selectionSort(intvalues10k, 10000);

    // Output first and last 5 sorted values
    cout << "First 5 (sorted): ";
    for (int i = 0; i < 5; i++) {
        cout << intvalues10k[i] << " ";
    }
    cout << endl;

    cout << "Last 5 (sorted): ";
    for (int i = 9995; i < 10000; i++) {
        cout << intvalues10k[i] << " ";
    }
    cout << endl;

    // Output sort time
    cout << "Sort time: " << sortTime << " ms" << endl;

    cout << endl << endl;

    // Close medium10k.txt
    inFS.close();

    // Reset number of values and sort time
    numValues = 0;
    sortTime = 0;

    ////////////////////////////////////////////////////////////////

    // Repeat for medium50k
    cout << "Sorting file: medium50k.txt" << endl;
    inFS2.open("medium50k.txt");
    if (!inFS2.is_open()) {
        cout << "Could not open file medium50k.txt." << endl;
        return 1;
    }

    for (int i = 0; i < 50000; i++) {
        getline(inFS2, value);
        values50k[i] = value;
        numValues++;
    }
    cout << "Number of values: " << numValues << endl;

    cout << "First 5 (unsorted): ";
    for (int i = 0; i < 5; i++) {
        cout << values50k[i] << " ";
    }
    cout << endl;

    cout << "Last 5 (unsorted): ";
    for (int i = 49995; i < 50000; i++) {
        cout << values50k[i] << " ";
    }
    cout << endl;

    int intvalues50k[50000];
    for (int i = 0; i < 50000; i++) {
        intvalues50k[i] = atoi(values50k[i].c_str());
    }

    selectionSort(intvalues50k, 50000);

    cout << "First 5 (sorted): ";
    for (int i = 0; i < 5; i++) {
        cout << intvalues50k[i] << " ";
    }
    cout << endl;

    cout << "Last 5 (sorted): ";
    for (int i = 49995; i < 50000; i++) {
        cout << intvalues50k[i] << " ";
    }
    cout << endl;

    cout << "Sort time: " << sortTime << " ms" << endl;

    cout << endl << endl;

    inFS2.close();

    return 0;
}

void selectionSort(int numbers[], int numbersSize) {
    int i, j, indexSmallest, temp;

    for (i = 0; i < numbersSize; i++) {
        indexSmallest = i;
        for (j = i + 1; j < numbersSize; j++) {
            if (numbers[j] < numbers[indexSmallest]) {
                indexSmallest = j;
            }
            sortTime++;
        }

        temp = numbers[i];
        numbers[i] = numbers[indexSmallest];
        numbers[indexSmallest] = temp;
    }
}