// C++ STL: vector, sort and binary search
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {5, 2, 9, 1, 7};
    sort(v.begin(), v.end());
    cout << "Sorted: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    int key = 7;
    cout << key << (binary_search(v.begin(), v.end(), key)
                     ? " found" : " not found") << endl;
    return 0;
}
