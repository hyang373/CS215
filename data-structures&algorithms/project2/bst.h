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
        node *parent;
};
typedef struct node node;

class BST
{
        public:
                // default constructor
                BST();

                // insert value into tree
                void tree_insert(node*& Root, int value);

                // delete a value from trree
                void tree_delete(node*& Root, int value);

                node* tree_search(node* Root, int value) const;

                void transplant(node*& Root, node*& num1, node*& num2);

                // find min of node pos
                node* tree_min(node *pos);

                // find max of node pos
                node* tree_max(node *pos);

                void tree_walk(node* Root) const;

                int tree_height(node* Root);

        private:
                // declare private variables for binary search tree
                node *root;

};
#endif /* BST_H */
