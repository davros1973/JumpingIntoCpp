// ch7_practice.cpp : Defines the entry point for the console application.
//

// http://www.amazon.co.uk/Jumping-into-C-Alex-Allain/dp/0988927802
// Chapter 7
// practice question 1, 2 and 3 combined

/*
Rewrite the menu program you wrote in the practice problems fo rthe Functions chapter using
switch-case (ALREADY DONE)

Write a program that outputs all the lyrics of The Twelve Days of Christmas
(http://en.wikipedia.org/wiki/The_Twelve_Days_of_Christmas_(song) ) using switch-case (hint: you
might want to take advantage of fall-through cases).

Write a two-player tic-tac-toe game, allowing two humans to play against each other; use enums when
possible to represent the values of the board
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

// enum for tictactoe functions ... global type
// ... define before function prototypes

enum TicTacToeSquare
{
    TTTS_BLANK,
    TTTS_0,
    TTTS_X
};


// prototypes
bool passwordAccepted(void);
void calculator(void);
void beerBottles(void);

void tictactoe(void);
void tictactoePlayMultiPlayer(void);
int getTicTacToeMove(   TicTacToeSquare square1,
                        TicTacToeSquare square2,
                        TicTacToeSquare square3,
                        TicTacToeSquare square4,
                        TicTacToeSquare square5,
                        TicTacToeSquare square6,
                        TicTacToeSquare square7,
                        TicTacToeSquare square8,
                        TicTacToeSquare square9);
bool ticTacToeFinished( TicTacToeSquare square1,
                        TicTacToeSquare square2,
                        TicTacToeSquare square3,
                        TicTacToeSquare square4,
                        TicTacToeSquare square5,
                        TicTacToeSquare square6,
                        TicTacToeSquare square7,
                        TicTacToeSquare square8,
                        TicTacToeSquare square9);
TicTacToeSquare getTicTacToePosStatus(
                        TicTacToeSquare square1,
                        TicTacToeSquare square2,
                        TicTacToeSquare square3,
                        TicTacToeSquare square4,
                        TicTacToeSquare square5,
                        TicTacToeSquare square6,
                        TicTacToeSquare square7,
                        TicTacToeSquare square8,
                        TicTacToeSquare square9,
                        int boardPos);
void displayTicTacToe(  TicTacToeSquare square1,
                        TicTacToeSquare square2,
                        TicTacToeSquare square3,
                        TicTacToeSquare square4,
                        TicTacToeSquare square5,
                        TicTacToeSquare square6,
                        TicTacToeSquare square7,
                        TicTacToeSquare square8,
                        TicTacToeSquare square9);
string getTTTSstr(      TicTacToeSquare square);


void twXmas(void);
string getDayStr(int day); // i.e. 1 = First, 2 = Second




int main()
{
    enum menuItems {
        DAVE_EXIT = 0,
        DAVE_CALC = 1,
        DAVE_BOTTLES = 2,
        DAVE_XMAS = 3,
        DAVE_TICTAC = 4
    };


    menuItems menuItem = DAVE_EXIT;
    int menuChoice = 0;

    if (!passwordAccepted())
    {
        MacroWaitReturn;
    }


    do
    {
        cout << "Menu\n\n" << "1. calculator\n" << "2. 99 Bottles of Beer\n" 
             << "3. Twelve Days of Christmas\n" << "4. Tic-Tac-Toe\n" << "0. Exit\n" << endl;
        cout << "Please input number for your menu choice ..." << endl;

        cin >> menuChoice;
        menuItem = (menuItems)menuChoice; // assuming at this stage this is the way to do this


        switch (menuItem)
        {
        case DAVE_CALC:
            calculator();
            break;
        case DAVE_BOTTLES:
            beerBottles();
            break;
        case DAVE_XMAS:
            twXmas();
            break;
        case DAVE_TICTAC:
            tictactoe();
            break;  
        case DAVE_EXIT:
            break;
        default:
            continue;
            break;
        }
    } while (menuItem); // implict cast to bool, exit when DAVE_EXIT i.e. int 0, bool false



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

    return attemptsRemaining; // implicit cast to bool ... compiler gives performance warning
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

void twXmas(void)
{
    for (int day = 1; day < 13; day++)
    {
        cout << "On the " << getDayStr(day) << " of Christmas my true love sent to me" << endl;

        switch (day)
        {
        case 12:
            cout << "Twelve Drummers Drumming" << endl;
        case 11:
            cout << "Eleven Pipers Piping" << endl;
        case 10:
            cout << "Ten Lords a-Leaping" << endl; 
        case 9:
            cout << "Nine Ladies Dancing" << endl;
        case 8:
            cout << "Eight Maids a-Milking" << endl;
        case 7:
            cout << "Seven Swans a-Swimming" << endl;
        case 6:
            cout << "Six Geese a-Laying" << endl;
        case 5:
            cout << "Five Gold Rings" << endl;
        case 4:
            cout << "Four Calling Birds" << endl;
        case 3:
            cout << "Three French Hens" << endl;
        case 2:
            cout << "Two Turtle Doves" << endl;
        case 1:
            if (day > 1)
            {
                cout << "and a Partridge in a Pear Tree" << endl;
            }
            else
            {
                cout << "a Partridge in a Pear Tree" << endl;
            }
            break;
        default:
            cout << "OTHER DAY?" << endl;
            break;
        }
        cout << endl;
    }
}

string getDayStr(int day)
{
    switch (day)
    {
    case 1:
        return "First";
        break;
    case 2:
        return "Second";
        break;
    case 3:
        return "Third";
        break;
    case 4:
        return "Fourth";
        break;
    case 5:
        return "Fith";
        break;
    case 6:
        return "Sixth";
        break;
    case 7:
        return "Seventh";
        break;
    case 8:
        return "Eighth";
        break;
    case 9:
        return "Ninth";
        break;
    case 10:
        return "Tenth";
        break;
    case 11:
        return "Eleventh";
        break;
    case 12:
        return "Twelfth";
        break;
    default:
        return "Other";
        break;
    }
}
void tictactoe(void)
{
    // TO DO
    tictactoePlayMultiPlayer();
}
void tictactoePlayMultiPlayer(void)
{
    // not using arrays yet
    // or structures :(

    // NOT RECOGNISING WINNER YET ... JUST PLAY ALL BOARD POSITIONS IN TURN

    cout << "Welcome to Tic Tac Toe\n Please use the following board positioning system for moves:\n" << endl;

    cout << " 1 | 2 | 3 " << endl;
    cout << "-----------" << endl;
    cout << " 4 | 5 | 6 " << endl;
    cout << "-----------" << endl;
    cout << " 7 | 8 | 9 " << endl;

    cout << endl;
    cout << endl;


    // initialise
    TicTacToeSquare square1 = TTTS_BLANK;
    TicTacToeSquare square2 = TTTS_BLANK;
    TicTacToeSquare square3 = TTTS_BLANK;
    TicTacToeSquare square4 = TTTS_BLANK;
    TicTacToeSquare square5 = TTTS_BLANK;
    TicTacToeSquare square6 = TTTS_BLANK;
    TicTacToeSquare square7 = TTTS_BLANK;
    TicTacToeSquare square8 = TTTS_BLANK;
    TicTacToeSquare square9 = TTTS_BLANK;

    // main game-play loop until finished
    while (!ticTacToeFinished(square1, square2, square3, square4, square5, square6, square7, square8, square9))
    {
        displayTicTacToe(square1, square2, square3, square4, square5, square6, square7, square8, square9);

        // FIRST PLAYER
        if (!ticTacToeFinished(square1, square2, square3, square4, square5, square6, square7, square8, square9))
        {
            cout << "Player X's ... please choose a blank position, 1 to 9" << endl;
            switch (getTicTacToeMove(square1, square2, square3, square4, square5, square6, square7, square8, square9))
            {
            case 1:
                square1 = TTTS_X;
                break;
            case 2:
                square2 = TTTS_X;
                break;
            case 3:
                square3 = TTTS_X;
                break;
            case 4:
                square4 = TTTS_X;
                break;
            case 5:
                square5 = TTTS_X;
                break;
            case 6:
                square6 = TTTS_X;
                break;
            case 7:
                square7 = TTTS_X;
                break;
            case 8:
                square8 = TTTS_X;
                break;
            case 9:
                square9 = TTTS_X;
                break;
            }
        }

        displayTicTacToe(square1, square2, square3, square4, square5, square6, square7, square8, square9);

        // SECOND PLAYER
        if (!ticTacToeFinished(square1, square2, square3, square4, square5, square6, square7, square8, square9))
        {
            cout << "Player 0's ... please choose a blank position, 1 to 9" << endl;
            switch (getTicTacToeMove(square1, square2, square3, square4, square5, square6, square7, square8, square9))
            {
            case 1:
                square1 = TTTS_0;
                break;
            case 2:
                square2 = TTTS_0;
                break;
            case 3:
                square3 = TTTS_0;
                break;
            case 4:
                square4 = TTTS_0;
                break;
            case 5:
                square5 = TTTS_0;
                break;
            case 6:
                square6 = TTTS_0;
                break;
            case 7:
                square7 = TTTS_0;
                break;
            case 8:
                square8 = TTTS_0;
                break;
            case 9:
                square9 = TTTS_0;
                break;
            }
        }

    }


    // displayTicTacToe(square1, square2, square3, square4, square5, square6, square7, square8, square9); // display final board

}

int getTicTacToeMove(   TicTacToeSquare square1,
                        TicTacToeSquare square2,
                        TicTacToeSquare square3,
                        TicTacToeSquare square4,
                        TicTacToeSquare square5,
                        TicTacToeSquare square6,
                        TicTacToeSquare square7,
                        TicTacToeSquare square8,
                        TicTacToeSquare square9)
{
    int requestPos = 1;
    bool validMove = false;
    TicTacToeSquare status = TTTS_BLANK;

    while (!validMove)
    {
        cin >> requestPos;

        if (getTicTacToePosStatus(square1, square2, square3, square4, square5, square6, square7, square8, square9, requestPos) == TTTS_BLANK)
        {
            validMove = true;   
        }
        else
        {
            cout << "You have not chosen a blank position for your move, please try again:" << endl;
        }
    }
    
    return requestPos;

}

bool ticTacToeFinished( TicTacToeSquare square1,
                        TicTacToeSquare square2,
                        TicTacToeSquare square3,
                        TicTacToeSquare square4,
                        TicTacToeSquare square5,
                        TicTacToeSquare square6,
                        TicTacToeSquare square7,
                        TicTacToeSquare square8,
                        TicTacToeSquare square9)
{
    // Eventually test for a winning status to exit early

    // but for now ... see if any blank positions remain

    if (square1 == TTTS_BLANK ||
        square2 == TTTS_BLANK ||
        square3 == TTTS_BLANK ||
        square4 == TTTS_BLANK ||
        square5 == TTTS_BLANK ||
        square6 == TTTS_BLANK ||
        square7 == TTTS_BLANK ||
        square8 == TTTS_BLANK ||
        square9 == TTTS_BLANK )
    {
        return false;
    }
    else
    {
        return true;
    }
}



TicTacToeSquare getTicTacToePosStatus ( TicTacToeSquare square1,
                                        TicTacToeSquare square2,
                                        TicTacToeSquare square3,
                                        TicTacToeSquare square4,
                                        TicTacToeSquare square5,
                                        TicTacToeSquare square6,
                                        TicTacToeSquare square7,
                                        TicTacToeSquare square8,
                                        TicTacToeSquare square9,
                                        int boardPos)
{
    switch (boardPos)
    {
    case 1:
        return square1;
        break;
    case 2:
        return square2;
        break;
    case 3:
        return square3;
        break;
    case 4:
        return square4;
        break;
    case 5:
        return square5;
        break;
    case 6:
        return square6;
        break;
    case 7:
        return square7;
        break;
    case 8:
        return square8;
        break;
    case 9:
        return square9;
        break;
    default:
        return TTTS_BLANK;
        break;
    }
}



void displayTicTacToe(  TicTacToeSquare square1,
                        TicTacToeSquare square2,
                        TicTacToeSquare square3,
                        TicTacToeSquare square4,
                        TicTacToeSquare square5,
                        TicTacToeSquare square6,
                        TicTacToeSquare square7,
                        TicTacToeSquare square8,
                        TicTacToeSquare square9)
{
    cout << "***********************" << endl;
    cout << "*                     *" << endl;
    cout << "*      " << getTTTSstr(square1) << " | " << getTTTSstr(square2) << " | " << getTTTSstr(square3) << "      *" << endl;
    cout << "*     -----------" << "     *" << endl;
    cout << "*      " << getTTTSstr(square4) << " | " << getTTTSstr(square5) << " | " << getTTTSstr(square6) << "      *" << endl;
    cout << "*     -----------" << "     *" << endl;
    cout << "*      " << getTTTSstr(square7) << " | " << getTTTSstr(square8) << " | " << getTTTSstr(square9) << "      *" << endl;
    cout << "*                     *" << endl;
    cout << "***********************" << endl;
}

string getTTTSstr(TicTacToeSquare square)
{
    string boardChar = " ";

    switch (square)
    {
    case TTTS_BLANK:
        boardChar = " ";
        break;
    case TTTS_0:
        boardChar = "0";
        break;
    case TTTS_X:
        boardChar = "X";
        break;
    default:
        boardChar = " ";
        break;
    }

    return boardChar;
}