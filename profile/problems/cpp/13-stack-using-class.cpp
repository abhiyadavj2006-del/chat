// C++ Data Structures: stack implemented with a class
#include <iostream>
using namespace std;

class Stack {
    int arr[100], top;
public:
    Stack() : top(-1) {}
    void push(int x) {
        if (top == 99) { cout << "Stack overflow" << endl; return; }
        arr[++top] = x;
    }
    int pop() {
        if (top == -1) { cout << "Stack underflow" << endl; return -1; }
        return arr[top--];
    }
    void display() {
        for (int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10); s.push(20); s.push(30);
    s.display();
    cout << "Popped: " << s.pop() << endl;
    s.display();
    return 0;
}
