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
        // is used to insert new Node with data to suitable place
        // then it uses private methods update(node) and rebalance(node),
        // which updates height and balancefactor of every node in path
        // to newly created node and if necessary rebalance tree so it
        // fulfills the dependence of AVL Tree
        // - it returns root of the tree
        Node<T>* insert(Node<T>* node, T value); 

        void update(Node<T>* node);

        Node<T>* rebalance(Node<T>* node);

        Node<T>* leftLeftCase(Node<T>* node);

        Node<T>* leftRightCase(Node<T>* node);

        Node<T>* rightLeftCase(Node<T>* node);

        Node<T>* rightRightCase(Node<T>* node);

        Node<T>* leftRotation(Node<T>* node);

        Node<T>* rightRotation(Node<T>* node);

    public:

        // Root node of the AVL_Tree
        Node<T>* root;

        // Method for test purposes, it returns height of the tree
        int height();

        // Method for test purposes, it returns size of the tree
        int size();

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
int AVL_Tree<T>::height(){

    if(root == NULL)
        return 0;

    return root->height;

};

template <class T>
int AVL_Tree<T>::size(){
    return nodeCount;
}

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

    update();
    // return rebalance();
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

template <class T>
void AVL_Tree<T>::update(Node<T>* node){

    int leftNodeHeight = (node->left == NULL) ? 0 : node->left->height;
    int rightNodeHeight = (node->right == NULL) ? 0 : node->right->height;
    int higher = (leftNodeHeight > rightNodeHeight) ? leftNodeHeight : rightNodeHeight;

    node->height = 1 + higher;

    node->bf = leftNodeHeight - rightNodeHeight;

};

template <class T>
Node<T>* AVL_Tree<T>::rebalance(Node<T>* node){

    if(node->bf == -2){

        if(node->left->bf <= 0)
            return leftLeftCase(node);

        else
            return leftRightCase(node);

    }
    if(node->bf == 2){

        if(node->right->bf >= 0)
            return rightLeftCase(node);

        else
            return rightRightCase(node);

    }

    return node;

};

template <class T>
Node<T>* AVL_Tree<T>::leftLeftCase(Node<T>* node){

    return rightRotation(node);

}

template <class T>
Node<T>* AVL_Tree<T>::leftRightCase(Node<T>* node){
    
    node->left = leftRotation(node->left);
    return leftLeftCase(node);
    
}

template <class T>
Node<T>* AVL_Tree<T>::rightLeftCase(Node<T>* node){
    


}

template <class T>
Node<T>* AVL_Tree<T>::rightRightCase(Node<T>* node){
    


}

template <class T>
Node<T>* AVL_Tree<T>::leftRotation(Node<T>* node){
    


}

template <class T>
Node<T>* AVL_Tree<T>::rightRotation(Node<T>* node){
    


}



#endif