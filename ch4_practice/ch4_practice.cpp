// ch4_practice.cpp : Defines the entry point for the console application.
//

// practice question 1

#include "stdafx.h"
#include "dave.h"



int main()
{
    string username;
    string password;

    cout << "Enter your username: " << "\n";
    getline(cin, username, '\n');

    cout << "Enter your password: " << "\n";
    getline(cin, password, '\n');

    if ( username == "root" && password == "xyzzy" )
    {
        cout << "Access allowed" << "\n";
    }
    else
    {
        cout << "Bad username or password. Denied access!" << "\n";
        // returning is a convenient way to stop the program
        MacroWaitReturn
    }
   
    MacroWaitReturn
}
