#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template <class T>
class Node{
    
    public:

        // Public constructor for creating new nodes
        // It assigns value to new node and sets pointers to NUll, bf to 0 and height to 1
        Node(T value): data(value), left(NULL), right(NULL), bf(0), height(1) {}

        // To avoid memory leaks, destructor deletes object's left and right nodes
        ~Node(){ delete left; delete right; }

        // Comparable data contained in this node
        T data;

        // Pointers for left and right nodes 
        Node* left;
        Node* right;

        // Balance factor
        int bf;

        // Height of this node in the tree
        int height;

};

#endif