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
    int completeOverlap = 0;
    int partialOverlap = 0;
    while (!input.eof()) {
        getline(input, line);
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

        // If one range completely includes the other, increment total
        if((stoi(leftLower) >= stoi(rightLower) && stoi(leftUpper) <= stoi(rightUpper)) || (stoi(leftLower) <= stoi(rightLower) && stoi(leftUpper) >= stoi(rightUpper))) {
            completeOverlap++;
        }
        for (int i = stoi(leftLower); i <= stoi(leftUpper); i++) {
            if (i >= stoi(rightLower) && i <= stoi(rightUpper)) {
                partialOverlap++;
                i = stoi(leftUpper) + 1;
            }
        }
        index = 0;
        leftLower = "";
        leftUpper = "";
        rightLower = "";
        rightUpper = "";
    }
    cout << "Pairs with complete overlap: " << completeOverlap << endl;
    cout << "Pairs with partial overlap: " << partialOverlap << endl;
}