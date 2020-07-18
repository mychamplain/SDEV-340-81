/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 10: Assignment (second semester) - Starting out with C++ Early Objects (9 Edition) (2020/07/19)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Exceptions, Templates, and the Standard Template Library (STL)
 * Templates - Chapter 16 (Page 1034)
 * Programming Challenge (3. Min/Max Templates)
 * Templates that returns the min and max of two arguments
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Written by Llewellyn van der Merwe <llewellyn.vandermerw@mymail.champlain.edu>, July 2020
 * Copyright (C) 2020. All Rights Reserved
 * License GNU/GPL Version 2 or later - http://www.gnu.org/licenses/gpl-2.0.html
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <string>

using namespace std;

// compare values
template<typename T>
bool comp(const T &a, const T &b) {
    return (a < b);
}

// compare string length
template<>
bool comp<string>(const string &a, const string &b) {
    return (a.length() < b.length());
}

// Get the Largest entity
// http://www.cplusplus.com/reference/algorithm/max/
template<typename T>
const T &Max(const T &a, const T &b) {
    return comp<T>(a, b) ? b : a;
}

// Get the Smallest entity
// http://www.cplusplus.com/reference/algorithm/min/
template<typename T>
const T &Min(const T &a, const T &b) {
    return comp<T>(a, b) ? a : b;
}

int main() {

    // The Test Values
    int i[] = {7, 5};
    float f[] = {3.1f, 3.2f};
    double d[] = {3.64, 3.232};
    string s[] = {"My Longer Name", "My short Name"};

    // Demonstrate the Max & Min template
    cout << "Between (" << *i << ") and (" << *(i + 1) << ") MAX=" << Max<int>(*i, *(i + 1))
         << " MIN=" << Min<int>(*(i + 0), *(i + 1)) << endl;
    cout << "Between (" << *f << ") and (" << *(f + 1) << ") MAX=" << Max<float>(*f, *(f + 1))
         << " MIN=" << Min<float>(*(f + 0), *(f + 1)) << endl;
    cout << "Between (" << *d << ") and (" << *(d + 1) << ") MAX=" << Max<double>(*d, *(d + 1))
         << " MIN=" << Min<double>(*(d + 0), *(d + 1))<< endl;
    cout << "Between (" << *s << ") and (" << *(s + 1) << ") MAX=" << Max<string>(*s, *(s + 1))
         << " MIN=" << Min<string>(*s, *(s + 1)) << endl;

    return 0;
}
