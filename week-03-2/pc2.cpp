/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 3: Assignment (second semester) - Characters, Strings and the String Class  (2020/06/01)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Working with C-type strings
 * More about C strings and the string Class - Chapter 12 (Page 849)
 * Programming Challenge (5. Name Arranger) Print out last, first, and middle name
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Written by Llewellyn van der Merwe <llewellyn.vandermerw@mymail.champlain.edu>, June 2020
 * Copyright (C) 2020. All Rights Reserved
 * License GNU/GPL Version 2 or later - http://www.gnu.org/licenses/gpl-2.0.html
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;

// Function prototypes
void getString(char *cString, string question);

int main() {

    // character array for first, middle, and last names
    char first[50];
    char middle[50];
    char last[50];
    // full name character array
    char full[157] = "";

    // questions
    getString(first, "Enter your first name");
    getString(middle, "Enter your middle name");
    getString(last, "Enter your last name");
    // I was not sure if it should have been one question,
    // if so I would have used something like the function
    // found on page 835 and 836 to split the string up

    // build the full name
    strcat(full, last);
    strcat(full, ", ");
    strcat(full, first);
    strcat(full, " ");
    strcat(full, middle);

    // print out result
    cout << endl;
    cout << " Your full name is: " << full << endl;

    return 0;
}

// get the string from the user
void getString(char *cString, string question){
    while (true) {
        cout << " " << question << ": ";
        cin.getline(cString, 50);
        // reset cin
        cin.clear();
        // make sure we have an alphabetic first character
        if (isalpha(*cString)) {
            break;
        } else {
            cout << " Your string must start with an alphabetic character!" << endl;
        }
    }
    // reset cin
    cin.clear();
}
