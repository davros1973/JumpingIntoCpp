// ch5_practice.cpp : Defines the entry point for the console application.
//

// http://www.amazon.co.uk/Jumping-into-C-Alex-Allain/dp/0988927802
// Chapter 5
// practice question 1

/*
Write a program that prints out the entire lyrics to a full rendition of "99 Bottles of Beer". (In case you
don't know this song, the words are here: http://en.wikipedia.org/wiki/99_Bottles_of_Beer )
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
    /*
        https://en.wikipedia.org/wiki/99_Bottles_of_Beer
        99 bottles of beer on the wall, 99 bottles of beer.
        Take one down, pass it around, 98 bottles of beer on the wall...

        No more bottles of beer on the wall, no more bottles of beer.
        Go to the store and buy some more, 99 bottles of beer on the wall...
    */

    // nb: In console output in Visual Studio 2015, on Windows 10, output of this slightly exceeds buffer
    //     with result that it SEEMS to start at 98 bottles!

    for (int bottles = 99; bottles >= 0; bottles--)
    {
        if (bottles)
        {
            cout << bottles << " bottles of beer on the wall, " << bottles << " bottles of beer." << endl;
            cout << "Take on down, pass it around, " << bottles - 1 << " bottles of beer on the wall ... " << endl;
        }
        else
        {
            cout << "No more bottles of beer on the wall, no more bottles of beer." << endl;
            cout << "Go to the store and buy some more, 99 bottles of beer on the wall ..." << endl;
        }

        cout << endl;
    }

    MacroWaitReturn
}
