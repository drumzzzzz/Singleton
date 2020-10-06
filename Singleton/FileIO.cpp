#include "FileIO.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

FileIO::FileIO(){}

vector<string>* FileIO::fileRead(string filename)
{
    ifstream file;
    file.open(filename);

    if (!file.is_open())
    {
        cout << "Error opening " << filename << endl;
        return nullptr;
    }

    vector<string>* file_text = new vector<string>();
    string line;
    while (getline(file, line))
    {
        file_text->push_back(line);
    }
    file.close();
    return file_text;
}

bool FileIO::fileWrite(string filename, vector<string>* file_text)
{
    ofstream file;
    file.open(filename);

    if (!file.is_open())
    {
        cout << "Error opening " << filename << endl;
        return false;
    }

    for (string s : *file_text)
    {
        file << s << endl;
    }

    file.close();
    return true;
}
