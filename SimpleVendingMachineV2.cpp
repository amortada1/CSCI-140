/*
    Program: Simple Vending Machine Version 2
    Author: Ali Mortada
    Class: CSCI 140
    Date: 3/15/2023
    Description: User enters amount of quarters, dimes, and nickels to
    load vending machine with.
    User then makes purchases using one-dollar bills between 0 and 100
    cents, receiving change from coins loaded.
    Program terminates when user enters 0, and outputs number of valid
    transactions, remaining amount of coins,
    and total machine balance.
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int purchaseAmount, change;
    int numQuarters, numDimes, numNickels, numDollars = 0;
    int validTransactions = 0;
    double machineBalance = 0.00;

    cout << "Vending Machine Version 2 by Ali Mortada" << endl << endl;

    // Prompt user for amount of quarters, dimes, and nickels
    cout << "Enter number of quarters, dimes, and nickels --> ";
    cin >> numQuarters >> numDimes >> numNickels;
    // Repeat number of quarters, dimes, and nickels to user
    cout << "Number of dollars : " << numDollars << endl;
    cout << "Number of quarters: " << numQuarters << endl;
    cout << "Number of dimes : " << numDimes << endl;
    cout << "Number of nickels : " << numNickels << endl;
    // Calculate and output machine balance
    machineBalance += ((numQuarters * 25) + (numDimes * 10) + (numNickels
    * 5)) / 100.0;
    cout << "Machine balance : $" << fixed << setprecision(2) <<
    machineBalance << endl;
    cout << endl << endl;

    cout << "Only one-dollar bills will be accepted." << endl;
    cout << "Only an amount between 0 and 100 is accepted." << endl;
    cout << "Enter 0 to stop the program." << endl;
    cout << endl << endl;

beginningloop:
    // Prompt user for input, store it in purchaseAmount variable
    cout << "Enter a purchase amount [0 - 100] --> ";
    cin >> purchaseAmount;
    // While purchaseAmount != 0 (sentinel value), keep prompting user to make purchases
    while (purchaseAmount != 0) {
        // Repeat purchase amount to user
        cout << "You entered a purchase amount of " << purchaseAmount << " cents." << endl;
        
        // If input amount is invalid, terminate loop and try again
        if (purchaseAmount < 0 || purchaseAmount > 100) {
            cout << "Invalid amount (outside valid range). Try again." << endl;
            cout << endl;
            goto beginningloop;
        }

        cout << "Please insert one-dollar bill." << endl;
        cout << "Processing your purchase . . ." << endl;

        // Calculate change and round to nearest multiple of 5
        change = 100 - purchaseAmount;
        change = ((change + 5 / 2) / 5) * 5;
        // If change is more than the amount of coins left, terminate loop and try again
        if (change > (numQuarters * 25 + numDimes * 10 + numNickels * 5))
        {
            cout << "Insufficient change!" << endl;
            cout << "Your transaction cannot be processed." << endl;
            cout << "Please take back your dollar bill." << endl;
            cout << endl;
            goto beginningloop;
        }

        // Read amount of change to user
        cout << "Your change of " << change << " cents is given as:" <<
        endl;

        int numQuartersNeeded, numDimesNeeded, numNickelsNeeded;
        // Calculate amount of quarters needed
        if (change / 25 >= 1) {
            numQuartersNeeded = change / 25;
            if (numQuartersNeeded > numQuarters)
            numQuartersNeeded = numQuarters;
            change -= (numQuartersNeeded * 25);
        }
        // Calculate amount of dimes needed
        if (change / 10 >= 1) {
            numDimesNeeded = change / 10;
            if (numDimesNeeded > numDimes)
            numDimesNeeded = numDimes;
            change -= (numDimesNeeded * 10);
        }
        // Calculate amount of nickels needed
        if (change / 5 >= 1) {
            numNickelsNeeded = change / 5;
            if (numNickelsNeeded > numNickels)
            numNickelsNeeded = numNickels;
            change -= (numNickelsNeeded * 5);
        }

        // Output change
        cout << " quarter(s): " << numQuartersNeeded << endl;
        cout << " dime(s) : " << numDimesNeeded << endl;
        cout << " nickel(s) : " << numNickelsNeeded << endl;

        // Remove change from machine
        numQuarters -= numQuartersNeeded;
        numDimes -= numDimesNeeded;
        numNickels -= numNickelsNeeded;

        // Update number of valid transactions and machine balance
        validTransactions++;
        machineBalance = ((numQuarters * 25) + (numDimes * 10) + (numNickels * 5)) / 100.0;

        // Prompt user again for input before redoing the loop (prevents infinite loop)
        cout << endl;
        cout << "Enter a purchase amount [0 - 100] --> ";
        cin >> purchaseAmount;
    }

    // Print valid transactions, number of each type of coin and machine balance
    cout << "There are " << validTransactions << " valid transactions." << endl;
    cout << "Number of dollars : " << validTransactions << endl;
    cout << "Number of quarters: " << numQuarters << endl;
    cout << "Number of dimes : " << numDimes << endl;
    cout << "Number of nickels : " << numNickels << endl;
    cout << "Machine balance : $" << fixed << setprecision(2) << machineBalance + validTransactions << endl;

    return 0;
}