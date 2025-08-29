
#include "auth.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

using namespace std;

string sha256(const string &str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)str.c_str(), str.size(), hash);

    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

void registerUser(const string &dbPath)
{
    string username, password, u, p;
    cin.ignore();

    cout << "Please Enter Your user name: ";
    getline(cin, username);
    cout << "Please Enter Your password: ";
    getline(cin, password);

    string hashedPassword = sha256(password);

    ifstream infile(dbPath);

    while (infile >> u >> p)
    {
        if (u == username)
        {
            cout << "User Name is already exists!\n";
            infile.close();
            return;
        }
    }
    infile.close();

    ofstream file(dbPath, ios::app);
    if (file.is_open())
    {
        file << username << " " << hashedPassword << endl;
        cout << "Registration Sucessfull !";
    }
    file.close();
    
}

bool loginUser(const std::string &dbPath)
{
    string username, password, u, p;
    cout << "Please Enter Your user name: ";
    cin >> username;
    cout << "Please Enter Your password: ";
    cin >> password;

    string hashedPassword = sha256(password);

    ifstream file(dbPath);
    if (file.is_open())
    {
        while (file >> u >> p)
        {
            if (u == username && p == hashedPassword)
            {
                cout << "User Login Sucessfull!" << endl;
                file.close();
                return true;
            }
        }
    }
    cout << "Login failed! Invalid username or password.\n";
    return false;
}