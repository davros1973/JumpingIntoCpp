// ch4_practice.cpp : Defines the entry point for the console application.
//

// http://www.amazon.co.uk/Jumping-into-C-Alex-Allain/dp/0988927802
// Chapter 4
// practice question 3

/*
Write a small calculator that takes as input one of the four arithmetic operations,
the two arguments to those operations, and then prints out the result
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
    double operandA = 0;
    double operandB = 0;
    double answer = 0;
    string myOperator = "+";

    // cheating ... using a loop earlier than in book

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
   
    MacroWaitReturn
}
