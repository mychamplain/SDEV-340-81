/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 2: Assignment (second semester) - Application of OOP  (2020/05/24)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * This is a demonstration of OOP in C++
 * More about Classes and Object-Oriented Programming - Chapter 11 (Page 810)
 * Programming Challenge (2. Day of the Year) Converting the day of the year to a date
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Written by Llewellyn van der Merwe <llewellyn.vandermerw@mymail.champlain.edu>, May 2020
 * Copyright (C) 2020. All Rights Reserved
 * License GNU/GPL Version 2 or later - http://www.gnu.org/licenses/gpl-2.0.html
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// internal classes
#include "DayToDate.h"
// libraries
#include <iostream>

using namespace std;
using namespace vdm;

int main() {
    int day;
    string answer;
    while (true) {
        // we first get the day of the year
        cout << endl;
        cout << "Check the date of a day in the year between 1 and 365: ";
        cin >> day;
        cout << endl;
        // check if we have a reasonable number
        if (!cin.fail() && day <= 365 && day >= 1) {
            // instantiate the class with the number
            DayToDate printDate(day);
            // print out the date of the given day
            cout << printDate << endl;
            cout << endl;
            // check if user wants to check another
            cout << "Check another [y/n]: ";
            cin >> answer;
            // check answers
            if (answer != "y" && answer != "Y") {
                break;
            }
        } else {
            // clear the cin
            cin.clear(); cin.ignore();
            // give warning message
            cout << endl;
            cout << "Only days between 1 and 365 are allowed!";
        }
    }
    return 0;
}
