/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 5: Assignment (second semester) - Recursion  (2020/06/15)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Working with recursion
 * Recursion - Chapter 14 (Page 946)
 * Programming Challenge (5. Recursive Multiplication) Multiply numbers recursively using addition
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

int multiplyRecursive(int x, int y);

int main() {
    // the number
    int x = 2320, y = 1034;
    // print result
    cout << x << " x " << y << " = ";
    // calculate
    cout << multiplyRecursive(x, y) << endl;
}

// multiply numbers recursively
int multiplyRecursive(int x, int y) {
    if (y == 1) {
        return x;
    } else {
        return x + multiplyRecursive(x , y - 1);
    }
}