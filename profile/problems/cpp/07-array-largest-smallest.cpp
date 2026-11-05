// C++ Arrays: largest, smallest and average
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    int largest = arr[0], smallest = arr[0], sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) largest = arr[i];
        if (arr[i] < smallest) smallest = arr[i];
        sum += arr[i];
    }
    cout << "Largest = " << largest << ", Smallest = " << smallest
         << ", Average = " << (float)sum / n << endl;
    return 0;
}
