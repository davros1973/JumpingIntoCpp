// ch4_practice.cpp : Defines the entry point for the console application.
//

// http://www.amazon.co.uk/Jumping-into-C-Alex-Allain/dp/0988927802
// Chapter 4
// practice question 4

/*
Expand the password checking program from earlier in this chapter and make it take multiple
usernames, each with their own password, and ensure that the right username is used for the right
password. Provide the ability to prompt users again if the first login attempt failed. Think about how easy
(or hard) it is to do this for a lot of usernames and passwords.
*/


// Using this book, primarily in Visual Studio 2015 community on Windows 10,
// but also linux gcc, and code::blocks on Windows
// ... to quickly relearn (earlier incarnation of) C++ with firmer foundations ...
// to help me with Arduino ...
// and Windows Universal apps (C++/Cx)
// (Originally learned C++ in the 90's).  David Bayliss  dave@xarta.co.uk

#include "stdafx.h"
#include <iostream>
#include <string>

// __cplusplus is defined in Visual Studio 2015
// if in this environment, wait for a keypress before returning, closing the command window
// cin.ignore(); flush the buffer for any /n in stream etc.!
#define MacroWaitReturn return 0;
#ifdef __cplusplus
#if __cplusplus == 199711
#undef MacroWaitReturn
#define MacroWaitReturn string wait = ""; \
                 cout << endl; \
                 cout << "Please press any key to exit from main" << endl; \
                 cin.ignore();  \
                 getline(cin, wait, '\n'); \
                 return 0;
#endif
#endif

using namespace std;

// Limitations: cin ... no type checking, testing etc.

int main()
{
    string username;
    string password;

    cout << "Enter your username: " << "\n";
    getline(cin, username, '\n');

    cout << "Enter your password: " << "\n";
    getline(cin, password, '\n');

    if (username == "root" && password == "xyzzy")
    {
        cout << "Access allowed" << "\n";
    }
    else
    {
        cout << "Bad username or password. Denied access!" << "\n";
        // early exit
        MacroWaitReturn
    }
    // remainder of programme
    MacroWaitReturn
}
