/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 6: Assignment (second semester) - Recursion Continued (2020/06/20)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Working with recursion
 * Recursion - Chapter 14 (Page 947)
 * Programming Challenge (6. Recursive Member Test) Search user given array for member value
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

void quickSort(int *arr, int low, int high);
bool isMember (int arr[], int length, int searchValue);
bool binarySearch(const int arr[], int low, int high, int searchValue);

int main() {
    // set size of input array (large to get all user input)
    int const SIZE = 100;
    // the user input array
    int user_input_array[SIZE];
    // user input length
    int n = 0;
    // now ask for the integers
    cout << "Enter one member as an integer at a time, and d when done." << endl;
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
    // user input search
    int searchValue;
    // now ask member what member should we search for
    cout << "Enter the member number you would like to search for: ";
    cin >> searchValue;
    // check if it was found
    if (isMember(user_input_array, n, searchValue)) {
        cout << "Member " << searchValue << " WAS found." << endl;
    } else {
        cout << "Member " << searchValue << " NOT found." << endl;
    }
    return 0;
}

// doing a binary search as found on page 928 of our text book
bool isMember (int arr[], int length, int searchValue)
{
    // sort the input members
    quickSort(arr, 0, length - 1);
    // now search for this member number is found
    return binarySearch(arr, 0, length, searchValue);
}

// Binary search as found on page 928 of our text book
bool binarySearch(const int arr[], int low, int high, int searchValue)
{
    // base case
    if (low > high)
        return false;
    // mid point
    int mid = (low + high) / 2;
    // if found return
    if(searchValue == arr[mid]) {
        return true;
    } else if (arr[mid] < searchValue) {
        // recursion binary search
        return binarySearch(arr, mid + 1, high, searchValue);
    } else {
        // recursion binary search
        return binarySearch(arr, low, mid - 1, searchValue);
    }
}

//******************************************************************************************
// Definition of the quickSort.
// This function is used to quick sort the array
// https://gist.github.com/christophewang/ad056af4b3ab0ceebacf (adaptation)
//******************************************************************************************
void quickSort(int *arr, int low, int high) {
    int i = low;
    int j = high;
    int pivot = arr[(i + j) / 2];
    int temp;

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(arr, low, j);
    if (i < high)
        quickSort(arr, i, high);
}
