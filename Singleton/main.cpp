#define _CRT_SECURE_NO_WARNINGS // Disable Vstudio warnings
#include <iostream>
#include <vector>
#include <time.h>
#include "FileIO.h"
using namespace std;

// Base class: inherits file IO utilities
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
	// Returns singleton object instance
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

	// Adds a single record to data array formatted with the date/time, source and data
    void addRecord(string filesource, string file_text)
	{
        string* text = new string();

    	// This could use a millisecond function
        time_t datetime = time(NULL);
        text->append(asctime(localtime(&datetime)));
        text->pop_back();
        text->append("\t");
        text->append(filesource);
        text->append("\t");
        text->append(file_text);
        data.push_back(text->data());
    }

	void clearRecords()
    {
        data.clear();
    }

	// Attempts a file read, display contents and results
	void readRecords()
    {
        vector<string>* file_text = fileRead(filename);

        if (file_text != nullptr)
        {
            for (string s : *file_text)
            {
                cout << s << endl;
            }
        }

        cout << "[ " << file_text->size() << " Records Read ]" << endl;
    }

    // Attempts a file write, display results
	void writeRecords()
    {  
        string* text = new string();

    	// Appends file header if not created yet
    	if (!instance->isHeader)
        {
            data.insert(data.begin(), "Date Time\t\t\tSource\tRecord");
        }

        if (fileWrite(filename, &data, instance->isHeader))
        {
            instance->isHeader = true;
            cout << "[ " << data.size() << " Records Written ]" << endl;
            data.clear();
        }
    }
};

// Init instance pointer and random hex values
DataLogger* DataLogger::instance = nullptr;
const char hex_chars[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

// Returns a randomly generated 20 character hex string
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

    // Add, write and read from dl1
    DataLogger *dl1 = dl1->getInstance();
    for (int i = 0; i < (rand() % 15) + 5; i++)
    {
        dl1->addRecord("dl1", getHexString()->data());
    }
    dl1->writeRecords();
    dl1->readRecords();

    // Add, write and read from dl2
    DataLogger* dl2 = dl2->getInstance();
    for (int i = 0; i < (rand() % 15) + 5; i++)
    {
        dl2->addRecord("dl2", getHexString()->data());
    }
    dl2->writeRecords();
    dl2->readRecords();

    // Add records to both dl1 and dl2, write from dl1 and read from dl2 
    for (int i = 0; i < (rand() % 10) + 5; i++)
    {
        dl1->addRecord("dl1", getHexString()->data());
        dl2->addRecord("dl2", getHexString()->data());
    }
    dl1->writeRecords();
    dl2->readRecords();
	
    return 0;
}