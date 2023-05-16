#include <iostream>
using namespace std;

class BasicShape {
    public:
        BasicShape();
        BasicShape(int X, int Y);

        int getX();
        int getY();

        virtual double area() = 0;
        virtual void print() = 0;
        
    protected:
        int x;
        int y;
};

BasicShape::BasicShape() {
    x = 0;
    y = 0;
}

BasicShape::BasicShape(int X, int Y) {
    x = X;
    y = Y;
}

int BasicShape::getX() {return x;}

int BasicShape::getY() {return y;}

class Circle : public BasicShape {
    public:
        Circle();
        Circle(int X, int Y, double Radius);

        double area() override;
        void print() override;
    private:
        double radius;
};

Circle::Circle() {
    x = 0;
    y = 0;
    radius = 1.0;
}

Circle::Circle(int X, int Y, double Radius) {
    x = X;
    y = Y;
    radius = Radius;
}

double Circle::area() {
    return 3.14 * radius * radius;
}

void Circle::print() {
    cout << "Circle: center point (" << x << ", " << y << ") and radius " << radius << endl; 
}

class Rectangle : public BasicShape {
    public:
        Rectangle();
        Rectangle(int X, int Y, int Width, int Height);

        double area() override;
        void print() override;
    private:
        int width;
        int height;
};

Rectangle::Rectangle() {
    x = 0;
    y = 0;
    width = 1;
    height = 1;
}

Rectangle::Rectangle(int X, int Y, int Width, int Height) {
    x = X;
    y = Y;
    width = Width;
    height = Height;
}

double Rectangle::area() {
    return width * height;
}

void Rectangle::print() {
    cout << "Rectangle: top-left point (" << x << ", " << y << "), " << width << " by " << height << endl;
}