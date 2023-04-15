#ifndef HEIGHT_H
#define HEIGHT_H

#include <iostream>
using namespace std;

class Height {
    public:
        Height(int userFeet, int userInches);
        bool operator==(const Height &r) const;

        void setFeet(int userFeet);
        void setInches(int userInches);

        int getFeet() const;
        int getInches() const;
        int totalInches() const;

        void print() const;
        void adjust();
        void adjust(int userInches);

    private:
        int feet;
        int inches;
};

#endif