#include <iostream>
#include "MyInteger.h"
using namespace std;

MyInteger::MyInteger(int v /*= 0*/) {
    value = v;
}

// Copy constructor
MyInteger::MyInteger(const MyInteger &origInteger) {
    value = origInteger.value;
}


void MyInteger::setValue(int v) {
    value = v;
}

int MyInteger::getValue() const {
    return value;
}

void MyInteger::operator=(const MyInteger &r) {
    value = r.value;
}

MyInteger MyInteger::operator+(const MyInteger &r) const {
    return value + r.value;
}

MyInteger MyInteger::operator-(const MyInteger &r) const {
    return value - r.value;
}

MyInteger MyInteger::operator*(const MyInteger& r) const {
    return value * r.value;
}

MyInteger MyInteger::operator/(const MyInteger& r) const {
    return value / r.value;
}

MyInteger MyInteger::operator%(const MyInteger& r) const {
    return value % r.value;
}

bool MyInteger::operator==(const MyInteger &r) const {
    if (value == r.value) {
        return true;
    }
    return false;
}

bool MyInteger::operator!=(const MyInteger& r) const {
    if (value != r.value) {
        return true;
    }
    return false;
}

ostream &operator<<(ostream &out, const MyInteger &r) {
    out << r.value;
    return out;
}

istream &operator>>(istream &in, MyInteger &r) {
    in >> r.value;
    return in;
}
