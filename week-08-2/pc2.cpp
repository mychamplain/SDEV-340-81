/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 8: Assignment (second semester) - Starting out with C++ Early Objects (9 Edition) (2020/07/4)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Polymorphism and Virtual functions
 * Recursion - Chapter 15 (Page 985)
 * Programming Challenge (2. Analysis of Sorting Algorithms)
 * Analyze the number of comparisons performed (Quick Sorting Algorithm)
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

// Quick Sort Class
class QuickSort:public AbstractSort{
public:
    QuickSort() {comparison_counter = 0;}
    // Function override to sort (Quick Sorting)
    void sort(int *arr, int size ) {
        sort(arr, 0, size - 1);
    }
    // local sort needed for quick sort
    void sort(int *arr, int low, int high) {
        // some default stuff
        int i = low;
        int j = high;
        int pivot = *(arr + ((i + j) / 2));
        int temp;
        // compare the array positions
        while (position_compare(&i, &j)) {
            // compare the array values
            while (compare(&pivot, (arr + i)))
                i++;
            // compare the array values
            while (compare((arr + j), &pivot))
                j--;
            // compare the array positions
            if (position_compare(&i, &j)) {
                temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
                i++;
                j--;
            }
        }
        // compare the array values
        if (compare(&j, &low))
            sort(arr, low, j);
        // compare the array values
        if (compare(&high, &i))
            sort(arr, i, high);
    }
    // local compare for the positions
    bool position_compare(int *a, int *b) {
        comparison_counter++; // not sure if this should also be count (just comment out this line if not)
        return *a <= *b;
    }
};

// main function
int main() {
    // array we would like to sort (mixed)
    int arr[] = {5, 72, 22, 4, 51, 88, 34, 482, 21, 25, 9, 10, 11, 1, 1, 98, 12, 6, 2, 33, 44, 8, 3, 1, 9, 59, 109};
    // the size of our array
    int size = sizeof(arr)/sizeof(arr[0]);

    // before sorting
    cout << endl << " Unsorted: ";
    for(int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }

    // Instantiate Quick Sort
    shared_ptr<QuickSort> quick_sort = make_shared<QuickSort>();
    // sort the array
    quick_sort->sort(arr, size);

    // proof that it was sorted
    cout << endl << " Sorted:   ";
    for(int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }

    // show the number of comparisons in quick sort
    cout << endl << endl << " Number of Comparisons (quick sort): " << quick_sort->getComparisonCounter() << endl;

    return 0;
}
