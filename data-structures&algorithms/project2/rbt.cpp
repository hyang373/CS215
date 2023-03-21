/*
 * File: rbt.cpp
 * Cousre: CS 315
 * Project: Problem Set 2
 * Purpose: Provide the declarations of the class named rbt
 *
 */

#include "rbt.h"
#include <iostream>
using namespace std;

// default constructor
RBT::RBT(){
        root = NULL;
}

// insert value into tree
void RBT::RB_insert(node_one*& Root, int value){
        // create a new node for value
        node_one *new_node = new node_one;
        new_node->key = value;
        new_node->left = new_node->right = NULL;
        new_node->parent = NULL;
        new_node->color = "RED";

        node_one *y = NULL;
        node_one *x = root;
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
        new_node->left = NULL;

        RB_insertFixup(root, new_node);

        Root = root;
}

void RBT::RB_insertFixup(node_one*& Root,node_one*& Node){
        while(Node->parent->color == "RED"){
                if(Node->parent == Node->parent->parent->left){
                        node_one *y = Node->parent->parent->right;
                        if(y->color == "RED"){
                                Node->parent->color = "BLACK";
                                y->color = "BLACK";
                                z->parent->parent->color = "RED";
                                Node = Node->parent->parent;
                        }
                        else{
                                if(Node == Node->parent->right){
                                        Node = Node->parent;
                                        left_rotate(root, Node);
                                }
                                Node->parent->color = "BLACK";
                                Node->parent->parent->color = "RED";
                                right_rotate(root, Node);

                        }
                }
                else{
                        node_one *y = Node->parent->parent->right;
                        if(y->color == "RED"){
                                Node->parent->color = "BLACK";
                                y->color = "BLACK";
                                z->parent->parent->color = "RED";
                                Node = Node->parent->parent;
                        }
                        else{
                                if(Node == Node->parent->right){
                                        Node = Node->parent;
                                        right_rotate(root, Node);
                                }
                                Node->parent->color = "BLACK";
                                Node->parent->parent->color = "RED";
                                left_rotate(root, Node);
                        }
                }
        }
        root->color = "BLACK";
        Root = root;

}
void RST::left_rotate(node_one*& Root, node_one*& Node){
        node_one *y = Node->right;
        Node->right = y->left;
        if(y->left != NULL){
                y->left->parent = Node;
        }
        y->parent = Node->parent;
        if(Node->parent == NULL){
                root = y;
        }
        else if(Node == Node->parent->left){
                Node->parent->left = y;
        }
        else{
                Node->parent->right = y;
        }
        y->left = Node;
        Node->parent = y;
        Root = root;
}
void RST::right_rotate(node_one*& Root, node_one*& Node){
        node_one *y = Node->left;
        Node->left = y->right;
        if(y->right != NULL){
                y->right->parent = Node;
        }
        y->parent = Node->parent;
        if(Node->parent == NULL){
                root = y;
        }
        else if(Node == Node->parent->right){
                Node->parent->right = y;
        }
        else{
                Node->parent->left = y;
        }
        y->right = Node;
        Node->parent = y;
        Root = root;
}

// delete a value from trree
void RBT::RB_delete(node_one*& Root, int value){
        // search for the node to delete
        node_one *del_node = RB_search(root, value);

        node_one *y = del_node; // y = successor
        string y_orgColor = y->color;
        node_one *x;

        if(del_node->left == NULL){
                x = del_node->right;
                transplant(root, del_node, del_node->right);
        }
        else if(del_node->right == NULL){
                x = del_node->left;
                transplant(root, del_node, del_node->left);
        }
        else{
                y = RB_min(del_node->right);
                y_orgColor = y->color;
                x = y->right;

                if(y->parent == del_node){
                        x->parent = y;
                }
                else{
                        RB_transplant(root, y, y->right);
                        y->right = del_node->right;
                        y->right->parent = y;
                }
                RB_transplant(root, del_node, y);
                y->left = del_node->left;
                y->left->parent = y;
                y->color = del_node->color;
        }
        if(y_orgColor == "BLACK"){
                RB_deleteFixup(root, x);
        }
        Root = root;

}

node_one* RBT::RB_search(node_one* Root, int value) const{
        if(Root == NULL || Root->key == value){
                return Root;
        }
        if(value < Root->key){
                return RB_search(Root->left, value);
        }
        else{
                return RB_search(Root->right, value);
        }
}

void RBT::transplant(node_one*& Root, node_one*& num1, node_one*& num2){
        if(num1->parent == NULL){
                root = num2;
        }
        else if(num1 == num1->parent->left){
                num1->parent->left = num2;
        }
        else{
                num1->parent->right = num2;
        }
        num2->parent = num1->parent;
        Root = root;
}

// find min of node pos
node_one* RBT::RB_min(node_one* pos){
        while(pos->left != NULL){
                pos = pos->left;
        }
        return pos;
}

// find max of node pos
node_one* RBT::RB_max(node_one* pos){
        while(pos->right != NULL){
                pos = pos->right;
        }
        return pos;
}

void RBT::RB_deleteFixup(node_one*& Root, node_one*& Node){
        while((Node->parent != NULL) && (Node->color == "BLACK")){
                node_one *w;
                if(Node == Node->parent->left){
                        w = Node->parent->right;
                        if(w->color == "RED"){
                                w->color = "BLACK";
                                Node->parent->color = "RED";
                                left_rotate(root, Node->parent);
                                w = Node->parent->right;
                        }
                        if((w->left->color == "BLACK")&&(w->right->color == "BLACK")){
                                w->color == "RED";
                                Node = Node->parent;
                        }
                        else{
                                if(w->right->color == "BLACK"){
                                        w->left->color = "BLACK";
                                        w->color = "RED";
                                        right_rotate(root, w);
                                        w = Node->parent->right;
                                }
                                w->color = Node->parent->color;
                                Node->parent->color = "BLACK";
                                left_rotate(root, Node->parent);
                                Node = root;
                        }
                }
                else{
                        w = Node->parent->left;
                        if(w->color == "RED"){
                                w->color = "BLACK";
                                Node->parent->color = "RED";
                                right_rotate(root, Node->parent);
                                w = Node->parent->left;
                        }
                        if((w->right->color == "BLACK")&&(w->left->color == "BLACK")){
                                w->color == "RED";
                                Node = Node->parent;
                        }
                        else{
                                if(w->left->color == "BLACK"){
                                        w->right->color = "BLACK";
                                        w->color = "RED";
                                        left_rotate(root, w);
                                        w = Node->parent->left;
                                }
                                w->color = Node->parent->color;
                                Node->parent->color = "BLACK";
                                right_rotate(root, Node->parent);
                                Node = root;
                        }
                }
        }
        Node->color = "BLACK";
        Root = root;
}


void RBT::RB_walk(node_one* Node) const{
        if(Node != NULL){
                RB_walk(Node->left);
                cout << Node->key << " ";
                RB_walk(Node->right);
        }
}

int RBT::RB_height(node_one* Node){
        if(Node == NULL){
                return 1;
        }
        else{
                int left_height = 1 + RB_height(Node->left);
                int right_height = 1 + RB_height(Node->right);
                if(left_height > right_height){
                        return left_height;
                }
                else{
                        return right_height;
                }
        }
}
