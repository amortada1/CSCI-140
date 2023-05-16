/* 
    Program: Abstract Base Class
    Author: Ali Mortada
    Class: CSCI 140
    Date: 5/16/23
    Description: Driver program for BasicShape class.
    I certify that the code below is my own work.
    Exception(s): N/A
*/

#include <iostream>
#include "BasicShape.cpp"
using namespace std;

int main() {
    cout << "Author: Ali Mortada" << endl << endl;

    Circle c1; // center (0, 0) with radius 1.0
    Circle c2(5, 7, 2.5); // center (5, 7) with radius 2.5
    Rectangle r1; // top-left (0, 0) with 1 by 1
    Rectangle r2(5, 7, 10, 15); // top-left (5, 7) with 10 by 15
    BasicShape *pShapeArray[4] = {&c1, &r1, &c2, &r2};
    for (int i = 0; i < 4; i++) {
        pShapeArray[i]->print();
        cout << "\narea: " << pShapeArray[i]->area() << endl << endl;
    }
    
    return 0;
}