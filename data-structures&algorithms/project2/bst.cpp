/*
 * File: bst.cpp
 * Cousre: CS 315
 * Project: Problem Set 2
 * Purpose: Provide the declarations of the class named bst
 *
 */

#include "bst.h"
#include <iostream>
using namespace std;

// default constructor
BST::create_tree(){
        root = NULL;
        left = NULL;
        right = NULL;
}

// insert value into tree
void BST::tree_insert(struct node* root, int value){
        // create a new node for value
        node *new_node;
        new_node->key = value;

        node *y = NULL;
        node *x = root;
        // traversal through the tree
        while(x->key != NULL){
                // keeps track of the node that lead to x
                y = x;

                if(new_node->key < x->key){
                        x = x->left;
                }
                else{
                        x = x->right;
                }
        }
        new_node->parent = y;
        if(y == NULL){
                // tree is empty
                root = new_node;
        }
        else if(new_node->key < y->key){
                y->left =
        }
}

// delete a value from trree
void BST::tree_delete(int value){

}

void BST::transplant(int num1, int num2){

}

// find min of node pos
int BST::tree_min(int pos) const{

}

// find max of node pos
int BST::tree_man(int pos) const{

}

void BST::tree_print() const{


}
