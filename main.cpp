#include <iostream>
#include <fstream>
#include <vector>
#include "admin.cpp"

using namespace std;

FileWritting writter;

void admin()
{
    adminC ad;
    int ch = 100;
    while (ch != 0)
    {
        cout << "\n1. See Result\n2. Start Setup\n3. delete voter\n4. delete all voters\n5. RESET()\n6. Add new voters \n0: Back" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            ad.seeResult();
            break;
        }
        case 2:
        {
            ad.startSetup();
            break;
        }
        case 3:
        {
            string id;
            cin >> id;
            ad.deleteVoter(id);
            break;
        }
        case 4:
        {
            ad.deleteAllVoters();
            break;
        }
        case 5:
        {
            ad.reset();
            break;
        }
        case 6:
        {
            ad.addVoters();
            break;
        }
        case 0:
            cout << "Exiting";
        default:
            cout << "Invalid";
            break;
        }
        system("cls");
    }
}

bool is_empt(std::ifstream &pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

string searchVoter(string id)
{
    ifstream inVoter("DATA/VoterDetails.txt");
    string ID, name, dob;
    while (!inVoter.eof())
    {
        inVoter >> ID;
        inVoter >> name;
        inVoter >> dob;
        if (id == ID)
        {
            return "Voter Id: " + id + ", Name: " + name + ", DOB: " + dob;
        }
    }
    if (inVoter.eof())
        return "";
    inVoter.close();
    return "";
}

bool isAlredyVoted(string id)
{
    ifstream av("DATA/AlredyVoted.txt");
    string ID;
    getline(av, ID);
    while (!av.eof())
    {
        if (ID.compare(id) == 0)
        {
            return true;
        }
        getline(av, ID);
    }

    return false;
}

void voting()
{
    ifstream res("DATA/Result.txt");
    if (!res)
    {
        cout << "Result file is not in DATA folder" << endl;
        return;
    }
    if (is_empt(res))
    {
        cout << "Setup first" << endl;
        return;
    }

    int ch = 10;

    vector<int> vote;
    vector<string> candidate;
    int voteCount;
    string line;

    res >> voteCount;
    getline(res, line);
    while (!res.eof())
    {
        vote.push_back(voteCount);
        candidate.push_back(line);
        res >> voteCount;
        getline(res, line);
    }
    // vote.push_back(voteCount);
    // candidate.push_back(line);
    // for (int i = 0; i < candidate.size(); i++)
    // {
    //     string s = to_string(vote[i]) + " " + candidate[i] + "\n";
    //     cout << s;
    //     //writter.appendNewLine("DATA/Result.txt", s);
    // }

    while (ch != 0)
    {
        cout << "1. Give VOTE\n0. End Voting" << endl;
        cin >> ch;
        if (ch == 0)
        {
            writter.write("DATA/Result.txt", "");
            for (int i = 0; i < candidate.size(); i++)
            {
                string s = to_string(vote[i]) + candidate[i] + "\n";
                writter.appendNewLine("DATA/Result.txt", s);
            }
        }
        else if (ch == 1)
        {
            cout << "Enter Voter ID: ";
            string id;
            cin >> id;
            if (searchVoter(id) == "")
            {
                cout << "Voter not found" << endl;
                continue;
            }
            cout << searchVoter(id);
            if (isAlredyVoted(id))
            {
                cout << "\nYou have already voted." << endl;
                continue;
            }
            int v;
            for (int i = 0; i < candidate.size(); i++)
            {
                cout << "\n"
                     << i + 1 << "." << candidate[i];
            }
            cin >> v;
            vote[v - 1]++;
            writter.appendNewLine("DATA/AlredyVoted.txt", id + "\n");
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
    res.close();
}

int main()
{
    int ch = 10;
    while (ch != 0)
    {
        cout << "1. ADMIN\n2. START VOTE\n0. EXIT" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            system("cls");
            admin();
            break;
        case 2:
            system("cls");
            voting();
            break;
        case 0:
            cout << "Exiting..";
        default:
            break;
        }
    }
}
