// ch6_practice.cpp : Defines the entry point for the console application.
//

// http://www.amazon.co.uk/Jumping-into-C-Alex-Allain/dp/0988927802
// Chapter 6
// practice question 1, 2 and 3 combined

/*
Take the "menu program" you wrote earlier and breka it out into a series of callas to functions for each of 
the menu items.  Add the calculator and "99 Bottles of Beer" as two different functions that can be called.

Make your calculator program perform computations in a separate function for each type of computation.
DECIDED NOT TO DO THIS ... SEEMS LITTLE POINT (UNDERSTAND DOUBLE RETURN) ... UNLESS OVERRIDING OPERATOR,
OR HAVING DIVIDE BY ZERO CHECK IN DIVISION OPERATION SOMEHOW: PASS BY REFERENCE ETC.

Modify your password program from before to put all of the password checking logic into a separate
function, apart from the rest of the program.
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

// prototypes
bool passwordAccepted(void);
void calculator(void);
void beerBottles(void);

int main()
{
    int menuItem = 0;

    if (!passwordAccepted())
    {
        MacroWaitReturn;
    }


    do
    {
        cout << "Menu\n\n" << "1. calculator\n" << "2. 99 Bottles of Beer\n" << "3. Exit\n" << endl;
        cout << "Please select 1, 2 or 3 ..." << endl;

        cin >> menuItem;

        switch (menuItem)
        {
        case 1:
            calculator();
            break;
        case 2:
            beerBottles();
            break;
        case 3:
            break;
        default:
            continue;
            break;
        }
    } while (!(menuItem == 3));



    MacroWaitReturn
}


bool passwordAccepted(void)
{
    string passwordSubmission = "";

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

    return attemptsRemaining; // implicit cast to bool
}

void calculator(void)
{
    double operandA = 0;
    double operandB = 0;
    double answer = 0;
    string myOperator = "+";

    cin.ignore(); // to "flush" earlier menu selection from stream (ready for getline())

    do
    {
        cout << "Please enter operator, x, /, +, - (times, divide by, plus, minus): " << endl;
        getline(cin, myOperator, '\n');

    } while (!(myOperator == "x" || myOperator == "/" || myOperator == "+" || myOperator == "-"));

    cout << "Please enter first operand" << endl;
    cin >> operandA; // not type safe

    cout << "PLease enter second operand" << endl;
    cin >> operandB; // not type safe

    if (!(operandB == 0 && myOperator == "/"))
    {

        if (myOperator == "+")
        {
            answer = operandA + operandB;
        }
        else if (myOperator == "-")
        {
            answer = operandA - operandB;

        }
        else if (myOperator == "x")
        {
            answer = operandA * operandB;
        }
        else
        {
            answer = operandA / operandB;
        }

        cout << operandA << " " << myOperator << " " << operandB << " = " << answer << endl;
    }
    else
    {
        cout << operandA << " " << myOperator << " " << operandB << " = ERROR: divide by zero" << endl;
    }
}


void beerBottles()
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
}