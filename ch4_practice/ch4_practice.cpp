// ch4_practice.cpp : Defines the entry point for the console application.
//

// http://www.amazon.co.uk/Jumping-into-C-Alex-Allain/dp/0988927802
// Chapter 4
// practice question 1


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
    int ageUser1 = 0;
    int ageUser2 = 0;

    cout << "User1 - please enter your age: " << endl;
    cin >> ageUser1;

    cout << "User2 - please enter your age: " << endl;
    cin >> ageUser2;

    if ( !(ageUser1 > 100 || ageUser2 > 100) && ageUser1 > ageUser2)
    {
        cout << "User1 is older than User2" << endl;
    }
    else if (!(ageUser1 > 100 || ageUser2 > 100) && ageUser2 > ageUser1)
    {
        cout << "User2 is older than User1" << endl;
    }
    else
    {
        cout << "A user is older than 100 years!" << endl;
    }
   
    MacroWaitReturn
}
