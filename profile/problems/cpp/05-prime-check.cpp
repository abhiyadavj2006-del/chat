// C++ Loops and conditions: prime check
#include <iostream>
using namespace std;

int main() {
    int n, isPrime = 1;
    cout << "Enter a number: ";
    cin >> n;
    if (n <= 1) isPrime = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) { isPrime = 0; break; }
    }
    cout << n << " is " << (isPrime ? "prime" : "not prime") << endl;
    return 0;
}
