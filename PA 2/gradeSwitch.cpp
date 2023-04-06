// Gives letter grade based on score given. Uses a switch statement.

#include <iostream>
using namespace std;

int main() {

    // Prompt user for score input between 0 and 100
    int score;
    char grade;
    cout << "Enter a score between 0 and 100: ";
    cin >> score;

    // Output correct score based on input
    switch (score) {
        case 90 ... 100:
            grade = 'A';
            break;
        case 80 ... 89:
            grade = 'B';
            break;
        case 70 ... 79:
            grade = 'C';
            break;
        case 60 ... 69:
            grade = 'D';
            break;
        default:
            grade = 'F';
            break;
    }

    cout << "Your grade is " << grade << "." << endl;

    return 0;
}