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

using namespace std;
using namespace vdm;

int main() {
    int number;
    string answer;
    while (true) {
        // we first get the number to convert
        cout << endl;
        cout << "Please enter a number you would like to convert to a string: ";
        cin >> number;
        cout << endl;
        // check if we have a reasonable number
        if (!cin.fail() && number < 1000000000 && number > -1000000000) { // below is the assignment's expected limits
        // if (!cin.fail() && number <= 9999 && number >= 0) {
            // instantiate the class with the number
            Numbers NumString(number);
            // print out the English (en-GB) description of the number
            // cout << NumString << endl; // the better way :)
            cout << NumString.print() << endl;
            cout << endl;
            cout << "Convert another [y/n]: ";
            cin >> answer;
            // check answer
            if (answer != "y" && answer != "Y") {
                break;
            }
        } else {
            // clear the cin
            cin.clear();
            cin.ignore();
            // give warning message
            cout << endl;
            cout << "Only numbers below 1000000000 and above -1000000000"; // below is the assignment's expected limits
            // cout << "Only numbers between 9999 and 0";
        }
    }
    return 0;
}
