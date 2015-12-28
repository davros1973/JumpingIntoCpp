// ch5_practice.cpp : Defines the entry point for the console application.
//

// http://www.amazon.co.uk/Jumping-into-C-Alex-Allain/dp/0988927802
// Chapter 5
// practice question 1

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
    // The loop goes while i < 10, and i increases by one 
    // every loop

    for (int i = 0; i < 10; i++)
    {
        // keep in mind that the loop condition checks
        // the conditional statement before it loops 
        // again.  Consequently, when i equals 10 the
        // loop breaks. i is updated before the 
        // condition is checked

        cout << i << " squared is " << i * i << endl;
    }

    /*
        1. Initialization step          i = 0
        2. Condition checked.           i < 10 so body run
        3. Update step                  i++
        4. Condition checked.           i < 10 (true = loop / body run)  (false = come out of loop) 
        5. ... if false                 body run ... goto step 3
    */

    MacroWaitReturn
}
