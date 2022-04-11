#include <iostream>
#include <fstream>
#include "fileHandling.cpp"

using namespace std;

class admin
{
private:
    string password = "password";
    FileWritting writter;

public:
    admin();
    ~admin();
    void reset();
    void deleteAllVoters();
    void deleteVoter(string id);
    void startSetup();
    void addVoters();
    void seeResult();
};

void admin::seeResult()
{
    ifstream in("DATA/Result.txt");
    int voteCount;
    string line;
    while (!in.eof())
    {
        in >> voteCount;
        getline(in, line);
        cout << line << " get " << voteCount << " Votes." << endl;
    }
}
void admin::addVoters()
{
    cout << "Enter how many Voters : ";
    int n;
    cin >> n;
    string VoterName, ID, dob;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of the Voter " << i + 1 << ": ";
        getline(cin, VoterName);
        cout << "Enter the Voter ID of " << VoterName << ": ";
        getline(cin, ID);
        cout << "Enter the Date of Birth " << VoterName << ": ";
        getline(cin, dob);
        writter.appendNewLine("DATA/VoterDetails.txt", "\n" + ID + " " + VoterName + " " + dob);
    }
}

void admin::startSetup()
{
    reset();
    writter.write("DATA/Result.txt", "");
    cout << "Enter how many Candidates: ";
    int n;
    cin >> n;
    string candidateName, party, symbol;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of the candidate " << i + 1 << ": ";
        getline(cin, candidateName);
        cout << "Enter the party name of the candidate " << candidateName << ": ";
        getline(cin, party);
        cout << "Enter the symbol of the party " << party << ": ";
        getline(cin, symbol);
        writter.appendNewLine("DATA/Result.txt", "0 " + candidateName + " of party " + party + " (" + symbol + ")\n");
        cout << endl;
    }

    cout << "\n You are Ready to start the Voteing.\n";
}

void admin::reset()
{
    writter.write("DATA/Result.txt", "NA");
    writter.write("DATA/AlredyVoted.txt", "");
}

void admin::deleteAllVoters()
{
    writter.write("DATA/VoterDetails.txt", "");
}

void admin::deleteVoter(string ID)
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
            writter.deleteLineByNumber("DATA/VoterDetails.txt", n);
            return;
        }
        n++;
    }
    if (inVoter.eof())
        cout << "\n Voter Not Found" << endl;
    inVoter.close();
}

// admin::admin(/* args */)
// {
//     cout << "admin";
// }

// admin::~admin()
// {
// }