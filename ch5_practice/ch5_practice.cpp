// ch5_practice.cpp : Defines the entry point for the console application.
//

// http://www.amazon.co.uk/Jumping-into-C-Alex-Allain/dp/0988927802
// Chapter 5
// practice question 4

/*
Write a password prompt that gives a user only a certain number of password entry attempts - so that
the user cannot easily write a password cracker.
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
//               ... if no cin before then have to press a key twice to exit ... no prob. for practice tests
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
    string passwordSubmission = "";

    cout << "For loop implementation: " << endl;

    for (int attemptsRemaining = 3; attemptsRemaining > 0; attemptsRemaining--)
    {
        cout << "Please enter your password to continue: " << endl;
        getline(cin, passwordSubmission, '\n');

        if (passwordSubmission == "blahblah")
        {
            cout << "Well done!  You may proceed" << endl;
            break;
        }
        else if ( attemptsRemaining -1 > 0 )
        {
            cout << "Please try again ... attempts remaining = " << attemptsRemaining - 1 << endl;
        }
        else
        {
            cout << "No more attempts remaaining. You cannot proceed. Password incorrect" << endl;
        }
    }

    cout << "While loop implementation: " << endl;

    // nb: attemptsRemaining declared before was local to the block with the For
    int attemptsRemaining = 3;

    while (attemptsRemaining > 0)
    {
        cout << "Please enter your password to continue: " << endl;
        getline(cin, passwordSubmission, '\n');

        if (passwordSubmission == "blahblah")
        {
            cout << "Well done! You may proceed" << endl;
            break;
        }
        else
        {
            attemptsRemaining--;
            cout << "Password incorrect. " << attemptsRemaining << " attempts remaining." << endl;
        }
        if (!attemptsRemaining)
        {
            cout << "You cannot proceed.  Bye." << endl;
        }
    }

    MacroWaitReturn
}
