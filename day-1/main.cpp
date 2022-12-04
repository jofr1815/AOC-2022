#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> vect;
    int sum = 0;
    string line;
    ifstream input ("input.txt");
    while (!input.eof()){
        getline(input, line);
        cout << line << endl;
        if (line.length() > 1) {
            sum += stoi(line);
            cout << "Not empty!" << endl;
        } else {
            cout << "Empty!" << endl;
            vect.push_back(sum);
            sum = 0;
        }
    }
    sort(vect.begin(), vect.end(), greater<int>());
    cout << vect[0] << endl;
    cout << vect[0] + vect[1] + vect[2] << endl;
}