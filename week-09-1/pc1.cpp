/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 9: Assignment (second semester) - Starting out with C++ Early Objects (9 Edition) (2020/07/4)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Polymorphism and Virtual functions
 * Recursion - Chapter 15 (Page 985)
 * Programming Challenge (3. Sequence Sum)
 * Abstract Class called AbstractSeq with virtual member function, and prints and sum sequences
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Written by Llewellyn van der Merwe <llewellyn.vandermerw@mymail.champlain.edu>, July 2020
 * Copyright (C) 2020. All Rights Reserved
 * License GNU/GPL Version 2 or later - http://www.gnu.org/licenses/gpl-2.0.html
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <memory>
#include <random>

using namespace std;

// Abstract Sequence Class
class AbstractSeq{
private:
    // used to sum
    int total = 0;
public:
    // function to print sequence
    void printSeq(int k, int m) {
        if (k <= m) {
            // print out k
            cout << k;
            // get the next k
            k = fun(k);
            // check if we should print the comma
            if (k <= m) {
                cout << ", ";
            }
            // recursive call printSeq,
            // and update k with fun
            return printSeq(k, m);
        }
    }
    // function to sum sequence
    int sumSeq(int k, int m) {
        // check if we must sum next
        if (k <= m) {
            // add to total
            total += k;
            // recursive call sumSeq,
            // and update k with fun
            return sumSeq(fun(k), m);
        }
        // k is no longer lesser then m
        // so we are done summing the total
        int sum = total;
        // reset total for next sum
        total = 0;
        // return the sum
        return sum;
    }
    // return the function name
    virtual string getName() = 0;
    // Pure Virtual Function to sort
    virtual int fun(int k) = 0;
};

// Real Odd Sequence
class Odd: public AbstractSeq{
public:
    // set the sequence
    int fun(int k) override{
        int nr = 1;
        int add = 2;
        // build next
        int next = nr + add;
        nr++;
        add++;
        // base case
        while (k >= next)
        {
            next = nr + add;
            nr++;
            add++;
        }
        return next;
    }
    // get the name of this seq
    string getName() override{
        return "Odd Sequence";
    }
};

// The Triangular Sequence
// https://www.mathsisfun.com/algebra/triangular-numbers.html
class Triangular: public AbstractSeq{
public:
    // set the sequence
    int fun(int k) override{
        if (k == 1)
        {
            return 3;
        }
        // build next
        int next = 6;
        int add = 4;
        // base case
        while (k >= next)
        {
            next = next + add;
            add++;
        }
        return next;
    }
    // get the name of this seq
    string getName() override{
        return "Triangular Sequence";
    }
};

// The Cube Sequence
// https://www.mathsisfun.com/numbers/cube-root.html
class Cube: public AbstractSeq{
public:
    // set the sequence
    int fun(int k) override{
        if (k == 1)
        {
            return 8;
        }
        // get cube root
        int cube_root = cbrt(k);
        // get next
        cube_root++;
        // calculate the next
        return cube_root * cube_root * cube_root;
    }
    // get the name of this seq
    string getName() override{
        return "Cube Sequence";
    }
};

// The Fibonacci Sequence
// https://en.wikipedia.org/wiki/Fibonacci_number
class Fibonacci: public AbstractSeq{
private:
    int start = 2;
public:
    // set the sequence
    int fun(int k) override{
        // the smallest are basic
        if(k == 1 && start > 1){
            start--;
            return 1;
        } else if(k == 2 && start > 2){
            start--;
            return 2;
        }
        // calculate the next Fibonacci number
        return previous(k) + k;
    }
    // get the previous fibonacci number
    // https://www.geeksforgeeks.org/find-the-previous-fibonacci-number/
    static int previous(int k)
    {
        double a = k / ((1 + sqrt(5)) / 2.0);
        return round(a);
    }
    // get the name of this seq
    string getName() override{
        return "Fibonacci Sequence";
    }
};

// main function
int main() {

    // get some random number methods
    // http://sdrv.ms/1e11LXl
    random_device rd;
    mt19937 mt_k(rd());
    mt19937 mt_m(rd());
    uniform_int_distribution<int> my_random_k(1, 11);
    uniform_int_distribution<int> my_random_m(310, 2500);

    // Least two different sequences fore each sequence
    int k = 1; // basic test
    int m = 377; // basic test
    int k2 = my_random_k(mt_k); // set some random numbers
    int m2 = my_random_m(mt_m); // set some random numbers

    // Instantiate AbstractSeq Sequence
    shared_ptr<AbstractSeq> Sequence[] =
    {
        // we load the text book example
        make_shared<Odd>(),
        make_shared<Triangular>(),
        make_shared<Cube>(),
        make_shared<Fibonacci>()
    };

    // the size of our array
    int size = sizeof(Sequence)/sizeof(Sequence[0]);

    // print out the sequences
    for (int i = 0; i < size; i++)
    {
        // print the name
        cout << "==> " << Sequence[i]->getName() << endl;
        // print out the sequence
        cout << "  Sequence (" << k << " - " << m <<"): ";
        Sequence[i]->printSeq(k, m);
        // sum the sequence
        cout << " = " << Sequence[i]->sumSeq(k, m) << endl;
        // print out the sequence
        cout << "  Sequence (" << k2 << " - " << m2 << "): ";
        Sequence[i]->printSeq(k2, m2);
        // sum the sequence
        cout << " = " << Sequence[i]->sumSeq(k2, m2) << endl;
    }

    return 0;
}
