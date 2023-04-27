/* 
    Program: Dynamic Array
    Author: Ali Mortada
    Class: CSCI 140
    Date: 4/27/23
    Description: Prompts user for monthly sales and stores them in a dynamically allocated
    array. Calls a function to fill in the array with user input, then computes the total 
    and average monthly sales and displays them with two digits of precision. Returns allocated 
    memory when done.
    I certify that the code below is my own work.
    Exception(s): N/A
*/

#include <iostream>
#include <iomanip>
using namespace std;

void inputMonthlySales(double *, int);
double computeTotalSales(double *, int);
double computeAvgSales(double *, int);

int main() {

    int numMonthlySales;

    cout << "Author: Ali Mortada" << endl << endl;

    // Prompt user for number of monthly sales
    cout << "Please enter the number of monthly sales --> ";
    cin >> numMonthlySales;

    // Fill data into dynamic array
    double *dynamicArray = new double[numMonthlySales];
    inputMonthlySales(dynamicArray, numMonthlySales);
    
    // Output total and average monthly sales
    cout << "Total sales: $" << fixed << setprecision(2) << computeTotalSales(dynamicArray, numMonthlySales) << endl;
    cout << "Average monthly sales: $" << fixed << setprecision(2) << computeAvgSales(dynamicArray, numMonthlySales) << endl;

    // Delete array
    cout << "Returning dynamic memory..." << endl;
    delete[] dynamicArray;
    cout << "Done." << endl;

    return 0;
}

void inputMonthlySales(double *dynamicArray, int numMonthlySales) {
    // Keep prompting user to input data into array
    for (int i = 0; i < numMonthlySales; i++) {
        cout << "Please input the sales for month " << i + 1 << " --> ";
        cin >> dynamicArray[i];
    }
    cout << endl;
}

double computeTotalSales(double *dynamicArray, int numMonthlySales) {
    double totalSales = 0;
    // Iterate through array and add up all the sales
    for (int i = 0; i < numMonthlySales; i++) {
        totalSales += dynamicArray[i];
    }

    return totalSales;
}

double computeAvgSales(double *dynamicArray, int numMonthlySales) {
    double totalSales = 0;
    double averageSales = 0;
    // Add up all sales
    for (int i = 0; i < numMonthlySales; i++) {
        totalSales += dynamicArray[i];
    }
    
    // Divide by total to get average
    averageSales = totalSales / numMonthlySales;

    return averageSales;
}
