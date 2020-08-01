/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 12: Assignment (second semester) - Starting out with C++ Early Objects (9 Edition) (2020/07/19)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Linked Lists - Chapter 17 (Page 1082)
 * Programming Challenge (7. List Search)
 * Modify the list class of Programming Challenge 1 (or later) to include a member function search()
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Written by Llewellyn van der Merwe <llewellyn.vandermerw@mymail.champlain.edu>, July 2020
 * Copyright (C) 2020. All Rights Reserved
 * License GNU/GPL Version 2 or later - http://www.gnu.org/licenses/gpl-2.0.html
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
using namespace std;

// Most of this code is from Chapter 17.2 code examples
// Simple Linked List Class (with search)
class LinkedList
{
protected:
    // Declare a class (struct)
    struct ListNode
    {
        double value;
        ListNode *next;
        ListNode (double value1, ListNode *next1 = nullptr)
        {
            value= value1;
            next= next1;
        }
    };
    ListNode *head; // List head pointer
public:
    LinkedList(){ head = nullptr; } // Constructor
    ~LinkedList (); // Destructor
    void add(double number);
    int search(double number);
};

//*****************************************************
// add adds a new element to the end of the list.
//*****************************************************
void LinkedList::add (double number)
{
    if (head == nullptr)
        head = new ListNode(number);
    else
    {
        // The list is not empty
        // Use nodePtr to traverse the list
        ListNode *nodePtr = head ;
        while ( nodePtr->next != nullptr)
            nodePtr = nodePtr->next;
        // nodePtr->next is nullptr so nodePtr points to last
        // Create a new node and put it after the last node
        nodePtr->next = new ListNode(number);
    }
}

//***************************************************
// Check if an value is part of the linked
// list then return the position it is at
//***************************************************
int LinkedList::search(double number)
{
    int position = 0;
    ListNode *nodePtr = head; // Start at head of list
    while (nodePtr)
    {
        // check if the number is found
        if (nodePtr->value == number)
            return position;
        // Move on to the next node
        nodePtr = nodePtr->next;
        position++;
    }
    return -1;
}

//******************************************************
// Destructor deallocate the memory used by the list
//******************************************************
LinkedList::~LinkedList()
{
    ListNode *nodePtr = head; // Start at head of list
    while (nodePtr != nullptr)
    {
        // garbage keeps track of node to be deleted
        ListNode *garbage = nodePtr;
        // Move on to the next node, if any
        nodePtr = nodePtr->next;
        // Delete the "garbage" node
        delete garbage;
    }
}

int main() {
    // main values     0    1     2    3     4
    double xArray[] = {2.5, 12.6, 7.9, 20.3, 31.3};
    // search values
    double sArray[] = {10.3, 31.3, 12.6, 4.2, 20.3};
    // the position value
    int p;
    // instantiate the linked list
    LinkedList list;
    // add the values
    for (double x :xArray)
        list.add(x);
    // now we search
    for (double e :sArray)
        if ((p = list.search(e)) != -1)
            cout << e << " at position: " << p << endl;
        else
            cout << e << " is not in the linked list" << endl;

    return 0;
}