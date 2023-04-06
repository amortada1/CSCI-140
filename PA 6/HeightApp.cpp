/* 
    Program: Height Class V1
    Author: Ali Mortada
    Class: CSCI 140
    Date: 4/6/23
    Description: 
    I certify that the code below is my own work.
    Exception(s): N/A
*/

#include <iostream>
#include "Height.h"
using namespace std;

int main() {
    
    cout << "Author: Ali Mortada" << endl << endl;
    
    // Create Height objects
    Height h3(5, 8);           // 5 feet, 8 inches, output: 5' 8"
    Height h4(-1, 5);          // 0 feet, 5 inches, output: 0' 5" (default feet used)
    Height h5(6, 15);          // 6 feet, 0 inches, output: 6' 0" (default inches used)

    // Print height h3
    cout << "h3: ";
    h3.print();                // h3: 5' 8"
    cout << endl;

    // Print height h4
    cout << "h4: ";
    h4.print();                // h4: 0' 5"
    cout << endl;

    // Print height h5
    cout << "h5: ";
    h5.print();                // h5: 6' 0"
    cout << endl;

    // Perform various operations
    h3.setFeet(-2);            // 5 feet, 8 inches (feet stay the same)
    h3.setInches(10);          // 5 feet, 10 inches
    cout << "feet: " << h3.getFeet() << ", inches: " << h3.getInches() << endl;  // 5' 10"

    h4.setFeet(6);             // 6 feet, 5 inches
    h4.setInches(12);          // 6 feet, 5 inches (inches stay the same)
    cout << "feet: " << h4.getFeet() << ", inches: " << h4.getInches() << endl;  // 6' 5"

    h5.setInches(10);          // 6 feet, 10 inches
    h5.adjust();               // 6 feet, 11 inches
    h5.adjust();               // 7 feet, 0 inches
    h5.print();                // 7' 0"

    cout << endl;

    return 0;
}