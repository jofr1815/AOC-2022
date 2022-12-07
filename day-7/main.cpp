#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct directory {
    directory* parent;
    vector<directory*> subDirs;
    string name;
    int size = 0;
};

int main() {
    directory* home = new directory;
    home->name = "/";
    cout << home->size << endl;
    cout << home->name << endl;
    directory* newDir = new directory;
    newDir->name = "/a";
    home->subDirs.push_back(newDir);
    cout << home->subDirs[0]->name << endl;
    return 0;
}