//******************************************************************************************
// This program gathers the data of the number of movies
// watched by college students per/month. Then calculates the
// average, median, and mode from the given input values.
//   Writen by Llewellyn van der Merwe (2020/05)
//******************************************************************************************
// Starting out with C++ Early Objects (Ninth Edition)
//   by Tony Gaddis, Judy Walters, Godfrey Muganda
// Review Questions and Exercises (page 702)
//------------------------------------------------------------------------------------------
// 7. Movie Statistics
//  Write a program that can be used to gather statistical data about the number of movies
//  college students see in a month. The program should ask the user how many students
//  were surveyed and dynamically allocate an array of that size. The program should then
//  allow the user to enter the number of movies each student has seen. The program
//  should then calculate the average, median, and mode of the values entered .
//******************************************************************************************
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Function prototypes
void getMoviesViewed(int *survey, int size);

double getTotal(int *survey, int size);

double getAverage(int *survey, int size);

double getMedian(int *survey, int size);

string getMode(int *survey, int size);

void quickSort(int *survey, int low, int high);

int main() {
    // we first get the number of students
    int number;
    cout << "Enter the number of college students that were surveyed: ";
    cin >> number;
    // only continue if we have a number higher then zero and lower the 100
    if (number > 0 && number < 101) {
        // add to constant
        const int STUDENTS = number;
        // the survey array
        int survey[STUDENTS];
        // get each student's number of movies viewed
        getMoviesViewed(survey, STUDENTS);
        // display the results
        cout << endl;
        cout << "  The average number of movies watched: ";
        cout << setprecision(2) << fixed << showpoint << getAverage(survey, STUDENTS) << endl;
        cout << "  The median of the number of movies watched: ";
        cout << setprecision(2) << fixed << showpoint << getMedian(survey, STUDENTS) << endl;
        cout << "  The mode of the number of movies watched: ";
        cout << getMode(survey, STUDENTS) << endl;
        cout << endl;
    } else {
        cout << "Oops, enter a number between 1 and 100" << endl;
        cout << "Please try again!" << endl;
    }
    return 0;
}

//******************************************************************************************
// Definition of the getMoviesViewed.
// This function is used to get each student's number of movies watched
//******************************************************************************************
void getMoviesViewed(int *survey, int size) {
    // get first element pointer
    int *ptr = &survey[0];
    cout << endl;
    for (int count = 0; count < size; count++) {
        cout << "  Enter the number of movies watched by student ";
        cout << (count + 1) << ": ";
        cin >> *ptr;
        ptr++;
    }
    cout << endl;
}

//******************************************************************************************
// Definition of the getTotal.
// This function is used to get total movies watched
//******************************************************************************************
double getTotal(int *survey, int size) {
    int sum = 0.00;
    for (int count = 0; count < size; count++) {
        sum += *survey++;
    }
    return sum;
}

//******************************************************************************************
// Definition of the getAverage.
// This function is used to get average of movies watched
//******************************************************************************************
double getAverage(int *array, int size) {
    double total = getTotal(array, size);
    // make sure we have more then 0
    if (total > 0) {
        return total / size;
    } else {
        return 0.00;
    }
}

//******************************************************************************************
// Definition of the getMedian.
// This function is used to get median movies watched
//******************************************************************************************
double getMedian(int *survey, int size) {
    // first sort the array
    quickSort(survey, 0, size - 1);
    // get first element pointer
    int *ptr = &survey[0];
    // get the middle of this array
    int get = floor(size / 2);
    // check if odd or even array size & since it is odd we have a center number
    if (size % 2) {
        return *(ptr + get);
    } else {
        double m = *(ptr + get) + *(ptr + get - 1);
        return m / 2;
    }
}

//******************************************************************************************
// Definition of the getMode.
// This function is used to get mode of the movies watched
//******************************************************************************************
string getMode(int *survey, int size) {
    // bucket to get the multi sets
    map<int, int>::iterator mode;
    map<int, int> modes;
    // our trigger
    int trigger = 0;
    // get first element pointer
    int *ptr = &survey[0];
    for (int i = 0; i < size; i++) {
        // get first element pointer
        int *pointer = &survey[0];
        for (int j = 0; j < size; j++) {
            if (*pointer == *ptr && pointer != ptr) {
                if (modes.count(*ptr) > 0) {
                    modes[*ptr]++;
                } else {
                    modes[*ptr] = 2;
                }
                trigger++;
            }
            pointer++;
        }
        ptr++;
    }
    // set the default winner value
    string winner = "none found";
    // check if we found a mode
    if (trigger > 0) {
        // bucket to get the winner sets
        map<int, string> winners;
        // loop over the found modes
        int counter = 1;
        for (mode = modes.begin(); mode != modes.end(); mode++) {
            // check if we have a winner
            if (counter <= mode->second) {
                // set the current winner
                if (counter == mode->second) {
                    // another of the same winner
                    winners[mode->second] += ", " + to_string(mode->first);
                } else {
                    // new winner
                    winners[mode->second] = to_string(mode->first);
                }
                // raise the bar
                counter = mode->second;
                // keep track of the winners
                winner = winners[mode->second];
            }
        }
    }
    // return winner string
    return winner;
}

//******************************************************************************************
// Definition of the quickSort.
// This function is used to quick sort the array
// https://gist.github.com/christophewang/ad056af4b3ab0ceebacf (adaptation)
//******************************************************************************************
void quickSort(int *survey, int low, int high) {
    int i = low;
    int j = high;
    int pivot = survey[(i + j) / 2];
    int temp;

    while (i <= j) {
        while (survey[i] < pivot)
            i++;
        while (survey[j] > pivot)
            j--;
        if (i <= j) {
            temp = survey[i];
            survey[i] = survey[j];
            survey[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(survey, low, j);
    if (i < high)
        quickSort(survey, i, high);
}
