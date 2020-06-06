/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 4: Assignment (second semester) - Advance File and I/O Operations  (2020/06/07)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Working with File and I/O Operations
 * Advance File and I/O Operations - Chapter 13 (Page 911)
 * Programming Challenge (1. File Previewer) Display the first 10 lines of a file on the screen
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Written by Llewellyn van der Merwe <llewellyn.vandermerw@mymail.champlain.edu>, June 2020
 * Copyright (C) 2020. All Rights Reserved
 * License GNU/GPL Version 2 or later - http://www.gnu.org/licenses/gpl-2.0.html
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // file path
    string file_path;
    // get the file path
    cout << " Enter the file path to your file: ";
    while (true) {
        cin >> file_path;
        // get the file
        fstream file(file_path.c_str(), ios::in);
        // check if the file is open
        if (file.is_open()) {
            // the input string
            string line;
            // little counter
            int counter = 1;
            // get the fist line
            getline(file , line);
            while (file && counter < 11)
            {
                // we print the line number and the line
                cout << " " << setfill('0') << setw(2) <<  counter << "| " << line << endl;
                // get the next line
                getline(file , line);
                // count the lines
                counter++;
            }
            // check if we are at the end of the file
            if (!file)
            {
                // print this ending line notice that the whole file was displayed
                cout << "------------------------------------------------" << endl;
                cout << " The entire file was displayed above" << endl;
                cout << "------------------------------------------------" << endl;
            }
            // close the file
            file.close();
            break;
        } else {
            cout << endl;
            cout << " Woops! The file path (" << file_path << ") does not exist!" << endl;
            cout << " Please enter the correct file path to your file: ";
        }
    }
    return 0;
}
