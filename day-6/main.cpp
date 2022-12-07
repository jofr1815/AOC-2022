#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool compareHelper(string subStr) {
    for (int i = 0; i < subStr.length(); i++) {
        for (int j = 0; j < subStr.length(); j++) {
            if ((i != j) && subStr[i] == subStr[j]) {
                return false;
            }
        }
    }
    return true;
}

int findStart(string input, int n) {
    for (int i = (n-1); i < input.length(); i++) {
        string subStr;
        for (int j = 0; j < n; j++) {
            subStr.push_back(input[i - j]);
        }
        if (compareHelper(subStr)) {
            return i + 1;
        }
        subStr.clear();
    }
    return 0;
}

int main() {

    fstream input;
    string line;
    input.open("input.txt");
    getline(input, line);
    cout << "Part 1: " << findStart(line, 4) << endl;
    cout << "Part 2: " << findStart(line, 14) << endl;
    input.close();
    return 0;
}