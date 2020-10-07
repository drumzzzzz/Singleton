#define _CRT_SECURE_NO_WARNINGS // Disable Vstudio warning
#include <iostream>
#include <vector>
#include "FileIO.h"
#include <time.h>
using namespace std;

class DataLogger : public FileIO
{
private:
	static DataLogger* instance;
    vector<string> data;
    const string filename = "test.log";
    bool isHeader;
    
	// Private constructor to disallow instaneation
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
        vector<string>* file_text = fileRead(filename);

        cout << "\n[******* Data Read *******]" << endl;
        for (string s : *file_text)
        {
            cout << s << endl;
        }
    }

	void writeRecord(string filesource, string file_text)
    {
        string* text = new string();

    	// Append file heade if not created yet
    	if (!instance->isHeader)
        {
            text->append("Date Time\t\t\tSource\tRecord\n");
        }
    
        time_t datetime = time(NULL);
        text->append(asctime(localtime(&datetime)));
        text->pop_back();
        text->append("\t");
        text->append(filesource);
        text->append("\t");
        text->append(file_text);

        fileWrite(filename, text, instance->isHeader);
        instance->isHeader = true;
    }

	string getFileName()
    {
	    
    }
};

// Init instance pointer and random hex value array
DataLogger* DataLogger::instance = nullptr;
const char hex_chars[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

// Returns a randomly generated hex string
string* getHexString()
{
    string* values = new string();
    for (int i = 0; i < 20; i++)
    {
        values->push_back(hex_chars[rand() % 16]);
    }
    return values;
}

int main()
{
    srand(time(NULL));
    DataLogger *dl1 = dl1->getInstance();

    for (int i = 0; i < 10; i++)
    {
        dl1->writeRecord("dl1", getHexString()->data());
    }
	
    dl1->readData();

    DataLogger* dl2 = dl2->getInstance();
    dl2->readData();
    for (int i = 0; i < 10; i++)
    {
        dl2->writeRecord("dl2", getHexString()->data());
    }

    dl1->readData();

    for (int i = 0; i < 10; i++)
    {
        dl1->writeRecord("dl1", getHexString()->data());
    }

    dl2->readData();
	
    return 0;
}