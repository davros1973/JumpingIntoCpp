// ch5_practice.cpp : Defines the entry point for the console application.
//

// http://www.amazon.co.uk/Jumping-into-C-Alex-Allain/dp/0988927802
// Chapter 5
// practice question 2

/*
Write a menu program that lets the user select from a list of options, and if the input is not one of the
options, reprint the list.
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
    int menuItem = 0;

    do
    {
        cout << "Menu\n\n" << "1. sausages\n" << "2. bacon\n" << "3. eggs\n" << endl;
        cout << "Please select 1, 2 or 3 ..." << endl;

        cin >> menuItem;
    } while (!(menuItem == 1 || menuItem == 2 || menuItem == 3));

    MacroWaitReturn
}
