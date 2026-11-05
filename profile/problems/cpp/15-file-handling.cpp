// C++ File handling: write to and read from a file with fstream
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream out("student.txt");
    out << "Abhi Yadav, BTech CSE" << endl;
    out.close();

    ifstream in("student.txt");
    string line;
    cout << "File content:" << endl;
    while (getline(in, line)) cout << line << endl;
    in.close();
    return 0;
}
