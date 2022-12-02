#include <iostream>
#include <string>
#include <fstream>
#include <climits>

using namespace std;

int main() {
    int candidate = 0;
    int max = 0;
    int min = INT_MAX;
    string line;
    ifstream input ("input.txt");
    while (!input.eof()){
        getline(input, line);
        cout << line << endl;
        if (line.length() > 1) {
            candidate += stoi(line);
            cout << "Not empty!" << endl;
        } else {
            cout << "Empty!" << endl;
            if (candidate > max) {
                max = candidate;
            }
            if (candidate < min) {
                min = candidate;
            }
            candidate = 0;
        }
    }
    cout << "The max is " << max << endl;
    cout << "The min is " << min << endl;
}