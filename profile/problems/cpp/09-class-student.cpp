// C++ OOP: class, constructor and member functions
#include <iostream>
#include <string>
using namespace std;

class Student {
    int roll;
    string name;
    float marks;
public:
    Student(int r, string n, float m) : roll(r), name(n), marks(m) {}
    void display() {
        cout << "Roll: " << roll << ", Name: " << name
             << ", Marks: " << marks << endl;
    }
};

int main() {
    Student s(101, "Abhi", 85.5);
    s.display();
    return 0;
}
