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
        // - if value doesn't exist in the tree it returns false
        // - if value already exists in the tree returns true
        bool contains(Node<T>* node, T value);

        // Private method called by insert(T value) public method
        Node<T>* insert(Node<T>* node, T value); 
    public:

        // Root node of the AVL_Tree
        Node<T>* root;

        // Method for test purposes, it returns height of the tree
        int height(){

            if(root == NULL)
                return 0;

            return root->height;

        }

        // Method for test purposes, it returns size of the tree
        int size(){
            return nodeCount;
        }

        // Public method calls contains(Node<T>* node, T value) private method
        // in order to always start searching for a value in root node:
        // - if value doesn't exist in the tree it returns false
        // - if value already exists in the tree returns true
        bool contains(T value);

        // Public method that inserts value to the AVL tree. First it validate 
        // if given value already exists in the tree. If not method calls 
        // private method insert(Node<T>* node, T value) and increments nodeCount:
        // - if value already exists in the tree, or value is null it returns false
        // - if value doesn't exist in the tree it returns true
        bool insert(T value);

};

template <class T>
bool AVL_Tree<T>::contains(Node<T>* node, T value){

    if(node == NULL)
        return false;

    T comparable = value - node->data;

    if(comparable < 0)
        return contains(node->left, value);

    if(comparable > 0)
        return contains(node->right, value);
    
    return true;

};

template <class T>
bool AVL_Tree<T>::contains(T value){
    return contains(root, value);
};

template <class T>
Node<T>* AVL_Tree<T>::insert(Node<T>* node, T value){

    if(node == NULL)
        return new Node<T>(value);

    T comparable = value - node->data;

    if(comparable < 0)
        node->left = insert(node->left, value);

    else
        node->right = insert(node->right, value);

    // some functions that will be added soon:
    // update();
    // return reBalance();
};

template <class T>
bool AVL_Tree<T>::insert(T value){

    if(value == NULL)
        return false;

    if(!contains(root, value)){
        root = insert(root, value);
        nodeCount++;
        return true;
    }

    return false;
};

#endif