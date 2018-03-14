#ifndef AVL_TREE
#define AVL_TREE

#include <iostream>
#include "node.hpp"

template <class T>
class AVL_Tree {

    private:
    
        // Variable solely for test purposes
        int nodeCount;

        // Private method called by contains(T value) public method
        // is used to validate if value already exists in the tree:
        // - if value doesn't exist in a tree it returns false
        // - if value already exists in a tree returns true
        bool contains(Node<T>* node, T value);

    public:

        // Root node of the AVL_Tree
        Node<T> root;

        // Method for test purposes, it returns height of the tree
        int height(){

            if(root == NULL)
                return 0;

            return root.height;

        }

        // Method for test purposes, it returns size of the tree
        int size(){
            return nodeCount;
        }

        // Public method calls contains(Node<T>* node, T value) private method
        // in order to always start searching for a value in root node:
        // - if value doesn't exist in a tree it returns false
        // - if value already exists in a tree returns true
        bool contains(T value);

};

template <class T>
bool AVL_Tree<T>::contains(Node<T>* node, T value){

    if(node == NULL)
        return false;

    int comparable = value - node->data;

    if(comparable < 0)
        return contains(node->left, value);

    if(comparable > 0)
        return contains(node->right, value);
    
    return true;

};

template <class T>
bool AVL_Tree<T>::contains(T value){
    return contains(root, value);
}


#endif