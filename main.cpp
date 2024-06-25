#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

#define _SO_IMPLEMENTATION
#include"Texty.hpp"

int main() {
    string file_name = "Texty.hpp";
    FileHandle file(file_name);

    string content = file.getContents();
    // file.separateWords();
    // file.showWords();
    // file.toLower();

    // cout << endl << file.fileContent << endl;
    // cout << file.averageWordLength() << endl;
    // file.showLineContents();

    file.findWordinFile("temp");
    return 0;
}

