#include <iostream>
#include <fstream>
#include "fileHandling.cpp"

using namespace std;

class admin
{
private:
    string password = "password";
    fileHandling handler;
public:
    admin();
    ~admin();
    void reset();
    void deleteAllVoters();
};

admin::admin(/* args */)
{
    cout << "admin";
}

admin::~admin()
{
}

void admin::reset()
{
//     ofstream temp;
//     temp.open("DATA/Result.txt");
//     temp << "";
//     temp.close();
    handler.write("DATA/Result.txt", "");


//     temp.open("DATA/AlredyVoted.txt");
//     temp << "";
//     temp.close();
    handler.write("DATA/AlredyVoted.txt", "");
}

void admin::deleteAllVoters()
{
    // ofstream temp;
    // temp.open("DATA/VoterDetails.txt");
    // temp << "";
    // temp.close();
    handler.write("DATA/VoterDetails.txt", "");

    
}
