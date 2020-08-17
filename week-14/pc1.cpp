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
// Adapted from Chapter 19
// IntBinaryTree class on page 1130
class Btree
{
private:
    struct BtreeNode
    {
        double value;
        BtreeNode* left;
        BtreeNode* right;
        BtreeNode(double value_, BtreeNode *left_ = nullptr, BtreeNode *right_ = nullptr) {
            value = value_;
            left = left_;
            right = right_;
        }
    };

    BtreeNode* root; // Pointer to the root of the tree

    bool search(double num, BtreeNode *tree) const {
        // If the tree is empty
        if (!tree) {
            return false;
        }
        // found the value
        if (tree->value == num)
            return true;
        else if (num < tree->value)
            // recursive search
            search(num, tree->left);
        else
            // recursive search
            search(num, tree->right);
    }
    void destroySubtree(BtreeNode *tree) {
        if (!tree) return;
        destroySubtree(tree->left);
        destroySubtree(tree->right);
        //  Delete the node at the root
        delete tree;
    }
    void remove(BtreeNode *&tree, double num) {
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
    // get the values in order, and add to vector
    void inorder(vector <double> &v, BtreeNode *tree) const {
        if (tree) {
            inorder(v, tree->left);
            v.push_back(tree->value);
            inorder(v, tree->right);
        }
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
    void insert(double num) {
        BtreeNode *tree = root;
        // if the tree is empty
        if (tree == nullptr) {
            root = new BtreeNode(num);
            return;
        }
        // tree not empty we add leaves
        while (true)
        {
            if (tree->value == num) {
                return;
            } else if (num < tree->value) {
                if (tree->left == nullptr){
                    tree->left = new BtreeNode(num);
                    return;
                } else {
                    tree = tree->left;
                }
            } else {
                if (tree->right == nullptr){
                    tree->right = new BtreeNode(num);
                    return;
                } else {
                    tree = tree->right;
                }
            }
        }
    }
    // search function
    bool search(double num) const {
        search(num, root);
    }
    // remove a node
    void remove(double num) {
        remove(root, num);
    }
    // get the values in order, and add to vector
    void inorder(vector <double> &v) const {
        inorder(v, root);
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
    cout << "Inserting the numbers 21.42, 5.52, 8.43, 3.22, 12.51, 9.13, 123.23" << endl;
    tree.insert(21.42);
    tree.insert(5.52);
    tree.insert(8.43);
    tree.insert(3.22);
    tree.insert(12.51);
    tree.insert(9.13);
    tree.insert(123.23);
    cout << "Here are the values inserted into the tree" << endl;
    cout << " (Pre Order)" << endl;
    tree.showPreOrder();
    cout << "\n (Post Order)" << endl;
    tree.showPostOrder();
    cout << "\n (In Order)" << endl;
    tree.showInOrder();
    cout << "\n\nDeleting 8.43..." << endl;
    cout << "Deleting 12.51..." << endl;
    tree.remove (8.43);
    tree.remove (12.51);
    cout << "\nLets check if 8.43 is still in the tree:" << endl;
    if(tree.search(8.43)){
        cout << "  8.43 found" << endl;
    } else {
        cout << "  8.43 not found" << endl;
    }
    cout << "Lets check if 9.13 is still in the tree:" << endl;
    if(tree.search(9.13)){
        cout << "  9.13 found" << endl;
    } else {
        cout << "  9.13 not found" << endl;
    }
    cout << "\nNow, here are the remainder of the values:" << endl;
    cout << "  (inorder vector method used)" << endl;
    // initialize the vector
    vector<double> v;
    // get the order values
    tree.inorder(v);
    // print out the values
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << ' ';
    cout << endl;

    return 0;
}
