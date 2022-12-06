#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void printArr(string arr[]) {
    for (int i = 0; i < 9; i++) {
        cout << i+1 << ". ";
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

void moveBoxes(int quantity, string &origin, string &dest) {
    for(int i = 0; i < quantity; i++) {
        //cout << "moving: " << origin[origin.length()-1] << endl;
        dest.push_back(origin[origin.length()-1]);
        origin.pop_back();
    }
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
        for (int i = 0; i < 9; i++) {
            cout << line[i*4 + 1] << " ";
            if (line[i*4 + 1] != ' ' && line[i*4 + 1] != 0) {
                arr[i].push_back(line[i*4 + 1]);
            }
        }
        cout << endl;
        getline(input, line);
    }
    // Print out array of strings

    // Reverse strings so that top box is at the top of the stack
    for (int i = 0; i < 9; i ++) {
        reverseStr(arr[i]);
    }
    cout << endl;
    // Print out array to verify the strings have been reversed
    printArr(arr);

    // Create and initialize variables for parsing instructions
    int quantity = 0;
    int origin = 0;
    int dest = 0;
    int index = 0;
    string parser;

    getline(input, line);
    // Print out rest of file, ie the instructions
    while (!input.eof()) {
        getline(input, line);
        //cout << line << endl;

        // Parse instruction into quantity, origin, and destination
        index = 0;

        // Find the start of the quantity #
        while(line[index] < 48 || line[index] > 57) {
            index++;
        }
        // Insert number into a parsing string
        while(line[index] != ' ') {
            parser.push_back(line[index]);
            index++;
        }

        // Set quantity to the value extracted by the parser
        quantity = stoi(parser);
        //cout << quantity << " ";

        // Clear the parser for the next number
        parser.clear();

        // Continue parsing the string to the next number (origin)
        while(line[index] < 48 || line[index] > 57) {
            index++;
        }

        // Extract the second number from the input string
        // The locations are labeled 1 through 9, so now we can just extract the character at the index
        origin = int(line[index] - '0');
        // Correct for the 0 indexed array
        origin--;
        //cout << origin << " ";

        // Extract the end number (destination)
        dest = int(line[line.length() - 1] - '0');
        // Correct for 0 index of array
        dest--;
        //cout << dest << endl;

        // Move boxes according to the instructions
        moveBoxes(quantity, arr[origin], arr[dest]);

        //printArr(arr);
    }

    string result;
    for (int i = 0; i < 9; i++){
        result.push_back(arr[i][arr[i].length()-1]);
    }
    cout << "result: " << result << endl;
    return 0;
}