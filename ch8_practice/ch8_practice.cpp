// ch8_practice.cpp : Defines the entry point for the console application.
//

// http://www.amazon.co.uk/Jumping-into-C-Alex-Allain/dp/0988927802
// Chapter 8
// practice questions combined

/*
1. Write a program that simulates a coin flip. Run it many times - do the results look random to you?

2. Write a program that picks a number between 1 and 100, and then lets the user guess what the number
is. The program should tell the user if their guess is too high, too low, or just right.

3. Write a program that solves the guess game from problem 2. How many guesses does your program need?

4. Make a "slot machine" game that randomly displays the results of a slot machien to a player - have
three (or more) possible values for each wheel of the slot machine. Don't worry about displaying the text
"spinning" by. Just choose the results and display them and print out the winnings (choose your own winning combinations).

5.) Write a program to play poker! You can provide 5 cards to the player, let that player choose new cards,
and then determine how good the hand is. Think about whether this is easy to do. What problems might
you have in terms of keeping track of cards that have been drawn already? Was this easier or harder than
the slow machine?
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


// *******************************************************************************
// pseudo random:
#include <cstdlib>
#include <ctime>



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


enum coinFace
{
    CF_TAILS = 0,
    CF_HEADS = 1
};

// prototypes
bool passwordAccepted(void);
coinFace flipCoin(void);
void flipManyCoins(int numTimes = 1);
void userGuess(void);
void computerGuess(void);
void slotMachine(void);
string slot(void);
void poker(void);  // OH NO ... HOW TEDIUS!!!!
string getFace(int card);
string getSuit(int card);
void displayHand(int card1, int card2, int card3, int card4, int card5);
int dealCard(int card1, int card2, int card3, int card4, int card5, int card6, int card7, int card8, int card9, int card10);
string analyseHand(int card1, int card2, int card3, int card4, int card5);
int getCardValue(int card);





int main()
{

    // pseudo-random stuff
    // void srand (int seed);        // srand #include <cstdlib>
    // srand( time( NULL) );         // time  #include <ctime>    time returns num seconds since Jan 1 1970

    // call just once, at the very start
    //srand( time( NULL ) );         // WITHOUT THIS, rand() will return same sequence every time (useful for debug)
                                     // rand() gives 0 to RAND_MAX (constant) (at least 32767)

                                     // but going to keep a record of the seed
    int srand_seed = time(NULL);
    // int srand_seed = XXXXXXX;     // some seed value for debug
    cout << "srand_seed = " << srand_seed << endl;
    srand(srand_seed);




    enum menuItems {
        DAVE_EXIT = 0,
        DAVE_COINFLIP = 1,
        DAVE_USERGUESS = 2,
        DAVE_COMPUTERGUESS = 3,
        DAVE_SLOT = 4,
        DAVE_POKER = 5
    };

    int numFlips = 0;  // for coin flips


    menuItems menuItem = DAVE_EXIT;
    int menuChoice = 0;

    if (!passwordAccepted())
    {
        MacroWaitReturn
    }


    do
    {
        cout << "Menu\n\n" << "1. flip coins\n" << "2. user guess number\n"
            << "3. computer guess number\n" << "4. slot machine\n" << "5. Poker\n" << "0. Exit\n" << endl;
        cout << "Please input number for your menu choice ..." << endl;

        cin >> menuChoice;
        menuItem = (menuItems)menuChoice; // assuming at this stage this is the way to do this


        switch (menuItem)
        {
        case DAVE_COINFLIP:
            cin.ignore();
            cout << "Please enter number of times to flip coin: " << endl;
            cin >> numFlips;
            flipManyCoins(numFlips);
            break;
        case DAVE_USERGUESS:
            userGuess();
            break;
        case DAVE_COMPUTERGUESS:
            computerGuess();
            break;
        case DAVE_SLOT:
            slotMachine();
            break;
        case DAVE_POKER:
            poker();
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

void poker()
{
    // cards 1 to 52
    // Assuming mapped to clubs, spades, diamonds and then hearts
    // Assuming A, 2, 3, 4, 5, 6, 7, 8, 9, 10 J, Q, K

    // if patient maybe use enums ?
    // Grrr ... I don't know anything about poker!!!

    // How to record dealt hands using what I've gone through in the book so far???? 
    // Manually done large sets of variables with bounds on number of "rounds"?

    // ok ... going to have to put some rules and bounds on this thing I don't even know

    // 10 cards max. to be dealt ... I can keep track of 10-cards
    // ... 5 in a hand
    // ... 5 in waiting

    int card1 = 0, card2 = 0, card3 = 0, card4 = 0, card5 = 0, card6 = 0, card7 = 0, card8 = 0, card9 = 0, card10 = 0;

    card1 = dealCard(card1, card2, card3, card4, card5, card6, card7, card8, card9, card10);
    card2 = dealCard(card1, card2, card3, card4, card5, card6, card7, card8, card9, card10);
    card3 = dealCard(card1, card2, card3, card4, card5, card6, card7, card8, card9, card10);
    card4 = dealCard(card1, card2, card3, card4, card5, card6, card7, card8, card9, card10);
    card5 = dealCard(card1, card2, card3, card4, card5, card6, card7, card8, card9, card10);
    card6 = dealCard(card1, card2, card3, card4, card5, card6, card7, card8, card9, card10);
    card7 = dealCard(card1, card2, card3, card4, card5, card6, card7, card8, card9, card10);
    card8 = dealCard(card1, card2, card3, card4, card5, card6, card7, card8, card9, card10);
    card9 = dealCard(card1, card2, card3, card4, card5, card6, card7, card8, card9, card10);
    card10 = dealCard(card1, card2, card3, card4, card5, card6, card7, card8, card9, card10);

    displayHand(card1, card2, card3, card4, card5);

    cin.ignore();
    
    int cardsLeft = true;
    int nextCard = card6;
    int countCards = 1;
    int userChoice = 0;
    while (cardsLeft)
    {
        switch (countCards)
        {
        case 1:
            nextCard = card6;
            break;
        case 2:
            nextCard = card7;
            break;
        case 3:
            nextCard = card8;
            break;
        case 4:
            nextCard = card9;
            break;
        case 5:
            nextCard = card10;
            cardsLeft = false;
            break;
        default:
            nextCard = card6;
            break;
        }

        cout << "Enter 1 to 5, or 0 to exit to main menu" << endl;
        cin >> userChoice;

        switch (userChoice)
        {
        case 0:
            cardsLeft = false;
            cout << "Exit to main menu ..." << endl;
            cout << endl;
            break;
        case 1:
            card1 = nextCard;
            displayHand(card1, card2, card3, card4, card5);
            break;
        case 2:
            card2 = nextCard;
            displayHand(card1, card2, card3, card4, card5);
            break;
        case 3:
            card3 = nextCard;
            displayHand(card1, card2, card3, card4, card5);
            break;
        case 4:
            card4 = nextCard;
            displayHand(card1, card2, card3, card4, card5);
            break;
        case 5:
            card5 = nextCard;
            displayHand(card1, card2, card3, card4, card5);
            break;
        default:
            break;
        }

        if ( !cardsLeft)
        {
            cout << "NO MORE CARDS ..." << endl;
            cout << endl;
        }

        countCards++;
    }

    cout << "Card analysis ... found: " << analyseHand(card1, card2, card3, card4, card5) << endl;
    cout << endl;

}

string getFace(int card)
{
    int basicCard = card % 13;
    basicCard++;

    switch (basicCard)
    {
    case 1:
        return "Ace";
        break;
    case 2:
        return "2";
        break;
    case 3:
        return "3";
        break;
    case 4:
        return "4";
        break;
    case 5:
        return "5";
        break;
    case 6:
        return "6";
        break;
    case 7:
        return "7";
        break;
    case 8:
        return "8";
        break;
    case 9:
        return "9";
        break;
    case 10:
        return "10";
        break;
    case 11:
        return "Jack";
        break;
    case 12:
        return "Queen";
        break;
    case 13:
        return "King";
        break;
    default:
        return "Joker";
        break;
    }
}

int getCardValue(int card)
{
    int basicCard = card % 13;
    basicCard++;

    return basicCard;
}

string getSuit(int card)
{
    if (card < 14)
    {
        return "clubs";
    }
    else if (card > 13 && card < 27)
    {
        return "spades";
    }
    else if (card > 26 && card < 40)
    {
        return "diamonds";
    }
    else
    {
        return "hearts";
    }
}

string analyseHand(int card1, int card2, int card3, int card4, int card5)
{

    // detect so far

    int cardspare = 0;
    bool straight = false;
    bool flush = false;
    string returnHand = "nothing";

    // bubble sort ish ok for 5 items, and stable ... suitable for looking for any straights
    // not using arrays etc. so bulky
    
    // loop 4 times ... fixed cost
    for (int i = 1; i<5; i++)
    {
        if (getCardValue(card1) > getCardValue(card2))
        {
            cardspare = card1;
            card1 = card2;
            card2 = cardspare;
        }
        if (getCardValue(card2) > getCardValue(card3))
        {
            cardspare = card2;
            card2 = card3;
            card3 = cardspare;
        }
        if (getCardValue(card3) > getCardValue(card4))
        {
            cardspare = card3;
            card3 = card4;
            card4 = cardspare;
        }
        if (getCardValue(card4) > getCardValue(card5))
        {
            cardspare = card4;
            card4 = card5;
            card5 = cardspare;
        }

    }

    // assuming ace low
    // after sort, card1 is lowest, card5 highest (potentially) 

    if (getCardValue(card5) == getCardValue(card4) + 1 &&
        getCardValue(card4) == getCardValue(card3) + 1 &&
        getCardValue(card3) == getCardValue(card2) + 1 &&
        getCardValue(card2) == getCardValue(card1) + 1)
    {
        straight = true;
    }

    if (getSuit(card1) == getSuit(card2) &&
        getSuit(card2) == getSuit(card3) &&
        getSuit(card3) == getSuit(card4) &&
        getSuit(card4) == getSuit(card5))
    {
        flush = true;
    }

    cout << "Your hand: looking for straights, flushes, and ToDo" << endl;
    cout << endl;

    cout << "\t" << getFace(card1) << "\tof " << getSuit(card1) << endl;
    cout << "\t" << getFace(card2) << "\tof " << getSuit(card2) << endl;
    cout << "\t" << getFace(card3) << "\tof " << getSuit(card3) << endl;
    cout << "\t" << getFace(card4) << "\tof " << getSuit(card4) << endl;
    cout << "\t" << getFace(card5) << "\tof " << getSuit(card5) << endl;

    cout << endl;
    cout << endl;


    // start with highest hand first

    if (straight) returnHand = "straight";
    if (flush) returnHand = "flush";
    if (straight && flush) returnHand = "straight-flush";

    // LOTS TO DO ... Full House, Three of a kind etc. etc. at least

    return returnHand;
}

void displayHand(int card1, int card2, int card3, int card4, int card5)
{
    cout << "Your hand:" << endl;
    cout << endl;

    cout << "\t" << getFace(card1) << "\tof " << getSuit(card1) << "\tPress 1 to replace with new card" << endl;
    cout << "\t" << getFace(card2) << "\tof " << getSuit(card2) << "\tPress 2 to replace with new card" << endl;
    cout << "\t" << getFace(card3) << "\tof " << getSuit(card3) << "\tPress 3 to replace with new card" << endl;
    cout << "\t" << getFace(card4) << "\tof " << getSuit(card4) << "\tPress 4 to replace with new card" << endl;
    cout << "\t" << getFace(card5) << "\tof " << getSuit(card5) << "\tPress 5 to replace with new card" << endl;

    cout << endl;
    cout << endl;
}

int dealCard(int card1, int card2, int card3, int card4, int card5, int card6, int card7, int card8, int card9, int card10)
{
    int proposedCard = rand() % 52; // between 0 and 51
    proposedCard++;                 // between 1 and 52

    // while only loops if proposedCard already dealt

    while (proposedCard == card1 ||
        proposedCard == card2 ||
        proposedCard == card3 ||
        proposedCard == card4 ||
        proposedCard == card5 ||
        proposedCard == card6 ||
        proposedCard == card7 ||
        proposedCard == card8 ||
        proposedCard == card9 ||
        proposedCard == card10)
    {
        if (proposedCard < 52)
        {
            proposedCard++;
        }
        else
        {
            proposedCard = rand() % 52;
            proposedCard++;
        }
    }

    return proposedCard;
}




void slotMachine(void)
{
    // randomly displays the results of a slot machine to a player
    // each slot wheel to heave 3 or more states

    //     ____________     ____________      ___________
    //     |    A     |     |     A     |     |     A    |
    //     |    B     |     |     B     |     |     B    |    win 10 points
    //     |    C     |     |     C     |     |     C    |   
    //     |    D     |     |     D     |     |     D    |    win 20 points
    //     |    E     |     |     E     |     |     E    |
    //     ------------     -------------     ------------


    string slot1 = slot();
    string slot2 = slot();
    string slot3 = slot();

    cout << "     ____________     ____________      ___________ " << endl;
    cout << "     |    " << slot1 << "     |     |     " << slot2 << "     |     |     " << slot3 << "    |" << endl;
    cout << "     ------------     -------------     ------------" << endl;

    if (slot1 == "B" && slot2 == "B" && slot3 == "B")
    {
        cout << endl;
        cout << "You WIN 10 points!!!" << endl;

    }
    else if (slot1 == "D" && slot2 == "D" && slot3 == "D")
    {
        cout << endl;
        cout << "You WIN 20 points!!!" << endl;
    }
}

string slot()
{
    int numEqv = rand() % 5;      // remainder 0 to 4
    numEqv++;                     // bump up to 1 to 5
    switch (numEqv)
    {
    case 1:
        return "A";
        break;
    case 2:
        return "B";
        break;
    case 3:
        return "C";
        break;
    case 4:
        return "D";
        break;
    case 5:
        return "E";
        break;
    default:
        return "F";
        break;
    }
}

void computerGuess(void)
{
    int numToGuess = rand() % 100; // remainder 0 to 99
    numToGuess++;                  // bump up to 1 to 100

    int computersGuess = 0;
    int computerHigherThan = 0;
    int computerLowerThan = 101;
    int numGuesses = 0;
    
    string wait = "";
    cin.ignore();

    while (computersGuess != numToGuess)
    {
        numGuesses++;

        cout << "Computer: please guess the number from 1 to 100" << endl;

        cout << "computerLowerThan = " << computerLowerThan << endl;
        cout << "computerHigherThan = " << computerHigherThan << endl;

        computersGuess = computerHigherThan + ((computerLowerThan - computerHigherThan) / 2);

        cout << "computersGuess = " << computerLowerThan << " - " << computerHigherThan 
             << " /2 and then add on " << computerHigherThan << " = " << computersGuess << endl;

        if (computersGuess < numToGuess)
        {
            cout << "Nope Computer.  " << computersGuess << " is too low." << endl;
            computerHigherThan = computersGuess;
        }
        else if (computersGuess > numToGuess)
        {
            cout << "Nope Computer.  " << computersGuess << " is too high." << endl;
            computerLowerThan = computersGuess;
        }
        else
        {
            cout << "Well done Computer!  " << computersGuess << "  You guessed right!" << endl;
            break;
        }

        cout << endl;
        cout << "User - kindly press a key for the computer to guess again ... " << endl;
        getline(cin, wait, '\n');

    }

    cout << "The computer took " << numGuesses << " guesses to guess the number." << endl;
    return;
}

void userGuess(void)
{
   
    int numToGuess = rand() % 100; // remainder 0 to 99
    numToGuess++;                  // bump up to 1 to 100

    int usersGuess = 0;
    
    cin.ignore();

    while (usersGuess != numToGuess)
    {
        cout << "Please guess the number from 1 to 100" << endl;

        cin >> usersGuess;

        if (usersGuess < numToGuess)
        {
            cout << "Nope. Too low." << endl;
        }
        else if (usersGuess > numToGuess)
        {
            cout << "Nope. Too high." << endl;
        }
        else
        {
            cout << "Well done!  You guessed right!" << endl;
        }
    }

    return;
}



void flipManyCoins(int numTimes)
{
    int countFlips = 0;
    int countHeads = 0;
    int countTails = 0;

    while (countFlips < numTimes)
    {
        if (flipCoin() == CF_HEADS)
        {
            countHeads++;
        }
        else
        {
            countTails++;
        }
        
        countFlips++;
    }

    cout << "Flipped coin: " << numTimes << " ... times." << endl;
    cout << "Number of Heads: " << countHeads << endl;
    cout << "Number of Tails: " << countTails << endl;
}



coinFace flipCoin(void)
{
    // spell it out
    int HeadsOrTails = 0;       // 0 = tails, 1 = heads
    HeadsOrTails = rand() % 2;  // rand() between 0 and RAND_MAX, divide by 2 ... and then remainder 0 or 1

    if (HeadsOrTails)
    {
        return CF_HEADS;
    }
    else
    {
        return CF_TAILS;
    }
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
