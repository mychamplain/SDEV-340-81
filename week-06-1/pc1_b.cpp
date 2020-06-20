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
#include <vector>
#include <sstream>

using namespace std;

int sumRecursive(int n, int array[]);

int main() {
    // string to get user input
    string user_input;
    // now ask for the integers
    cout << "Enter space separated list of integers you would like to sum:" << endl;
    // get the user input of integer
    getline(cin, user_input);
    // convert to string stream
    stringstream user_input_stream(user_input);
    // the vector array of integers
    vector<int>array;
    int number;
    while(user_input_stream >> number){
        // add the number
        array.push_back(number);
        // skip empty space
        if(user_input_stream.peek() == ' ') user_input_stream.ignore();
    }
    // get size
    int SIZE = array.size();
    // start array of int
    int arr[SIZE];
    // little counter for +
    number = 0;
    // print out the numbers entered and build array
    for(int val : array) {
        // add to array
        arr[number] = val;
        // increment the number
        number++;
        // print out the value
        cout << val;
        // just add for the first numbers
        if(number < SIZE)  {
            cout << " + ";
        }
    }
    // give back answer
    cout << " = " << sumRecursive(SIZE, arr) << endl;
}

// multiply numbers recursively
int sumRecursive(int n, int array[]) {
    // lower to previous index
    --n;
    // get current value
    int number = array[n];
    // are we at the first element
    if (n == 0) {
        // return first "last" number
        return number;
    } else {
        // recursive call
        return number + sumRecursive(n , array);
    }
}
