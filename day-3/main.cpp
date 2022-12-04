#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int charToPriority (char c) {
    if (c >= 97 && c <= 122) {
        return c - 96;
    } else if (c >= 65) {
        return c - 38;
    }
    return -1;
}

int main() {
    string line;
    ifstream input ("input.txt");
    string left;
    string right;
    while (!input.eof()) {
        getline(input, line);
        cout << line << endl << line.length() << endl;
    }
    cout << charToPriority('A') << endl;
}