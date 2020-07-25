/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 11: Assignment (second semester) - Starting out with C++ Early Objects (9 Edition) (2020/07/26)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Exceptions, Templates, and the Standard Template Library (STL)
 * Exceptions - Chapter 16 (Page 1034)
 * Programming Challenge (4. Sequence Accumulation)
 * A Function that sum any type values and concatenate strings
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Written by Llewellyn van der Merwe <llewellyn.vandermerw@mymail.champlain.edu>, July 2020
 * Copyright (C) 2020. All Rights Reserved
 * License GNU/GPL Version 2 or later - http://www.gnu.org/licenses/gpl-2.0.html
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include<limits>
#include <vector>

using namespace std;

// Quick accum template
template <typename T>
T accum (vector <T> &values){
    T bucket = T();
    for (int i = 0; i < values.size(); ++i) {
        bucket+=values.at(i);
    }
    return bucket;
}

int main() {
    // space notice
    cout << "Separate your numbers with a space" << endl;
    // the integers vectors
    vector<int> number(2);
    while(true) {
        cout << "Enter two integers: ";
        cin >> number[0] >> number[1];
        if (!cin.fail())
            break;
        // reset cin
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // print result
    cout << "   " << number.at(0) << "+" << number.at(1) << "= " << accum(number) << endl;
    // space notice
    cout << "Separate your strings with a space" << endl;
    // the string vectors
    vector<string> data(3);
    while(true) {
        cout << "Enter three strings: ";
        cin >> data[0] >> data[1] >> data[2];
        if (!cin.fail())
            break;
        // reset cin
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // print result
    // print result
    cout << "   " << data.at(0) << "+" << data.at(1) << "+" << data.at(2) << "= " << accum(data) << endl;
}
