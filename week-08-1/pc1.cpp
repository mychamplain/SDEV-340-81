/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 8: Assignment (second semester) - Starting out with C++ Early Objects (9 Edition) (2020/07/4)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Polymorphism and Virtual functions
 * Recursion - Chapter 15 (Page 985)
 * Programming Challenge (1. Analysis of Sorting Algorithms)
 * Analyze the number of comparisons performed (Simple Sorting Algorithm)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Written by Llewellyn van der Merwe <llewellyn.vandermerw@mymail.champlain.edu>, July 2020
 * Copyright (C) 2020. All Rights Reserved
 * License GNU/GPL Version 2 or later - http://www.gnu.org/licenses/gpl-2.0.html
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <iostream>
#include <memory>

using namespace std;

// Abstract Sort Class
class AbstractSort{
protected:
    int comparison_counter;
public:
    // function to compare values
    bool compare(int *a, int *b) {
        comparison_counter++;
        return *a > *b;
    }
    // Pure Virtual Function to sort
    virtual void sort(int *arr, int size ) = 0;
    // get comparison counter
    int getComparisonCounter() { return comparison_counter; }
};

// Simple Sort Class
class SimpleSort:public AbstractSort{
public:
    SimpleSort() {comparison_counter = 0;}
    // Function override to sort (Simple Sorting)
    virtual void sort(int *arr, int size ) {
        // some default stuff
        int i ,j;
        int temp;
        // Simple Sorting
        for (i = 0; i < size; ++i)
        {
            for (j = i + 1; j < size; ++j)
            {
                // compare the array elements
                if (compare((arr + i), (arr + j)))
                {
                    temp =  *(arr + i);
                    *(arr + i) = *(arr + j);
                    *(arr + j) = temp;
                }
            }
        }
    }
};

// main function
int main() {
    // array we would like to sort
    int arr[] = {5, 72, 22, 4, 51, 88, 34, 482, 21, 25, 9, 10, 11, 1, 1, 98, 12, 6, 2, 33, 44, 8, 3, 1, 9, 59, 109};
    // the size of our array
    int size = sizeof(arr)/sizeof(arr[0]);

    // before sorting
    cout << endl << " Unsorted: ";
    for(int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }

    // Instantiate Simple Search
    shared_ptr<SimpleSort> simple_sort = make_shared<SimpleSort>();
    // sort the array
    simple_sort->sort(arr, size);

    // proof that it was sorted
    cout << endl << " Sorted:   ";
    for(int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }

    // show the number of comparisons in simple sort
    cout << endl << endl << " Number of Comparisons (simple sort): " << simple_sort->getComparisonCounter() << endl;

    return 0;
}
