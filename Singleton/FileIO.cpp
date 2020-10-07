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

bool FileIO::fileWrite(string filename, string* file_text, bool isAppend)
{
    ofstream file;
	if (isAppend)
		file.open(filename, ios_base::app);
    else
        file.open(filename);

    if (!file.is_open())
    {
        cout << "Error opening " << filename << endl;
        return false;
    }

    file << file_text->data() << endl;
    file.close();
    return true;
}
