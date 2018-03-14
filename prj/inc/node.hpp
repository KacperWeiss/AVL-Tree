#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template <class T>
class Node{
    private:

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
        Node(T value): data(value) {}
};

#endif