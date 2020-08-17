/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Champlain College SDEV-340-81
 *
 * C++ Week 14: Assignment (second semester) - Starting out with C++ Early Objects (9 Edition) (2020/08/15)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Binary Search Tree - Chapter 19 (Page 1123)
 * Programming Challenge (1. Simple Binary Search Tree Class)
 * Implementing a simple binary search tree capable of storing numbers.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Written by Llewellyn van der Merwe <llewellyn.vandermerw@mymail.champlain.edu>, Aug 2020
 * Copyright (C) 2020. All Rights Reserved
 * License GNU/GPL Version 2 or later - http://www.gnu.org/licenses/gpl-2.0.html
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <vector>

using namespace std;

// Binary Tree Class
// Adaption from Chapter 19
// IntBinaryTree class on page 1130
class Btree
{
private:
    struct BtreeNode
    {
        int value;
        BtreeNode* left;
        BtreeNode* right;
        BtreeNode(int value1, BtreeNode *left1 = nullptr, BtreeNode *right1 = nullptr) {
            value = value1;
            left = left1;
            right = right1;
        }
    };

    BtreeNode* root; // Pointer to the root of the tree

    // Various helper member functions.
    void insert(BtreeNode *&tree, int num) {
        // If the tree is empty, make a new node and make it
        // the root of the tree
        if (!tree) {
            tree = new BtreeNode(num);
            return;
        }
        // If num is already in tree:
        if (tree->value == num)
            return;
        // The tree is not empty: insert the new node into the
        // left or right subtree
        if (num < tree->value)
            insert(tree->left, num);
        else
            insert(tree->right, num);
    }
    void destroySubtree(BtreeNode *tree) {
        if (!tree) return;
        destroySubtree(tree->left);
        destroySubtree(tree->right);
        //  Delete the node at the root
        delete tree;
    }
    void remove(BtreeNode *&tree, int num) {
        if (tree == nullptr) return ;
        if (num < tree->value )
            remove(tree->left, num);
        else if (num > tree->value)
            remove(tree->right, num);
        else
            // We have found the node to delete .
            makeDeletion (tree);
    }
    void makeDeletion(BtreeNode *&tree) {
        // Used to hold node that will be deleted
        BtreeNode *nodeToDelete = tree;

        // Used to locate the point where the
        // left subtree is attached
        BtreeNode *attachPoint;

        if (tree->right == nullptr) {
            // Replace tree with its left subtree
            tree = tree->left ;
        }  else if (tree->left == nullptr) {
            // Replace tree with its right subtree
             tree = tree->right;
        } else {
        // The node has two children
            // Move to right subtree
            attachPoint = tree->right;

            // Locate the smallest node in the right subtree
            // by moving as far to the left as possible
            while (attachPoint->left != nullptr)
                attachPoint = attachPoint->left;

            // Attach the left subtree of the original tree
            // as the left subtree of the smallest node
            // in the right subtree
            attachPoint->left = tree->left;

            // Replace the original tree with its right subtree
            tree = tree->right;
        }
        // Delete root of original tree
        delete nodeToDelete;
    }
    void displayInOrder(BtreeNode *tree) const {
        if (tree) {
            displayInOrder(tree->left);
            cout << tree->value << " ";
            displayInOrder(tree->right);
        }
    }
    void displayPreOrder(BtreeNode *tree) const {
        if (tree) {
            cout << tree->value << " ";
            displayPreOrder(tree->left);
            displayPreOrder(tree->right);
        }
    }
    void displayPostOrder(BtreeNode *tree) const {
        if (tree) {
            displayPostOrder(tree->left);
            displayPostOrder(tree->right);
            cout << tree->value << " ";
        }
    }

public:
    // These member functions are the public interface.
    // Constructor
    Btree () {
        root = nullptr;
    }
    // Destructor
    ~Btree () {
        destroySubtree(root);
    }
    // insert function
    void insert(int num) {
        insert(root, num);
    }
    // search function
    bool search(int num) const {
        BtreeNode *tree = root;
        while (tree)
        {
            if (tree->value == num)
                return true;
            else if (num < tree->value)
                tree = tree->left;
            else
                tree = tree->right;
        }
        return  false;
    }
    // remove a node
    void remove(int num) {
        remove(root, num);
    }
    // show in order
    void showInOrder(void) const {
        displayInOrder(root);
    }
    // show in pre order
    void showPreOrder() const {
        displayPreOrder(root);
    }
    // show in post order
    void showPostOrder() const {
        displayPostOrder(root);
    }
};

int main() {
    Btree tree;
    cout << "Inserting the numbers 5 8 3 12 9" << endl;
    tree.insert(5) ;
    tree.insert(8) ;
    tree.insert(3) ;
    tree.insert( 12) ;
    tree.insert(9) ;
    cout << "Here are the values in the tree" << endl;
    tree.showInOrder();
    cout << "\nDeleting 8..." << endl;
    cout << "Deleting 12..." << endl;
    tree.remove (8) ;
    tree.remove ( 12) ;
    cout << "Now, here are the nodes" << endl;
    tree.showInOrder();
    return 0;
}
