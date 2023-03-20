/* 
    Program: Simple Vending Machine Version 2
    Author: Ali Mortada
    Class: CSCI 140
    Date: 3/14/2023
    Description: Reads an int value between 0 and 100 representing a purchase in cents from
    a vending machine, and outputs the amount of change. Rounds change to the nearest multiple
    of 5 and can only use up to 2 quarters, 2 dimes, and 1 nickel.
    I certify that the code below is my own work.
    Exception(s): N/A
*/

#include <iostream>
using namespace std;

int main() {

    int purchaseAmount, change;
    int numQuarters, numDimes, numNickels;
    int machineBalance;

    cout << "Vending Machine Version 2 by Ali Mortada" << endl;
    
    // Prompt user for amount of quarters, dimes, and nickels
    cout << "Enter number of quarters, dimes, and nickels --> ";
    cin >> numQuarters >> numDimes >> numNickels;

    // Repeat number of quarters, dimes, and nickels to user
    cout << "Number of dollars : " << endl;
    cout << "Number of quarters: " << numQuarters << endl;
    cout << "Number of dimes   : " << numDimes << endl;
    cout << "Number of nickels : " << numNickels << endl;
    // Calculate and output machine balance
    machineBalance = (numQuarters * 25) + (numDimes * 10) + (numNickels * 5);
    cout << "Machine balance   : $" << machineBalance / 100 << "." << machineBalance % 100 << endl;

    // Prompt user for input, store it in purchaseAmount variable
    cout << "Enter a purchase amount [0 - 100] --> ";
    cin >> purchaseAmount;

    // Repeat purchase amount to user
    cout << "You entered a purchase amount of " << purchaseAmount << "cents." << endl;

    // If input amount is invalid, terminate program
    if (purchaseAmount < 0 || purchaseAmount > 100) {
        cout << "You entered an invalid amount (not between 0 and 100)." << endl;
        return 0;
    }

    // Calculate change and round to nearest multiple of 5
    change = 100 - purchaseAmount;
    change = ((change + 5 / 2) / 5) * 5;

    // If change is greater than 75 cents, terminate program
    if (change > 75) {
        cout << "Insufficient coins. Your change of " << change << " cents cannot be processed." << endl;
        return 0;
    }

    // Read amount of change to user
    cout << "Your change of " << change << " cents is given as:" << endl;

    // Calculate amount of quarters needed
    if (change / 25 == 1 || change / 25 == 2) {
        numQuarters = (change / 25);
        change -= (numQuarters * 25);
    }
    // Special case for if change is exactly 75 cents
    if (change == 75) {
        numQuarters = 2;
        change -= (numQuarters * 25);
    }
    // Calculate amount of dimes needed
    if (change / 10 == 1 || change / 10 == 2) {
        numDimes = (change / 10);
        change -= (numDimes * 10);
    }
    // Calculate amount of nickels needed
    if (change / 5 == 1) {
        numNickels = (change / 5);
        change -= (numNickels * 5);
    }

    // Output change
    cout << " quarter(s): " << numQuarters << endl;
    cout << " dime(s) : " << numDimes << endl;
    cout << " nickel(s) : " << numNickels << endl;

    return 0;
}