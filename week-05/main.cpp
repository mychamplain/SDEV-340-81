/*
 *
 *  Created on: Jun 29, 2012
 *      Author: Derek
 *
 *  Updated on: June 17, 2020
 *      Author: Llewellyn
 *
 *  Example of the binary search algorithm
 */

#include <iostream>

using namespace std;

int binarySearch(int array[], int low, int high, int mid, int searchValue)
{
    // if found return
    if(searchValue == array[mid]) {
        return mid;
    } else if (low <= high) {
        // get search again
        if (searchValue > array[mid]) {
            low =  mid + 1;
        } else {
            high =  mid - 1;
        }
        // get the mid point
        mid = (low + high) / 2;
        // recursion binary search
        return binarySearch(array, low, high, mid, searchValue);
    }
    return -1;
}

int main()
{
    int a[] = {1, 5, 11, 14, 16, 18, 22, 24, 25, 28, 31, 35, 37, 39, 42, 44, 46, 48, 51, 55, 57, 59, 62, 63};

    int userValue;
    int low = 0;
    int high = sizeof(a) - 1;
    // get the mid point
    int mid = (low + high) / 2;

    cout << "Enter an integer: " << endl;
    cin >> userValue;

    int result = binarySearch(a, low, high, mid, userValue);

    if(result >= 0)
    {
        cout << "The number " << a[result] << " was found at the"
                                              " element with index " << result << endl;
    }
    else
    {
        cout << "The number " << userValue << " was not found. " << endl;
    }
}