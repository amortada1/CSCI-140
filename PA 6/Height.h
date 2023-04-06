#ifndef HEIGHT_H_
#define HEIGHT_H_

#include <iostream>
using namespace std;

class Height {
    public:
        Height(int userFeet, int userInches);
        void setFeet(int userFeet);
        void setInches(int userInches);
        int getFeet() const;
        int getInches() const;
        void print() const;
        void adjust();
    private:
        int feet;
        int inches;
};

#endif