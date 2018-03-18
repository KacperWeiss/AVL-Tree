#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template <class T>
class Node{
    
    public:

        // Comparable data contained in this node
        T data;

        // Pointer for left and right nodes 
        Node* left, right;

        // Balance factor
        int bf;

        // Height of this node in the tree
        int height;

    public:
        // Public constructor for creating new nodes
        // It assigns value to new node and sets pointers to NUll, bf and height to 0
        Node(T value): data(value), left(NULL), right(NULL), height(0), bf(0) {}

        // To avoid memory leaks, destructor deletes object's left and right nodes
        ~Node(){
            delete left;
            delete right;
        }
};

#endif