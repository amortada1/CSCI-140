/*  Program: timeConversion   
    Author: Ali Mortada  
    Class: CSCI 140
    Date: 2/28/2023 
    Description: Inputs number of minutes and outputs number of hours and leftover minutes.
    I certify that the code below is my own work.
    Exception(s): N/A
*/

#include <iostream>
using namespace std;

int main(){

    // Initialize variables
    int totalMinutes, hours, minutes;

    // Prompt user for input
    cout << "Enter total number of minutes: ";
    cin >> totalMinutes;

    // Calculate hours and leftover minutes
    hours = totalMinutes / 60;
    minutes = totalMinutes % 60;

    // Output number of hours and leftover minutes
    cout << totalMinutes << " equals " << hours << " hour(s) and " << minutes << " minute(s)." << endl;

    return 0;
}
