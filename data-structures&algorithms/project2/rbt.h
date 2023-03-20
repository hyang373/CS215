/*
 * File: rbt.h
 * Course: CS 315 - 001
 * Project: Problem Set 2
 * Purpose: Declaration of RBT class
 *      - Includes functions of a Red-Black Tree
 */

#ifndef RBT_H
#define RBT_H

#include <iostream>
#include <string>
using namespace std;

struct node1{
        int key;
        node *left;
        node *right;
        node *parent;
        string color;
        bool T_root;
};
typedef struct node1 node1;

class RBT
{
        public:
                // default constructor
                RBT();

                // insert value into tree
                void RB_insert(node*& tree, int value);
                void RB_insertFixup(node*& tree, node*& Node);

                // delete a value from trree
                void RB_delete(node*& tree, int value);
                void RB_deleteFixup(node*& tree, node*& Node);
                node* RB_search(node* Node, int value) const;
                void transplant(node*& tree, node*& num1, node*& num2);

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
#endif /* RBT_H */
