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
        root = NULL;
}

// insert value into tree
void BST::tree_insert(node*& Root, int value){
        // create a new node for value
        node *new_node = new node;
        new_node->key = value;
        new_node->left = new_node->right = NULL;
        new_node->parent = NULL;

        node *y = NULL;
        node *x = root;
        // traversal through the tree
        while((x != NULL) && (x->key > 0)){
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
        // search for the node to delete
        node *del_node = tree_search(root, value);

        if(del_node->left == NULL){
                transplant(root, del_node, del_node->right);
        }
        else if(del_node->right == NULL){
                transplant(root, del_node, del_node->left);
        }
        else{
                node* successor = tree_min(del_node->right);
                if(successor->parent != del_node){
                        transplant(root, successor, successor->right);
                        successor->right = del_node->right;
                        successor->right->parent = successor;
                }
                transplant(root, del_node, successor);
                successor->left = del_node->left;
                successor->left->parent = successor;
        }

        Root = root;

}

node* BST::tree_search(node* Root, int value) const{
        if(Root == NULL || Root->key == value){
                return Root;
        }
        if(value < Root->key){
                return tree_search(Root->left, value);
        }
        else{
                return tree_search(Root->right, value);
        }
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
node* BST::tree_max(node* pos){
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
}

int BST::tree_height(node* Node){
        if(Node == NULL){
                return 1;
        }
        else{
                int left_height = 1 + tree_height(Node->left);
                int right_height = 1 + tree_height(Node->right);
                if(left_height > right_height){
                        return left_height;
                }
                else{
                        return right_height;
                }
        }
}
