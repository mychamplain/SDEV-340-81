/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 3: Assignment (second semester) - Characters, Strings and the String Class  (2020/06/01)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Working with C-type strings
 * More about C strings and the string Class - Chapter 12 (Page 848)
 * Programming Challenge (4. Vowels and Consonants) Counting the Vowels and Consonants in a C string
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
void options();
void getString(char *cString);
void getOption(char *option);
void counter(char *cString, int &vowels, int &consonants, int &numbers);
int isAvailableOption(char *option);

// vowels
char a_[2] = "a";
char e_[2] = "e";
char i_[2] = "i";
char o_[2] = "o";
char u_[2] = "u";

// options
char option_a[2] = "a";
char option_b[2] = "b";
char option_c[2] = "c";
char option_d[2] = "d";
char option_e[2] = "e";

// main function
int main ()
{
    // starting option
    char option[2];
    // run the program loop
    while (true) {
        // string
        char cString[100];
        // counters
        int vowels = 0;
        int consonants = 0;
        int numbers = 0;
        // get the string
        getString(cString);
        // show the string selected
        cout << " Your string is: " << cString << endl;
        // get the action option
        getOption(option);
        // check the option
        if (strcmp(option, option_e) != 0) {
            // count the string values
            counter(cString, vowels, consonants, numbers);
            while (true) {
                cout << endl;
                // print out the number of vowels
                if (strcmp(option, option_a) == 0 || strcmp(option, option_c) == 0) {
                    cout << " Number of vowels: " << vowels << endl;
                }
                // print out the number of constants
                if (strcmp(option, option_b) == 0 || strcmp(option, option_c) == 0) {
                    cout << " Number of consonants: " << consonants << endl;
                }
                // print out the number of numbers
                if (strcmp(option, option_c) == 0) {
                    cout << " Number of numbers: " << numbers << endl;
                }
                cout << endl;
                cout << " Your string is: " << cString << endl;
                // get the action option
                getOption(option);
                // get a new string or end
                if (strcmp(option, option_d) == 0 || strcmp(option, option_e) == 0) {
                    break;
                }
            }
            cout << endl;
        }
        // if we have (e) we end the program
        if (strcmp(option, option_e) == 0) {
            break;
        }
    }

    return 0;

}

// get the string from the user
void getString(char *cString){
    while (true) {
        cout << " Please enter a string: ";
        cin.getline(cString, 100);
        cout << endl;
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

// get the action option from the user
void getOption(char *option){
    while (true) {
        // show the options
        options();
        // get the option
        cin.getline(option, 2);
        // reset cin
        cin.clear();
        // make sure we have an alphabetic first character
        if (isAvailableOption(option)) {
            break;
        } else {
            cout << " Please make a valid selection!" << endl;
        }
    }
    // reset cin
    cin.clear();
    // cout << " Option: " << option << endl; // debug
}

// check if the option selected is available (allows if starts with correct
int isAvailableOption(char *option){
    // convert to lower case
    option[0] = tolower(*option);
    // now validate
    return strcmp(option, option_a) == 0 || strcmp(option, option_b) == 0 || strcmp(option, option_c) == 0
           || strcmp(option, option_d) == 0 || strcmp(option, option_e) == 0;
}

// a function to print out the options
void options(){
    cout << endl;
    cout << " What should we do with this string?" << endl;
    cout << " a) Count the number of vowels in the string." << endl;
    cout << " b) Count the number of consonants in the string." << endl;
    cout << " c) Count the vowels, constants and numbers in the string." << endl;
    // cout << " c) Count both the vowels and consonants in the string." << endl;  // improved
    cout << " d) Enter another string." << endl;
    cout << " e) Exit the program." << endl;
    cout << endl;
    cout << " Enter your selection: ";
}

// do the counting of the string
void counter(char *pointer, int &vowels, int &consonants, int &numbers){
    // get the string length
    int cc = strlen(pointer);
    // loop over the string to check the values
    for (int c = 0; c < cc; c++) {
        // check if its a alphabetic
        if (isalpha(*pointer)) {
            // checking char
            char v[2] = "-";
            // set to lower the whole string
            v[0] = tolower(*pointer);
            // check fo vowels
            if (strcmp(v, a_) == 0 || strcmp(v, e_) == 0 ||
                strcmp(v, i_) == 0 || strcmp(v, o_) == 0 ||
                strcmp(v, u_) == 0) {
                // found a vowel
                // cout << "vowel: " << *pointer << endl; // debug
                ++vowels;
            } else {
                // found a consonants
                // cout << "consonant: " << *pointer << endl; // debug
                ++consonants;
            }
        } else if (isdigit(*pointer)) {
            // found a number
            // cout << "number: " << *pointer << endl; // debug
            ++numbers;
        }
        pointer++;
    }
}
