/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 2: Assignment (second semester) - Application of OOP  (2020/05/24)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * This is a demonstration of OOP in C++
 * More about Classes and Object-Oriented Programming - Chapter 11 (Page 810)
 * Programming Challenge (1. Check Writing)  Converting numbers to English (en-GB) description of the number.
 * (Full Disclosure) I've Been converting numbers to strings in PHP since 2016
 * https://github.com/vdm-io/Joomla-Component-Builder/blob/master/admin/helpers/componentbuilder.php#L7409
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Written by Llewellyn van der Merwe <llewellyn.vandermerw@mymail.champlain.edu>, May 2020
 * Copyright (C) 2020. All Rights Reserved
 * License GNU/GPL Version 2 or later - http://www.gnu.org/licenses/gpl-2.0.html
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// internal classes
#include "Numbers.h"
// libraries
#include <iostream>
#include <cmath>
#include <string>

using namespace std;
using namespace vdm;

// constructor that takes an int
Numbers::Numbers(int number) : number(number) {
    // do a sanity check here
    if (number < 1000000000 && number > -1000000000) {
        // initialize class once we have int set
        Numbers::initialize();
    } else {
        // set the warning (this should never happen, but if someone mess-up)
        cout << "Only numbers below 1000000000 and above -1000000000";
    }
};

// constructor for no-input
Numbers::Numbers() : number(0) {
    // initialize class once we have int set
    Numbers::initialize();
};

// constructor that takes a double
Numbers::Numbers(double number) {
    // just do a simple cast to int (basic)
    Numbers::number = (int) number;
    // do a sanity check here
    if (number < 1000000000 && number > -1000000000) {
        // initialize class once we have int set
        Numbers::initialize();
    } else {
        // set the warning (this should never happen, but if someone mess-up)
        cout << "Only numbers below 1000000000 and above -1000000000";
    }
};

// constructor with error when string is given
Numbers::Numbers(string number) {
    // set the warning (this should never happen, but if someone mess-up)
    cout << "Only numbers below 1000000000 and above -1000000000";
};

// initialize multiple methods for the constructor
void Numbers::initialize() {
    // initialize the number words
    Numbers::initializeNumberWords();
    // now convert to string
    Numbers::toString();
};

// return the converted number string
string Numbers::print() const {
    return Numbers::numberString;
};

// initialize the number words
void Numbers::initializeNumberWords() {
    Numbers::words[0] = "zero";
    Numbers::words[1] = "one";
    Numbers::words[2] = "two";
    Numbers::words[3] = "three";
    Numbers::words[4] = "four";
    Numbers::words[5] = "five";
    Numbers::words[6] = "six";
    Numbers::words[7] = "seven";
    Numbers::words[8] = "eight";
    Numbers::words[9] = "nine";
    Numbers::words[10] = "ten";
    Numbers::words[11] = "eleven";
    Numbers::words[12] = "twelve";
    Numbers::words[13] = "thirteen";
    Numbers::words[14] = "fourteen";
    Numbers::words[15] = "fifteen";
    Numbers::words[16] = "sixteen";
    Numbers::words[17] = "seventeen";
    Numbers::words[18] = "eighteen";
    Numbers::words[19] = "nineteen";
    Numbers::words[20] = "twenty";
    Numbers::words[30] = "thirty";
    Numbers::words[40] = "forty";
    Numbers::words[50] = "fifty";
    Numbers::words[60] = "sixty";
    Numbers::words[70] = "seventy";
    Numbers::words[80] = "eighty";
    Numbers::words[90] = "ninety";
};

// Thanks to Tom Nicholson <http://php.net/manual/en/function.strval.php#41988>
// Adapted to C++ by Llewellyn van der Merwe
// This method converts numbers to strings
void Numbers::toString() {
    // always rest string
    Numbers::numberString = "";
    // deal with minus numbers
    if (Numbers::number< 0) {
        Numbers::numberString = "minus ";
        Numbers::number = -Numbers::number;
    }
    // 0 to 20
    if (Numbers::number< 21) {
        Numbers::numberString += Numbers::words[Numbers::number];
    }
    // 21 to 99
    else if (Numbers::number< 100) {
        Numbers::numberString += Numbers::words[10 * floor(Numbers::number / 10)];
        int r = fmod(Numbers::number, 10);
        if (r > 0) {
            Numbers::numberString += " " + Numbers::words[r];
        }
    }
    // 100 to 999
    else if (Numbers::number< 1000) {
        Numbers::numberString += Numbers::words[floor(Numbers::number / 100)] + " hundred";
        int r = fmod(Numbers::number, 100);
        if (r > 0) {
            Numbers::numberString += " and " + Numbers::toString(r); // en-GB
        }
    }
    // 1000 to 999999
    else if (Numbers::number< 1000000) {
        Numbers::numberString += Numbers::toString(floor(Numbers::number / 1000)) + " thousand";
        int r = fmod(Numbers::number, 1000);
        if (r > 0) {
            Numbers::numberString += " ";
            if (r < 100) {
                Numbers::numberString += "and "; // en-GB
            }
            Numbers::numberString += Numbers::toString(r);
        }
    }
    // millions
    else {
        Numbers::numberString += Numbers::toString(floor(Numbers::number / 1000000)) + " million";
        int r = fmod(Numbers::number, 1000000);
        if (r > 0) {
            Numbers::numberString += " ";
            if (r < 100) {
                Numbers::numberString += "and "; // en-GB
            }
            Numbers::numberString += Numbers::toString(r);
        }
    }
    // I haven't bothered with "billion" because the word means 10e9 or 10e12 depending who you ask.

    // a little bit of fun
    if (666 == Numbers::number) {
        Numbers::numberString += " (The mark of the beast)";
    } else if (2020 == Numbers::number) {
        Numbers::numberString += " (The year of COVID-19)";
    }
};

// Thanks to Tom Nicholson <http://php.net/manual/en/function.strval.php#41988>
// Adapted to C++ by Llewellyn van der Merwe
// This method converts numbers to strings
string Numbers::toString(int number) {
    // local string
    string numberString;
    // 0 to 20
    if (number < 21) {
        numberString += Numbers::words[number];
    }
    // 21 to 99
    else if (number < 100) {
        numberString += Numbers::words[10 * floor(number / 10)];
        int r = fmod(number, 10);
        if (r > 0) {
            numberString += " " + Numbers::words[r];
        }
    }
    // 100 to 999
    else if (number < 1000) {
        numberString += Numbers::words[floor(number / 100)] + " hundred";
        int r = fmod(number, 100);
        if (r > 0) {
            numberString += " and " + Numbers::toString(r); // en-GB
        }
    }
    // 1000 to 999999
    else if (number < 1000000) {
        numberString += Numbers::toString(floor(number / 1000)) + " thousand";
        int r = fmod(number, 1000);
        if (r > 0) {
            numberString += " ";
            if (r < 100) {
                numberString += "and "; // en-GB
            }
            numberString += Numbers::toString(r);
        }
    }
    //  millions
    else {
        numberString += Numbers::toString(floor(number / 1000000)) + " million";
        int r = fmod(number, 1000000);
        if (r > 0) {
            numberString += " ";
            if (r < 100) {
                numberString += "and "; // en-GB
            }
            numberString += Numbers::toString(r);
        }
    }
    // I haven't bothered with "billion" because the word means 10e9 or 10e12 depending who you ask.
    return numberString;
};

// Enable class to have toString ability
// https://stackoverflow.com/a/1549937/1429677
ostream &vdm::operator<<(ostream &outputStream, const Numbers &num) {
    return outputStream << num.print() << endl;
};
