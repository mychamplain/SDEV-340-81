/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 10: Assignment (second semester) - Starting out with C++ Early Objects (9 Edition) (2020/07/19)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Exceptions, Templates, and the Standard Template Library (STL)
 * Exceptions - Chapter 16 (Page 1034)
 * Programming Challenge (2. Arithmetic Exceptions)
 * A Function that throw an exception when a integer that is passed in not perfect square
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Written by Llewellyn van der Merwe <llewellyn.vandermerw@mymail.champlain.edu>, July 2020
 * Copyright (C) 2020. All Rights Reserved
 * License GNU/GPL Version 2 or later - http://www.gnu.org/licenses/gpl-2.0.html
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <cmath>

using namespace std;

// To check if a number is perfect square without finding square root
// Taken from
// https://www.geeksforgeeks.org/check-if-a-number-is-perfect-square-without-finding-square-root/
bool isPerfectSquare(int n) {
    for (int i = 1; i * i <= n; i++) {
        // If (i * i = n)
        if ((n % i == 0) && (n / i == i)) {
            return true;
        }
    }
    return false;
}

// Get the square root of a number
int getSquareRoot(int n) {
    // only if it is perfect
    if (isPerfectSquare(n)) {
        // return square root
        return sqrt(n);
    }
    throw " is not a perfect square";
}

int main() {
    // instantiate the numbers
    int n, r;
    // get a number from the user
    cout << " To get the square root" << endl;
    cout << " **********************" << endl;
    cout << " Enter a number: ";
    cin >> n;
    // try this out
    try {
        // get the square root
        r = getSquareRoot(n);
        // print out the square root
        cout << " Square root of " << n << " is " << r << endl;
    }
    // check if we have a catch
    catch (char const* &m) {
        // a very basic error message
        cout << " " << n << m << endl;
    }

    return 0;
}
