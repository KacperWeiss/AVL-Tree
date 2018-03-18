#ifndef AVL_TREE
#define AVL_TREE

#include <iostream>
#include "node.hpp"

template <class T>
class AVL_Tree {

    private:
    
        // Variable solely for test purposes
        int nodeCount;

        // Private method called first by contains(T value) public method
        // is used to validate if value already exists in the tree:
        // - if value doesn't exist in the tree it returns false
        // - if value already exists in the tree returns true
        bool contains(Node<T>* node, T value);

        // Private method called first by insert(T value) public method
        // is used to insert new Node with data to suitable place
        // then it uses private methods update(node) and rebalance(node),
        // which updates height and balancefactor of every node in path
        // to newly created node and if necessary rebalance tree so it
        // fulfills the dependence of AVL Tree
        // - it returns root of the tree
        Node<T>* insert(Node<T>* node, T value); 

        // Private method that's used to update height and bf values
        // of the node.
        // - it returns nothing
        void update(Node<T>* node);

        // Private method that decides if node needs to be rebalanced
        // if so, it calls one of the functions:
        // -> leftLeftCase(Node<T>* node) if node's balance factor is 
        //    equal to -2, and it's left child have bf less or equal to 0
        // -> leftRightCase(Node<T>* node) if node's balance factor is 
        //    equal to -2, and it's left child have bf greater than 0
        // -> rightLeftCase(Node<T>* node) if node's balance factor is 
        //    equal to 2, and it's right child have bf less or equal to 0
        // -> rightRightCase(Node<T>* node) if node's balance factor is 
        //    equal to 2, and it's right child have bf greater than 0
        // after operation node is balanced and method returns node that
        // should be placed in position of node that required rebalance.
        // - it returns node that should be in this place of the tree
        Node<T>* rebalance(Node<T>* node);

        // Private method called by rebalance(Node<T>* node) private method
        // it represents operations that need to be done in order to rebalance
        // the node. In this case it rotates right.
        // - returns left node in place of parent with parent on right ptr
        Node<T>* leftLeftCase(Node<T>* node);

        // Private method called by rebalance(Node<T>* node) private method
        // it represents operations that need to be done in order to rebalance
        // the node. In this case it rotates right.
        // - returns left node in place of parent with old parent on right ptr
        Node<T>* leftRightCase(Node<T>* node);

        // Private method called by rebalance(Node<T>* node) private method
        // it represents operations that need to be done in order to rebalance
        // the node. In this case it's right child rotates right, and then it calls
        // rightRightCase(Node<T>* node) on return
        // - returns rightRightCase(Node<T>* node) result
        Node<T>* rightLeftCase(Node<T>* node);

        // Private method called by rebalance(Node<T>* node) private method
        // it represents operations that need to be done in order to rebalance
        // the node. In this case it rotates left.
        // - returns right node in place of parent with parent on left ptr
        Node<T>* rightRightCase(Node<T>* node);

        // Private method called by methods that handle rebalance cases.
        // It replaces parent node with it's left node, then new parent's
        // right child node becomes left node of the old parent and at the
        // end old parent becomes right child of new parent node. After that
        // new child and parent nodes are both updated with new height and 
        // balance factor values
        // - returns new parent node 
        Node<T>* rightRotation(Node<T>* node);

        // Private method called by methods that handle rebalance cases.
        // It replaces parent node with it's right node, then new parent's
        // left child node becomes right node of the old parent and at the
        // end old parent becomes left child of new parent node. After that
        // new child and parent nodes are both updated with new height and 
        // balance factor values
        // - returns new parent node
        Node<T>* leftRotation(Node<T>* node);

        // Private method called first by deleteValue(T value) public method
        // is used to delete existing nodes and then rearange AVL_Tree back
        // to balance by using private methods update(node) and rebalance(node)
        // which updates height and balancefactor of every node affected by
        // removal of selected value.
        // - returns root of the tree
        Node<T>* deleteValue(Node<T>* node, T value);

    public:

        // Constructor creates new AVL_Tree with it's root set to null
        AVL_Tree(): root(NULL) {}

        // Destructor for AVL Tree - it destructs all of the nodes by recursion
        ~AVL_Tree(){ delete root; }

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

        // Public method that removes node with selected value. First it validate if
        // value which has to be removed is not null, then it validates if value exists
        // in the tree. If value exists, then private method deleteValue(Node<T> node, T value)
        // is called and it decrements nodeCount value:
        // - if value does not exists in the tree, or value is null it returns false
        // - if value exist in the tree it returns true once value is removed
        bool deleteValue(T value);

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

    auto comparable = value - node->data;

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
    return rebalance();
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

};

template <class T>
Node<T>* AVL_Tree<T>::leftRightCase(Node<T>* node){

    node->left = leftRotation(node->left);
    return leftLeftCase(node);

};

template <class T>
Node<T>* AVL_Tree<T>::rightLeftCase(Node<T>* node){

    node->right = rightRotation(node->right);
    return rightRightCase(node);

};

template <class T>
Node<T>* AVL_Tree<T>::rightRightCase(Node<T>* node){

    return leftRotation(node);

};

template <class T>
Node<T>* AVL_Tree<T>::rightRotation(Node<T>* node){

    Node<T>* newParent = node->left;
    node->left = newParent->right;
    newParent->right = node;
    update(node);
    update(newParent);
    return newParent;

};

template <class T>
Node<T>* AVL_Tree<T>::leftRotation(Node<T>* node){

    Node<T>* newParent = node->right;
    node->right = newParent->left;
    newParent->left = node;
    update(node);
    update(newParent);
    return newParent;    

};

template <class T>
bool AVL_Tree<T>::deleteValue(T value){

    if(value == NULL)
        return false;

    if(contains(root, value)){
        root = deleteValue(root, value);
        nodeCount--;
        return true;
    }
    
    return false;
};

#endif