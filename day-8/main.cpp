#include<fstream>
#include<string>
#include<cstring>
#include<iostream>

using namespace std;

int main(int argc, char** argv) {
    // Read in input file to 2d array
    string line; 
    int numLines = 0;

    ifstream input(argv[1]);

    while(getline(input, line)) {
        numLines++;
    }
    int lineLen = line.length();
    
    // Create array to store tree height values
    int arr[lineLen][numLines];

    // Fill in array from input
    input.clear();
    input.seekg(0);  
    for(int i = 0; i < numLines; i++){
        getline(input, line);
        for(int j = 0; j < lineLen; j++) {
            arr[i][j] = line[j] - '0';
        }
    }

    // Create array to store if a tree is visible or not
    bool vis[lineLen][numLines];
    memset(vis, false, sizeof(vis));

    // Traverse grid in each direction to determine if a tree is visible
    int max = -1; // Variable to hold maximum height found in a given row
 
    // Traverse left to right
    for(int i = 0; i < numLines; i++) {
        for(int j = 0; j < lineLen; j++) {
            if(max < arr[i][j]) {
                max = arr[i][j];
                vis[i][j] = true;
            }
        }
        max = -1;
    }
    // Traverse right to left
    for(int i = 0; i < numLines; i++) {
        for(int j = lineLen - 1; j >= 0; j--) {
            if(max < arr[i][j]) {
                max = arr[i][j];
                vis[i][j] = true;
            }
        }
        max = -1;
    }

    // Traverse top to bottom
    for(int j = 0; j < lineLen; j++) {
        for(int i = 0; i < numLines; i++) {
            if(max < arr[i][j]) {
                max = arr[i][j];
                vis[i][j] = true;
            }
        }
        max = -1;
    }


    // Traverse bottom to top
    for(int j = 0; j < lineLen; j++) {
        for(int i = numLines - 1; i >= 0; i--) {
            if(max < arr[i][j]) {
                max = arr[i][j];
                vis[i][j] = true;
            }
        }
        max = -1;
    }

    // Traverse visability grid to find number of visible trees
    int numVis = 0; 
    for(int i = 0; i < numLines; i++) {
        for(int j = 0; j < lineLen; j++){
            if (vis[i][j] == true) {
            numVis++;
        }
        }
    }
    cout << numVis << endl;
}