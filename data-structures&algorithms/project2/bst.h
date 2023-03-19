/*
 * File: bst.h
 * Course: CS 315 - 001
 * Project: Problem Set 2
 * Purpose: Declaration of BST class
 *      - Includes functions of a Binary Search Tree
 */

#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct node{
        int key;
        node *left;
        node *right;
};

class BST
{
        public:
                // default constructor
                create_tree();

                // insert value into tree
                void tree_insert(int value);

                // delete a value from trree
                void tree_delete(int value);

                void transplant(int num1, int num2);

                // find min of node pos
                int tree_min(int pos) const;

                // find max of node pos
                int tree_man(int pos) const;

                void tree_print() const;
        private:
                // declare private variable for binary search tree
                node *root;
};
#endif /* BST_H */
