/* 
    Program: Class Templates - MyNum
    Author: Ali Mortada
    Class: CSCI 140
    Date: 5/29/23
    Description: Copy of MyInteger class from PA 8, but uses a class template to allow use for
	other data types such as double, etc.
    I certify that the code below is my own work.
    Exception(s): N/A
*/

#ifndef MYNUM_H
#define MYNUM_H

#include <iostream>

using namespace std;

template<typename NumType>
class MyNum
{
public:
	MyNum(NumType v = 0) {
		value = v;
	}

	MyNum(const MyNum &origNumber) {            // Copy constructor
		value = origNumber.value;
	}

	void setValue(NumType v) {
		value = v;
	}

	int getValue() const {
		return value;
	}

	void operator=(const MyNum &r) {            // Copy assignment operator
		value = r.value;
	}
	              
	MyNum operator+(const MyNum &r) const {
		return value + r.value;
	}

	MyNum operator-(const MyNum &r) const {
		return value - r.value;
	}

	MyNum operator*(const MyNum& r) const {
		return value * r.value;
	}

	MyNum operator/(const MyNum& r) const {
		return value / r.value;
	}

	MyNum operator%(const MyNum& r) const {
		return value % r.value;
	}

	bool operator==(const MyNum &r) const {
		if (value == r.value)
			return true;
		return false;
	}

	bool operator!=(const MyNum& r) const {
		if (value != r.value) 
        	return true;
    	return false;
	}

	friend ostream &operator<<(ostream &out, const MyNum &r) {
		out << r.value;
    	return out;
	}

	friend istream &operator>>(istream &in, MyNum &r) {
		in >> r.value;
    	return in;
	}

private:
	NumType value;
};
#endif