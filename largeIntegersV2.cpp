/* 
    Program: Large Integers V2
    Author: Ali Mortada
    Class: CSCI 140
    Date: 3/30/23
    Description: Takes two large integers as strings, converts them into vectors, adds them up,
    then outputs the result. Uses three functions: one to store the integers as vectors, one to add
    them up, and one to output the result. Terminates if one input has more than 25 digits, or if 
    the total digits of both integers is greater than 25.
    I certify that the code below is my own work.
    Exception(s): N/A
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function prototypes
void stringToVector(string, vector<int>&);
bool addOperands(vector<int>&, vector<int>&, vector<int>&, int, int);
void outputLargeInteger(string, string, vector<int>&, bool);

const int MAX_DIGITS = 25;
int main() {
    vector<int> num1(MAX_DIGITS);
    vector<int> num2(MAX_DIGITS);
    vector<int> result(MAX_DIGITS);
    string input1, input2;
    char op;
    int numDigits;

    cout << "Author: Ali Mortada" << endl;

    // Prompt user for input
    cout << "Enter an expression --> ";
    cin >> input1 >> op >> input2;

    // If either input1 or input2 has more than 25 digits, terminate program
    if (input1.size() > MAX_DIGITS || input2.size() > MAX_DIGITS) {
        cout << "Invalid operand(s)" << endl;
        return 0;
    }

    // Convert input strings to vectors
    stringToVector(input1, num1);
    stringToVector(input2, num2);
    
    // Add operands, then output result
    outputLargeInteger(input1, input2, result, addOperands(num1, num2, result, input1.size(), input2.size()));

    return 0;
}

// Function definitions
// Converts input string into a vector
void stringToVector(string input, vector<int>& num) {
    int numDigits = input.size();
    int j = 0;
    for (int i = numDigits - 1; i >= 0; i--, j++) {
        num.at(i) = input.at(j) - '0';
    }
}

// Add vector 1 and 2 together
bool addOperands(vector<int>& num1, vector<int>& num2, vector<int>& result, int numDigits1, int numDigits2) {
    // If size of operands is greater than 25, terminate program
    if (numDigits1 + numDigits2 > MAX_DIGITS) {
        return false;
    }
    
    for (int i = 0; i < MAX_DIGITS; i++) {
        // If digits add up to less than 10, simply add. Otherwise, carry the 1.
        if (result.at(i) + num1.at(i) + num2.at(i) < 10) {
            result.at(i) += num1.at(i) + num2.at(i);
        } else {
            result.at(i) = (result.at(i) + num1.at(i) + num2.at(i)) % 10;
            result.at(i + 1) = 1;
        }
    }
    return true;
}

// Outputs result of addition
void outputLargeInteger(string input1, string input2, vector<int>& result, bool isValid) {
    string resultString = "";
    // Iterate through vector backwards and put contents into string
    for (int i = MAX_DIGITS - 1; i >= 0; i--) {
        resultString.append(to_string(result.at(i)));
    }
    // Erase leading zeros
    resultString.erase(0, resultString.find_first_not_of('0'));

    // Output results
    cout << input1 << " + " << input2 << " = ";
    // If operands were valid, output result. If not, output "overflow"
    if (isValid) {
        cout << resultString << endl;
    } else {
        cout << "overflow" << endl;
    }
}