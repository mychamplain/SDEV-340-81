/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 12: Assignment (second semester) - Starting out with C++ Early Objects (9 Edition) (2020/07/19)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Linked Lists - Chapter 17 (Page 1082)
 * Programming Challenge (1. Simple Linked List Class.)
 * Using an appropriate definition of ListNode, design a simple linked
 * list class with only two member functions and a default constructor.
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
// Simple Linked List Class
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
    bool isMember(double number);
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
// Check if an value is part of the linked list
//***************************************************
bool LinkedList::isMember(double number)
{
    ListNode *nodePtr = head; // Start at head of list
    while (nodePtr)
    {
        // Print the value in the current node
        if (nodePtr->value == number)
            return true;
        // Move on to the next node
        nodePtr = nodePtr->next;
    }
    return false;
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

int main()
{
    // main values
    double xArray[] = {2.5, 12.6, 7.9, 20.3, 31.3};
    // search values
    double sArray[] = {10.3, 31.3, 12.6, 4.2, 20.3};
    // instantiate the linked list
    LinkedList list;
    // add the values
    for (double x :xArray)
        list.add(x);
    // now we search
    for (double e :sArray)
        if (list.isMember(e))
            cout << e << " is a member" << endl;
        else
            cout << e << " is not a member" << endl;

    return 0;
}
