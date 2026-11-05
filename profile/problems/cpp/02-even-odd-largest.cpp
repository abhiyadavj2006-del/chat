// C++ Branching: even/odd and largest of three numbers
#include <iostream>
using namespace std;

int main() {
    int a, b, c, largest;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;
    cout << a << " is " << (a % 2 == 0 ? "even" : "odd") << endl;
    largest = a;
    if (b > largest) largest = b;
    if (c > largest) largest = c;
    cout << "Largest = " << largest << endl;
    return 0;
}
