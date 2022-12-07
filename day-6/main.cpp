#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool compareHelper(char a, char b, char c, char d) {
    if (a == b || a == c || a == d || b == c || b == d || c == d) {
        return false;
    }
    return true;
}

int findStart(string input) {
    for (int i = 3; i < input.length(); i++) {
        if (compareHelper(input[i], input[i-1], input[i-2], input[i-3])) {
            return i + 1;
        }
    }
    return 0;
}

int main() {

    fstream input;
    string line;
    input.open("input.txt");
    getline(input, line);
    cout << findStart(line) << endl;
    input.close();
    return 0;
}