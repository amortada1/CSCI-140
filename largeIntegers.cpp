/* 
    Program: Large Integers
    Author: Ali Mortada
    Class: CSCI 140
    Date: 3/21/23
    Description: Input an integer up to 25 digits long. Program stores value as an integer in a vector.
    Program outputs digits of integer, filling up the unused digits with zeroes. Program also outputs 
    number of digits in the entered integer and terminates if an integer greater than 25 digits long
    is entered.
    I certify that the code below is my own work.
    Exception(s): N/A
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    const int MAX_DIGITS = 25;
    vector<int> a;
    string input;
    int numDigits;

    cout << "Author: Ali Mortada" << endl;

    // Prompt user to input large integer up to 25 digits
    cout << "Enter a large integer up to 25 digits: ";
    cin >> input;

    // If input is greater than 25 digits, terminate program
    if (input.size() > MAX_DIGITS) {
        cout << "Error: too many digits" << endl;
        return 0;
    }

    // Count number of digits
    for (int i = 0; i < input.size(); i++) {
        numDigits++;
    }

    // Fill in rest of input with zeroes
    for (int i = input.size(); i < MAX_DIGITS; i++) {
        input.push_back('0');
    }
    
    // Enter each digit as an element in vector a
    for (int i = 0; i < input.size(); i++) {
        a.push_back(input.at(i) - '0');
    }

    // Output digits to user
    cout << "Digits: ";
    for (int i = 0; i < a.size(); i++) {
        cout << a.at(i) << " ";
    }
    cout << endl;

    // Output number of digits to user
    cout << "Number of digits: " << numDigits << endl;

    return 0;
}
