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
BST::BST(){
        root->key = 0;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
}

// insert value into tree
void BST::tree_insert(node*& Root, int value){
        // create a new node for value
        node *new_node;
        new_node->key = value;
        new_node->left = new_node->right = NULL;
        new_node->parent = NULL;

        node *y = NULL;
        node *x = root;
        // traversal through the tree
        while(x->key > 0){
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
                y->left = new_node;
        }
        else{
                y->right = new_node;
        }
        Root = root;
}

// delete a value from trree
void BST::tree_delete(node*& Root, int value){
        // create a new node for value
        node *new_node;
        new_node->key = value;
        new_node->left = new_node->right = NULL;
        new_node->parent = NULL;

        if(new_node->left == NULL){
                transplant(root, new_node, new_node->right);
        }
        else if(new_node->right == NULL){
                transplant(root, new_node, new_node->left);
        }
        else{
                node* y = tree_min(new_node->right);
                if(y->parent != new_node){
                        transplant(root, y, y->right);
                        y->right = new_node->right;
                        y->right->parent = y;
                }
                transplant(root, new_node, y);
                y->left = new_node->left;
                y->left->parent = y;
        }

        Root = root;

}

void BST::transplant(node*& Root, node*& num1, node*& num2){
        if(num1->parent == NULL){
                root = num2;
        }
        else if(num1 == num1->parent->left){
                num1->parent->left = num2;
        }
        else{
                num1->parent->right = num2;
        }
        if(num2 != NULL){
                num2->parent = num1->parent;
        }
        Root = root;
}

// find min of node pos
node* BST::tree_min(node* pos){
        while(pos->left != NULL){
                pos = pos->left;
        }
        return pos;
}

// find max of node pos
node* BST::tree_man(node* pos){
        while(pos->right != NULL){
                pos = pos->right;
        }
        return pos;
}

void BST::tree_walk(node* Node) const{
        if(Node != NULL){
                tree_walk(Node->left);
                cout << Node->key << " ";
                tree_walk(Node->right);
        }
        cout << endl;
}
