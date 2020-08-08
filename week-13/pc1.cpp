/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 13: Assignment (second semester) - Starting out with C++ Early Objects (9 Edition) (2020/08/08)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Stacks & Queues - Chapter 18 (Page 1123)
 * Programming Challenge (9. File Reverser)
 * Using a stack data type, reverse the content of a file
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Written by Llewellyn van der Merwe <llewellyn.vandermerw@mymail.champlain.edu>, Aug 2020
 * Copyright (C) 2020. All Rights Reserved
 * License GNU/GPL Version 2 or later - http://www.gnu.org/licenses/gpl-2.0.html
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <fstream>
#include <string>
#include <stack>

// Function Declarations
void readCharFileToStack(std::string &filePath, std::stack<char> &fileContent);
void writeStackToFile(std::string &filePath, std::stack<char> &fileContent);

int main() {
    // My test file is one directory up, from the executable
    // Please set the file paths to your test files here
    std::string filePathIn = "../test_file";
    std::string filePathOut = "../test_file_out";
    // initialize the stack content bucket;
    std::stack<char> fileContent;
    // now get the file "in" content
    readCharFileToStack(filePathIn, fileContent);
    // now lets push the characters to a new file "out"
    writeStackToFile(filePathOut, fileContent);

    return 0;
}

// Adapted this from https://stackoverflow.com/a/40930254/1429677
// To read the characters from a file one by one
void readCharFileToStack(std::string &filePath, std::stack<char> &fileContent) {
    std::ifstream file(filePath);
    char c;
    if(file.is_open()) {
        while(!file.eof()) {
            file.get(c);
            if ((!file.eof())) {
                // set the character to the stack
                fileContent.push(c);
            }
        }
    }
    if(!file.eof() && file.fail())
        std::cout << "error reading " << filePath << std::endl;
    file.close();
}

// To write characters to a file one at a time
void writeStackToFile(std::string &filePath, std::stack<char> &fileContent) {
    std::fstream file(filePath, std::ios::trunc | std::ios::out);
    if(file.is_open()) {
        do {
            file << fileContent.top();
            fileContent.pop();
        } while(!fileContent.empty());
    }
    if(!file.eof() && file.fail())
        std::cout << "error writing to " << filePath << std::endl;
    file.close();
}
