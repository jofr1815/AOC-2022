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

    // Part 1
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
    cout << "part 1 total: " << total << endl;
    input.close();

    // Part 2
    total = 0;
    input.open("input.txt");
    string lineA;
    string lineB;
    string lineC;
    while (!input.eof()) {
        getline(input, lineA);
        getline(input, lineB);
        getline(input, lineC);

        for (int i = 0; i < lineA.length(); i ++) {
            for (int j = 0; j < lineB.length(); j ++) {
                for (int k = 0; k < lineC.length(); k++) {
                    if (lineA[i] == lineB[j] && lineB[j] == lineC[k]){
                        total += charToPriority(lineA[i]);
                        while (lineA.length() > 0) {
                            lineA.pop_back();
                        }
                        while (lineB.length() > 0) {
                            lineB.pop_back();
                        }
                        while (lineC.length() > 0) {
                            lineC.pop_back();
                        }
                    }
                }
            }
        }
    }
    cout << "part 2 total: " << total << endl;
}