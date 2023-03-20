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
