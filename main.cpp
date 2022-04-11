#include <iostream>
using namespace std;


void admin(){
    cout << "1. See Result\n2. Add new voters\n3. delete voter\n4. delete all voters\n5. RESET()\n6.Start Setup"<<endl;
}

void voting(){
    cout << "vote";
}

int main()
{
    int ch = 10;
    while (ch != 0)
    {
        cout << "1. ADMIN\n2. VOTE\n0. EXIT"<< endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            admin();
            break;
        case 2:
            voting();
            break;
        case 0:
            cout << "Exiting..";
        default:
            break;
        }
    }
    
}