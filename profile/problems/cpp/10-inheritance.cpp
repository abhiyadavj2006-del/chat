// C++ OOP: single inheritance - Person -> Student
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n) : name(n) {}
    void showName() { cout << "Name: " << name << endl; }
};

class Student : public Person {
    int roll;
public:
    Student(string n, int r) : Person(n), roll(r) {}
    void display() {
        showName();
        cout << "Roll: " << roll << endl;
    }
};

int main() {
    Student s("Abhi", 101);
    s.display();
    return 0;
}
