// C++ OOP: runtime polymorphism with virtual functions
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() { cout << "Area of a shape" << endl; }
    virtual ~Shape() {}
};

class Circle : public Shape {
    double r;
public:
    Circle(double radius) : r(radius) {}
    void area() override {
        cout << "Area of circle = " << 3.14 * r * r << endl;
    }
};

class Rectangle : public Shape {
    double l, b;
public:
    Rectangle(double length, double breadth) : l(length), b(breadth) {}
    void area() override {
        cout << "Area of rectangle = " << l * b << endl;
    }
};

int main() {
    Shape* s1 = new Circle(5);
    Shape* s2 = new Rectangle(4, 6);
    s1->area();
    s2->area();
    delete s1;
    delete s2;
    return 0;
}
