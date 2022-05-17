#include <iostream>
#include "admin.cpp"
using namespace std;

void admin()
{
    adminC ad;
    int ch = 100;
    while (ch != 0)
    {
        cout << "1. See Result\n2. Start Setup\n3. delete voter\n4. delete all voters\n5. RESET()\n6. Add new voters \n0: EXIT" << endl;
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

void voting()
{
    cout << "vote";
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