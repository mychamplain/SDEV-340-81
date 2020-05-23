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

#ifndef INC_2_WEEK2_2_DAYTODATE_H
#define INC_2_WEEK2_2_DAYTODATE_H

// libraries
#include <iostream>
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


#endif //INC_2_WEEK2_2_DAYTODATE_H
