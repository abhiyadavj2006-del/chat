// C++ Strings: check if a string is a palindrome
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s, rev;
    cout << "Enter a string: ";
    cin >> s;
    rev = s;
    reverse(rev.begin(), rev.end());
    cout << s << " is " << (s == rev ? "a palindrome" : "not a palindrome") << endl;
    return 0;
}
