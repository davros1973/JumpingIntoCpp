// ch4_practice.cpp : Defines the entry point for the console application.
//

// http://www.amazon.co.uk/Jumping-into-C-Alex-Allain/dp/0988927802
// Chapter 4
// practice question 2

/*
Implement a simple "password" system that takes a password in the form of a number. Make it so that 
either of two numbers is valid, but use only one if statement to do the check.
*/


// Using this book, primarily in Visual Studio 2015 community on Windows 10,
// but also linux gcc, and code::blocks on Windows
// ... to quickly relearn (earlier incarnation of) C++ with firmer foundations ...
// to help me with Arduino ...
// and Windows Universal apps (C++/Cx)
// (Originally learned C++ in the 90's).  David Baylis  dave@xarta.co.uk

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
    int acceptPass1 = 45;
    int acceptPass2 = 1148;
    int submitPass = 0;

    cout << "Please enter password: " << endl;
    cin >> submitPass;

    if (submitPass == acceptPass1 || submitPass == acceptPass2)
    {
        cout << "Password is valid" << endl;
    }
    else
    {
        cout << "Invalid password";
    }

   
    MacroWaitReturn
}
