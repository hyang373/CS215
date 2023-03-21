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

struct node_one{
        int key;
        node *left;
        node *right;
        node *parent;
        string color;
};
typedef struct node_one node_one;

class RBT
{
        public:
                // default constructor
                RBT();

                // insert value into tree
                void RB_insert(node_one*& Root, int value);

                // delete a value from trree
                void RB_delete(node_one*& Root, int value);

                // print tree in order
                void RB_walk(node_one* Node) const;

                // determine tree height
                int RB_height(node_one* Node);

        private:
                // declare private variables for binary search tree
                node_one *root;
                void RB_insertFixup(node_one*& Root, node_one*& Node);
                void RB_deleteFixup(node_one*& Root, node_one*& Node);
                node_one* RB_search(node_one* Node, int value) const;
                void transplant(node_one*& Root, node_one*& num1, node_one*& num2);
                void left_rotate(node_one*& Root, node_one*& Node);
                void right_rotate(node_one*& Root, node_one*& Node);
                node_one* RB_min(node_one *pos);
                node_one* RB_max(node_one *pos);

};
#endif /* RBT_H */
