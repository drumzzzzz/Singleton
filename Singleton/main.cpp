#include <iostream>
#include <vector>
// Main
#include "FileIO.h"

using namespace std;

class DataLogger : public FileIO
{
private:
	static DataLogger* instance;
    vector<string> data;

	DataLogger()
	{
        data.clear();
	}

public:
    static DataLogger *getInstance()
	{
        if (!instance) 
        {
            instance = new DataLogger();
        }
        return instance;
    }

    vector<string> getData()
	{
        return data;
    }

    void setData(string newData)
	{
        data.push_back(newData);
    }

	void clearData()
    {
        data.clear();
    }

	int getLength()
    {
        return data.size();
    }

	void readData()
    {
        vector<string>* file_text = fileRead("test.txt");

        for (string s : *file_text)
        {
            cout << s << endl;
        }
    }

	void writeData(vector<string>* file_text)
    {
        fileWrite("test.txt", file_text);
    }
};

// Init pointer
DataLogger* DataLogger::instance = nullptr;

int main()
{
    DataLogger *dl = dl->getInstance();

    vector<string>* test_log = new vector<string>();
    test_log->push_back("Hello world!");
    test_log->push_back("Its Working!");

    dl->writeData(test_log);
	
    dl->readData();

    return 0;
}