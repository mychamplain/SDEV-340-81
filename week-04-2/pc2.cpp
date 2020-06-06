/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 4: Assignment (second semester) - Advance File and I/O Operations  (2020/06/07)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Working with File and I/O Operations
 * Advance File and I/O Operations - Chapter 13 (Page 911)
 * Programming Challenge (3. Punch Line) Display joke and punch line from two different files
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Written by Llewellyn van der Merwe <llewellyn.vandermerw@mymail.champlain.edu>, June 2020
 * Copyright (C) 2020. All Rights Reserved
 * License GNU/GPL Version 2 or later - http://www.gnu.org/licenses/gpl-2.0.html
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <fstream>
#include <limits>
#include <string>

using namespace std;

// Function prototype
void printLastLine(fstream& file);
void printAllLines(fstream& file);

// Adaptation of Wake (Aug 21, 2013 at 5:35pm)
// http://www.cplusplus.com/forum/general/108679/#msg593184
istream& ignoreline(fstream& in, fstream::pos_type& pos);
string getLastLine(fstream& in);

int main()
{
    // get the file
    fstream file_joke("../joke.txt", ios::in);
    // check if the file is open
    if (file_joke.is_open()) {
        // print out the file content
        printAllLines(file_joke);
        // now close the file
        file_joke.close();
    } else {
        cout << " Error opening the joke file!" << endl;
    }

    // get the file
    fstream file_punch("../punchline.txt", ios::in);
    // check if the file is open
    if (file_punch.is_open()) {
        // print out the file content
        printLastLine(file_punch);
        // now close the file
        file_punch.close();
    } else {
        cout << " Error opening the punch line file!" << endl;
    }

    return 0;
}

// get all content from file and print it out
void printAllLines(fstream& file) {
    // print out the complete file
    cout << file.rdbuf() << endl;
}

// get the last line and print it out
void printLastLine(fstream& file) {
    // print out the last line
    cout << getLastLine(file) << endl;
}

// Adaptation of Wake (Aug 21, 2013 at 5:35pm)
// http://www.cplusplus.com/forum/general/108679/#msg593184
istream& ignoreline(fstream& in, fstream::pos_type& pos) {
    // update current position of the file pointer
    pos = in.tellg();
    return in.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Adaptation of Wake (Aug 21, 2013 at 5:35pm)
// http://www.cplusplus.com/forum/general/108679/#msg593184
string getLastLine(fstream& in) {
    // set the current position of the file pointer
    fstream::pos_type pos = in.tellg();

    // set the seeking pointer
    fstream::pos_type lastPos;
    while (in >> ws && ignoreline(in, lastPos))
        // set the new position
        pos = lastPos;

    // reset the file pointer
    in.clear();
    // move the pointer to the found position
    in.seekg(pos);
    // setup the string
    string line;
    // now finally get the last line
    getline(in, line);
    // return the last will
    return line;
}
