#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void printArr(string arr[]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < arr[i].length(); j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

void reverseStr(string &str) {
    int n = str.length() - 1;
    for (int i = 0; i <= n/2; i ++) {
        swap(str[i], str[n-i]);
    }
    return;
}

int main() {
    // Variables for parsing input into lines
    fstream input;
    string line;

    // Array of strings to hold the stack of boxes
    string arr[9];

    // Open file and get first line
    input.open("input.txt");
    getline(input, line);
    while(line.length() != 0 && line[1] != '1') {
        for (int i = 0; i < line.length(); i++) {
            cout << line[i*4 + 1] << " ";
            if (line[i*4 + 1] != ' ' && line[i*4 + 1] != 0) {
                arr[i].push_back(line[i*4 + 1]);
            }
        }
        cout << endl;
        getline(input, line);
    }
    // Print out array of strings
    printArr(arr);

    string x = "ABC";
    reverseStr(x);
    cout << x << endl;

    return 0;
}