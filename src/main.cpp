
#include <iostream>
#include "auth.h"

using namespace std;

int main()
{
    const string dbPath = "../data/users.txt";
    int choise;
    while (true)
    {
        cout << "\n1. Register\n2. Login\n3. Exit\n";
        cout << "Please Enter Your Choise: ";
        cin >> choise;
        switch (choise)
        {
        case 1:
            registerUser(dbPath);
            break;
        case 2:
            loginUser(dbPath);
            break;
        case 3:
            cout << "Exiting ...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}