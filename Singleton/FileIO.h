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
    static bool fileWrite(string filename, vector<string>* file_text);

private:
    
};

#endif


