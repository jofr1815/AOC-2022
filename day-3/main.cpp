#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

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
    int total = 0;
    while (!input.eof()) {
        getline(input, line);
        if (line.length() %2){
            line.pop_back();
        };
        for (int i = 0; i < line.length()/2; i++){
            left.push_back(line[i]);
        }
        for (int i = line.length()/2; i < line.length(); i++) {
            right.push_back(line[i]);
        }

        for (int i = 0; i < left.length(); i++) {
            for (int j = 0; j < right.length(); j++) {
                if (left[i] == right[j]){
                    total += charToPriority(left[i]);
                    while (left.length() > 0) {
                        left.pop_back();
                        right.pop_back();
                    }
                }
            }
        }
    }
    cout << total << endl;
}