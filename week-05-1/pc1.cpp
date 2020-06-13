/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 5: Assignment (second semester) - Recursion  (2020/06/15)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Working with recursion
 * Recursion - Chapter 14 (Page 946)
 * Programming Challenge (1. Iterative Factorial) Using a loop instead of recursion print factorial
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Written by Llewellyn van der Merwe <llewellyn.vandermerw@mymail.champlain.edu>, June 2020
 * Copyright (C) 2020. All Rights Reserved
 * License GNU/GPL Version 2 or later - http://www.gnu.org/licenses/gpl-2.0.html
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>

using namespace std;

int main() {
    // the input number
    int number;
    // the result (and starting number)
    int result = 1;
    // get the number from user
    cout << " Get the factorial of numbers between 1 and 31" << endl;
    while (true) {
        cout << " Enter a number: ";
        cin >> number;
        if (number < 32 && number > 0) {
            break;
        } else {
            cout << " The Program can only work with numbers between 1 and 31, please try again." << endl;
        }
    }
    // start printing answer now, since we have the input number
    cout << " " << number << "! ";
    while (true) {
        if (number == 0) {
            break;
        } else {
            result = number * result;
        }
        number--;
    }
    // we print the factorial result
    cout << "= " << result << endl;
}
