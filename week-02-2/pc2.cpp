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

// libraries
#include <iostream>
#include <map>
#include <string>

using namespace std;

// VDM as my own space
namespace vdm {
    // class to convert day of year to date
    class DayToDate {
    private:
        // Year Day number
        int day;
        // special identifying keys
        const array<int, 12> keys{ 31,
                                   59,
                                   90,
                                   120,
                                   151,
                                   181,
                                   212,
                                   243,
                                   273,
                                   304,
                                   334,
                                   365 };
        // months of the year
        const array<string, 12> months{ "January",
                                        "February",
                                        "March",
                                        "April",
                                        "May",
                                        "June",
                                        "July",
                                        "August",
                                        "September",
                                        "October",
                                        "November",
                                        "December" };
        // ordinal ends
        array<string, 10> ends{"th",
                               "st",
                               "nd",
                               "rd",
                               "th",
                               "th",
                               "th",
                               "th",
                               "th",
                               "th"};
        // the actual date string
        string dateString;
        // Methods
        string getOrdinal(int day);
        void initialize();
        void setMonth();
        void setDay();
        int getKey();

    public:
        // Constructor - default
        DayToDate(int day);
        // Print Method
        string print() const;
        // operator << overload
        friend ostream& operator<<(ostream&, const DayToDate&);
    };
}

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

// constructor that takes an int
DayToDate::DayToDate(int day) : day(day) {
    // do a sanity check here
    if (day <= 365 && day >= 1) {
        // initialize class once we have int set
        DayToDate::initialize();
    } else {
        // set the warning (this should never happen, but if someone mess-up)
        cout << "Only days between 1 and 365 are allowed!";
    }
};

// initialize the dateString
void DayToDate::initialize() {
    // initialize the month
    DayToDate::setMonth();
    // initialize the day
    DayToDate::setDay();
    // little bit of fun :)
    if (123 == DayToDate::day) {
        DayToDate::dateString += " (My wife's birthday!)";
    } else if (159 == DayToDate::day) {
        DayToDate::dateString += " (My birthday!)";
    }
};

// get the key
int DayToDate::getKey() {
    // loop over the 12 months (keys)
    for (int key = 0; key < 12; key++) {
        // if the day is less or equal
        if (DayToDate::day <= DayToDate::keys[key]) {
            return key;
        }
    }
    return 0;
};

// set the day's ordinal suffix
// https://en.wikipedia.org/wiki/English_numerals#Ordinal_numbers
string DayToDate::getOrdinal(int day) {
    if (((day % 100) >= 11) && ((day % 100) <= 13)) {
        return to_string(day) + "th";
    } else {
        return to_string(day) + DayToDate::ends[day % 10];
    }
}

// set the day
void DayToDate::setDay() {
    // get the day
    DayToDate::dateString += " " + DayToDate::getOrdinal(
            DayToDate::day <= 31 ? DayToDate::day : DayToDate::day - DayToDate::keys[DayToDate::getKey() - 1]);
}

// set the month
void DayToDate::setMonth() {
    // get the month
    DayToDate::dateString = DayToDate::months[DayToDate::getKey()];
};

// return the converted number string
string DayToDate::print() const {
    return DayToDate::dateString;
};

// Enable class to have toString ability
// https://stackoverflow.com/a/1549937/1429677
ostream &vdm::operator<<(ostream &outputStream, const DayToDate &dayTD) {
    return outputStream << dayTD.print() << endl;
}

// The class header and function declarations where in there own files,
// but the assignment said: Save the source code in a file named pc2.
// I am wondering if I could instead use gitHub?
