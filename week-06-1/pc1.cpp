/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 5: Assignment (second semester) - Recursion Continued (2020/06/20)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Working with recursion
 * Recursion - Chapter 14 (Page 947)
 * Programming Challenge (4. Recursive Array Sum) Sum numbers recursively
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Written by Llewellyn van der Merwe <llewellyn.vandermerw@mymail.champlain.edu>, June 2020
 * Copyright (C) 2020. All Rights Reserved
 * License GNU/GPL Version 2 or later - http://www.gnu.org/licenses/gpl-2.0.html
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <limits>

using namespace std;

int sumRecursive(int n, int array[]);

int main() {
    // set size of input array (large to get all user input)
    int const SIZE = 100;
    // the user input array
    int user_input_array[SIZE];
    // user input length
    int n = 0;
    // now ask for the integers
    cout << "Enter one integer at a time that you would like to sum, and d when done." << endl;
    // get the user input of integers
    for (int & i : user_input_array)
    {
        if (cin >> i){
            n++;
        } else {
            // just reset cin properly
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    // print out the numbers entered
    for (int i = 0; i < n; i++){
        // print out the value
        cout << user_input_array[i];
        // just add for the first numbers
        if(i + 1 < n)  {
            cout << " + ";
        }
    }
    // give back answer
    cout << " = " << sumRecursive(n, user_input_array) << endl;

    return 0;
}

// multiply numbers recursively
int sumRecursive(int n, int array[]) {
    // lower to previous index
    --n;
    // are we at the first element
    if (n == 0) {
        // return first "last" number
        return array[n];
    } else {
        // recursive call
        return array[n] + sumRecursive(n , array);
    }
}
