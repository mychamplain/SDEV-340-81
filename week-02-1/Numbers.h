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

#ifndef INC_2_WEEK2_1_NUMBERS_H
#define INC_2_WEEK2_1_NUMBERS_H

// libraries
#include <iostream>
#include <map>
#include <string>

using namespace std;

// VDM as my own space
namespace vdm {
    // class to convert numbers to string
    class Numbers {
    private:
        // Members
        int number;
        map<int, string> words;
        string numberString;
        // Methods
        void initialize();
        void initializeNumberWords();
        void toString();
        string toString(int number);

    public:
        // Constructor - default
        Numbers(int number);
        // Constructor - number is zero if none is given (not needed really)
        Numbers();
        // Constructor - when number is double (not needed really)
        Numbers(double number);
        // Constructor - error when string (not needed really)
        Numbers(string number);

        // Print Method
        string print() const;
        // operator << overload
        friend ostream& operator<<(ostream&, const Numbers&);
    };
}


#endif //INC_2_WEEK2_1_NUMBERS_H
