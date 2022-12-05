#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input;
    input.open("input.txt");
    string line;
    string leftLower;
    string leftUpper;
    string rightLower;
    string rightUpper;
    int index = 0;
    int total = 0;
    while (!input.eof()) {
        getline(input, line);
        cout << line << endl;
        // Extract first number
        while(line[index] != '-'){
            leftLower.push_back(line[index]);
            index++;
        }
        index++;
        // Extract second number
        while(line[index] != ','){
            leftUpper.push_back(line[index]);
            index++;
        }
        index++;
        // Extract third number
        while(line[index] != '-'){
            rightLower.push_back(line[index]);
            index++;
        }
        index++;
        // Extract fourth number
        while(index < line.length()){
            rightUpper.push_back(line[index]);
            index++;
        }
        cout << leftLower << " " << leftUpper << endl;
        cout << rightLower << " " << rightUpper << endl;

        // If one range completely includes the other, increment total
        if((stoi(leftLower) >= stoi(rightLower) && stoi(leftUpper) <= stoi(rightUpper)) || (stoi(leftLower) <= stoi(rightLower) && stoi(leftUpper) >= stoi(rightUpper))) {
            cout << "One range holds the other" << endl;
            total++;
        }
        index = 0;
        leftLower = "";
        leftUpper = "";
        rightLower = "";
        rightUpper = "";
    }
    cout << total << endl;
}