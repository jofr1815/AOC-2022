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
            // Draw
            total += 3;
            if (line[0] == 'A') {
                // Opponent played rock
                total += 1;
            } else if (line[0] == 'B') {
                // Opponent played paper
                total += 2;
            } else {
                // Opponent played scissors
                total += 3;
            }
        } else if (line[2] == 'X') {
            // Lose
            if (line[0] == 'A') {
                // Opponent played rock
                total += 3;
            } else if (line[0] == 'B') {
                // Opponent played paper
                total += 1;
            } else {
                // Opponent played scissors
                total += 2;
            }
        } else {
            // Win
            total += 6;
            if (line[0] == 'A') {
                // Opponent played rock
                total += 2;

            } else if (line[0] == 'B') {
                // Opponent played paper
                total += 3;
            } else {
                // Opponent played scissors
                total +=1;
            }
        }
    }
    cout << total << endl;
}