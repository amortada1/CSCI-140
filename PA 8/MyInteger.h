// Created and updated by T. Vo for CSCI 140 Spring 2023.
// Do not modify this file.
#ifndef MYINTEGER_H
#define MYINTEGER_H

#include <iostream>

using namespace std;

class MyInteger
{
public:
	MyInteger(int v = 0);
	MyInteger(const MyInteger &origInteger);         // Copy constructor
	void setValue(int v);
	int getValue() const;
	void operator=(const MyInteger &r);              // Copy assignment operator
	MyInteger operator+(const MyInteger &r) const;
	MyInteger operator-(const MyInteger &r) const;
	MyInteger operator*(const MyInteger& r) const;
	MyInteger operator/(const MyInteger& r) const;
	MyInteger operator%(const MyInteger& r) const;
	bool operator==(const MyInteger &r) const;
	bool operator!=(const MyInteger& r) const;

	friend ostream &operator<<(ostream &out, const MyInteger &r);
	friend istream &operator>>(istream &in, MyInteger &r);

private:
	int value;
};
#endif