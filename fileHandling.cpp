#include<iostream>
#include<fstream>

using namespace std;

class fileHandling
{
    
public:
    // fileHandling();
    // ~fileHandling();
    void write(string fileName, string data);
    void writeNewLine(string fileName, string data);
    //  read(string fileName);
};


void fileHandling::write(string fileName, string data)
{
    ofstream out(fileName);
    out << data;
    out.close();
}

void fileHandling::writeNewLine(string fileName, string data)
{
    ofstream out(fileName);
    out << data;
    out.close();
}


// fileHandling::fileHandling()
// {
// }

// fileHandling::~fileHandling()
// {
// }
