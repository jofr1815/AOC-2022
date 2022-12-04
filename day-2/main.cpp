#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream input ("input.txt");
    string line;
    int total = 0;
    while(!input.eof()) {
        getline(input, line);
        if (line[2] == 'Y') {
            // You played paper
            total += 2;
            if (line[0] == 'A') {
                // Opponent played rock
                total += 6;
            } else if (line[0] == 'B') {
                // Opponent played paper
                total += 3;
            }
        } else if (line[2] == 'X') {
            // You played rock
            total += 1;
            if (line[0] == 'C') {
                // Opponent played scissors
                total += 6;
            } else if (line[0] == 'A') {
                // Opponent played rock
                total += 3;
            }
        } else {
            // You played scissors
            total += 3;
            if (line[0] == 'B') {
                // Opponent played paper
                total += 6;
            } else if (line[0] == 'C') {
                // Opponent played scissors
                total += 3;
            }
        }
    }
    cout << total << endl;
}