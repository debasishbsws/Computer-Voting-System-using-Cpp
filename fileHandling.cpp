#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class FileWritting
{

public:
    // fileHandling();
    // ~fileHandling();
    void write(string fileName, string data);
    void appendNewLine(string fileName, string data);
    void deleteLineByNumber(string fileName, int lineNo);
    //  read(string fileName);
};

//rewrite the whole file
void FileWritting::write(string fileName, string data)
{
    ofstream out(fileName);
    out << data;
    out.close();
}

//append a new line to the file
void FileWritting::appendNewLine(string fileName, string data)
{
    ofstream out(fileName, std::ios_base::app);
    out << data;
    out.close();
}

//delete specific line number
void FileWritting::deleteLineByNumber(string fileName, int n)
{
    ifstream ins(fileName);

    // open file in write mode or out mode
    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);

    int line_no = 1;
    string line;
    while (getline(ins, line))
    {
        if (line_no == n)
        {
            ofs << "\n";
        }
        else
        {
            ofs << line << "\n";
        }
    }
    ofs.close();
    ins.close();

    // replacing the original file
    char *name;
    name = &fileName[0];
    remove(name);
    rename("temp.txt", name);
}
