// ch5_practice.cpp : Defines the entry point for the console application.
//

// http://www.amazon.co.uk/Jumping-into-C-Alex-Allain/dp/0988927802
// Chapter 5
// practice question 7

/*
Write a program that provides the option of tallying up the results of a poll with 3 possible values. The
first input to the program is the poll question; the next three inputs are the possible answers. The first
answer is indicated by 1, the second by 2, the theird by 3. The answers are tallied until a 0 is entered. The 
program should then show the results of the poll - try making a bar graph that shoes the results properly
scaled to fit on your screen no matter how many results were entered.
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
        Breaking down question:
        
        Poll:
            Ask ONE question:

            LOOP BEGIN ->
            Input answer ...
                0 terminate and show results incl. scaled bar-graph
                1, or
                2, or
                3
            LOOP BACK TO BEGIN

        No functions
        No arrays
        No structures etc.

        Can represent number of each answer, 1 or 2 or 3 by an integer each. Just a count.
        
        If no results, flat bar graph, 0.
        If all results are the same then flat bar graph, max. height.
        
        Otherwise:
        Then, take biggest (non-zero) result (or one of two results if same) and represent in a graph at a fixed height.
        Then take the next biggest (or same magnitude) result, and scale to scale on used on screen
        And then scale final result.

    */

    string question = "Which of these colours do you prefer?\n1. Orange, 2. Yellow, 3. Beige.\nAnswer 1, 2 or 3.";
    int answercount1 = 0;
    int answercount2 = 0;
    int answercount3 = 0;
    int answerbiggest = 0;
    int answer = 0;

    double scale1 = 0;
    double scale2 = 0;
    double scale3 = 0;

    int bargraphMax = 25; // max. asci characters high for bargraph
    int bar1 = 0;
    int bar2 = 0;
    int bar3 = 0;

    do
    {
        cout << question << endl;
        cin >> answer;

        // going to cheat and use a switch
        switch ( answer )
        {
            case 0:
                break;
            case 1:
                answercount1++;
                break;
            case 2:
                answercount2++;
                break;
            case 3:
                answercount3++;
                break;
            default:
                cout << "Please only enter 1, or 2, or 3 ... or 0 to tally." << endl;
                break;
        }

    } while (answer);
    
    if (answercount1 == answercount2 && answercount2 == answercount3)
    {
        if (answercount1 == 0)
        {
            bar1 = 0;
            bar2 = 0;
            bar3 = 0;
        }
        else if (answercount1 > bargraphMax)
        {
            bar1 = bargraphMax;
            bar2 = bargraphMax;
            bar3 = bargraphMax;
        }
        else
        {
            bar1 = answercount1;
            bar2 = answercount2;
            bar3 = answercount3;
        }
    }
    else
    {
        cout << "debug: answercount1 = " << answercount1 << endl;
        cout << "debug: answercount2 = " << answercount2 << endl;
        cout << "debug: answercount3 = " << answercount3 << endl;


        // can't use an array yet for simple insertion swap etc.  :(
        // could calculation max. iterations for a loop to sort answers ...
        // though without structures etc. that's still a bit messy with nominals.
        // but not doing that here.  Just find biggest result etc.

        if (  answercount1 >= answercount2 && answercount2 >= answercount3  ||
              answercount1 >= answercount3 && answercount3 >= answercount2  )
        {
            cout << "debug: answercount1 is biggest" << endl;
            answerbiggest = answercount1;

            if (answerbiggest > bargraphMax)
            {
                scale1 = bargraphMax;
                scale2 = answercount2 / (double)answercount1 * bargraphMax;
                scale3 = answercount3 / (double)answercount1 * bargraphMax;
            }
            else
            {
                scale1 = answercount1;
                scale2 = answercount2;
                scale3 = answercount3;
            }
            
        }
        else if (  answercount2 >= answercount1 && answercount1 >= answercount3  ||
                   answercount2 >= answercount3 && answercount3 >= answercount1  )
        {
            cout << "debug: answercount2 is biggest" << endl;
            answerbiggest = answercount2;

            if (answerbiggest > bargraphMax)
            {
                scale2 = bargraphMax;
                scale1 = answercount1 / (double)answercount2 * bargraphMax;
                scale3 = answercount3 / (double)answercount2 * bargraphMax;
            }
            else
            {
                scale1 = answercount1;
                scale2 = answercount2;
                scale3 = answercount3;
            }
            

        }
        else
        {
            cout << "debug: answercount3 is biggest" << endl;
            answerbiggest = answercount3;

            if (answerbiggest > bargraphMax)
            {
                scale3 = bargraphMax;
                scale1 = answercount1 / (double)answercount3 * bargraphMax;
                scale2 = answercount2 / (double)answercount3 * bargraphMax;
            }
            else
            {
                scale1 = answercount1;
                scale2 = answercount2;
                scale3 = answercount3;

            }
            
        }

        bar1 = scale1; // implict cast to int
        bar2 = scale2;
        bar3 = scale3;
    }

    // OUTPUT
    
    // make cartesian ordinal raster using x, y in nested For loop
    // make bargraph columns 5 characters wide
    // ... with 1 character spacing

    // top  -> down
    // left -> right (bar1, bar2, bar3)
 
    cout << "bar1 = " << bar1 << endl;
    cout << "bar2 = " << bar2 << endl;
    cout << "bar3 = " << bar3 << endl;


    for (int y = bargraphMax-1; y >= 0; y--)
    {
        for (int x = 0; x < ((3 * 5) + (1 * 2)); x++)
        {
            if (x < 5 || x > 5 && x < 11 || x > 11 && x < 17)
            {
                if ( x < 5  && bar1 > y ||
                     x > 5  && x < 11   && bar2 > y ||
                     x > 11 && x < 17   && bar3 > y)
                {
                    cout << "@";
                }
                else
                {
                    cout << ".";
                }
            }
            else
            {
                cout << ".";
            }
        }
        cout << endl;
    }

    if (answerbiggest < 100)
    {
        // approx. ... would format this more nicely using say, string conversion
        //             and padding ... or more ifs / and padding.
        cout << ".." << answercount1 << ". .." << answercount2 << ". .." << answercount3 << "." << endl;
    }
    

    MacroWaitReturn
}
