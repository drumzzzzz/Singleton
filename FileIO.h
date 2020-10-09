/// FileIO.h: file reading and writing header

#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <vector>
using namespace std;

class FileIO
{
public:
    FileIO();
    static vector<string>* fileRead(string filename);
    static bool fileWrite(string filename, string* file_text, bool isAppend);
    static bool fileWrite(string filename, vector<string>* data, bool isAppend);
};

#endif


