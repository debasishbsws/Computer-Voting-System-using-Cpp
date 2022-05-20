#include <iostream>
#include <fstream>
#include <conio.h>
#include "fileHandling.cpp"

using namespace std;

class adminC
{
private:
    FileWritting writter;

public:
    string password = "password";
    void reset();
    void deleteAllVoters();
    void deleteVoter(string id);
    void startSetup();
    void addVoters();
    void seeResult();
};

void adminC::seeResult()
{
    cout << endl;
    ifstream in("DATA/Result.txt");
    int voteCount;
    string line;
    in >> voteCount;
    getline(in, line);
    while (!in.eof())
    {
        cout << endl
             << "      " << line << " get total " << voteCount << " Votes." << endl;
        in >> voteCount;
        getline(in, line);
    }
}

void adminC::addVoters()
{
    cout << "       Now we are going to add new voters in voter list  " << endl
         << endl;

    cout << "       Enter how many Voters you want to add  : ";
    int n;
    cin >> n;
    cout << endl
         << endl;
    string VoterName, ID, dob;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        cout << "       Enter the name of the Voter " << i + 1 << ": ";
        getline(cin, VoterName);
        cout << "       Enter the Voter ID of " << VoterName << ": ";
        getline(cin, ID);
        cout << "       Enter the Date of Birth " << VoterName << ": ";
        getline(cin, dob);
        writter.appendNewLine("DATA/VoterDetails.txt", ID + " " + VoterName + " " + dob + "\n");
        cout << "-------------------------------------------------------------------------------\n"
             << endl;
    }
}

void adminC::reset()
{
    writter.write("DATA/Result.txt", "NA");
    writter.write("DATA/AlredyVoted.txt", "");
}

void adminC::startSetup()
{
    reset();
    writter.write("DATA/Result.txt", "");

    cout << endl;
    cout << "       Enter how many Candidates: ";
    int n;
    cin >> n;
    string candidateName, party, symbol;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        cout << "       Enter the name of the candidate " << i + 1 << ": ";
        getline(cin, candidateName);
        cout << "       Enter the party name of the candidate " << candidateName << ": ";
        getline(cin, party);
        cout << "       Enter the symbol of the party " << party << ": ";
        getline(cin, symbol);
        writter.appendNewLine("DATA/Result.txt", "0 " + candidateName + " of party " + party + " (" + symbol + ")\n");
        cout << endl;
    }
}

void adminC::deleteAllVoters()
{
    writter.write("DATA/VoterDetails.txt", "");
}

// delete voter from voter list by ID
void adminC::deleteVoter(string ID)
{
    ifstream inVoter("DATA/VoterDetails.txt");
    string id, name, dob;
    int n = 1;
    while (!inVoter.eof())
    {
        inVoter >> id;
        inVoter >> name;
        inVoter >> dob;
        if (id == ID)
        {
            cout << "Voter Id: " << id << ", Name: " << name << ", DOB: " << dob;
            cout << "Deleted from the Voter List." << endl;
            writter.deleteLineByNumber("DATA/VoterDetails.txt", n);
            return;
        }
        n++;
    }
    if (inVoter.eof())
        cout << "\n Voter Not Found" << endl;
    inVoter.close();
}