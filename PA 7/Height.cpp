#include <iostream>
#include "Height.h"
using namespace std;

// Default constructor
Height::Height(int userFeet, int userInches) {
    // Set feet to input if >= 0, if not then default to 0
    if (userFeet >= 0) {
        feet = userFeet;
    } else {
        feet = 0;
    }
    // Set inches to input if between 0 and 11, if not then default to 0
    if (userInches >= 0 && userInches <= 11) {
        inches = userInches;
    } else {
        inches = 0;
    }
}

// Operator overload for ==, allows two heights to be compared
bool Height::operator==(const Height &r) const {
    if (feet == r.feet && inches == r.inches) {
        return true;
    }
    return false;
}

// Mutator for feet data member
void Height::setFeet(int userFeet) {
    if (userFeet >= 0)
        feet = userFeet;
}

// Mutator for inches data member
void Height::setInches(int userInches) {
    if (userInches >= 0 && userInches <= 11)
        inches = userInches;
}

// Accessor for feet data member
int Height::getFeet() const {
    return feet;
}

// Accessor for inches data member
int Height::getInches() const {
    return inches;
}

// Returns total inches
int Height::totalInches() const {
    return (feet * 12) + inches;
}

// Print height in ' " format
void Height::print() const {
    cout << feet << "' " << inches << "\"" << endl;
}

// Increments inch by 1 and, if needed, feet by 1
void Height::adjust() {
    if (inches != 11) {
        inches++;
    } else {
        inches = 0;
        feet++;
    }
}

// Adjusts height by a given amount of inches
void Height::adjust(int userInches) {
    inches += userInches;
    // If inches overflow, carry a foot up or down
    if (inches >= 12) {
        inches -= 12;
        feet++;
    }
    if (inches < 0) {
        inches += 12;
        feet--;
    }
}