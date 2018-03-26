#ifndef AVL_TREE
#define AVL_TREE

/*!
 * \file AVL_Tree.hpp
 * 
 * This file contains template class AVL_Tree, it's constructor, destructor,
 * properties and methods.
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <typeinfo>
#include "node.hpp"
#include "logger.hpp"

/*!
 * \brief AVL Tree class
 * 
 * Class that represents algorithm of AVL Tree. It contains pointer to root Node,
 * node count, and methods to work with AVL Nodes/Trees
 */
template <class T>
class AVL_Tree {

    private:

        /*! Root node of the AVL_Tree */
        Node<T>* root;

        /*! Logger for AVL_Tree */
        Logger logger;
    
        /*! Variable solely for test purposes */
        int nodeCount;

        /*! 
         * \brief Private method that checks if tree contain given value in given node
         * 
         * Private method called first by contains(T value) public method
         * is used to validate if value already exists in the tree:
         * - if value doesn't exist in the tree it returns false
         * - if value already exists in the tree returns true 
         * \param node - current node
         * \param value - value that program searches for
         */
        bool contains(Node<T>* node, T value);


        /*! 
         * \brief Private method that inserts given value
         * 
         * Private method called first by insert(T value) public method
         * is used to insert new Node with data to suitable place
         * then it uses private methods update(node) and rebalance(node),
         * which updates height and balancefactor of every node in path
         * to newly created node and if necessary rebalance tree so it
         * fulfills the dependence of AVL Tree
         * - it returns root of the tree 
         * \param node - current node
         * \param value - value that program inserts
         */
        Node<T>* insert(Node<T>* node, T value); 

        /*! 
         * \brief Private method that updates information inside given node
         * 
         * Private method that's used to update height and bf values
         * of the node.
         * - it returns nothing 
         * \param node - current node
         */
        void update(Node<T>* node);

        /*! 
         * \brief Private method that rebalances the tree in given node if necessary
         * 
         * Private method that decides if node needs to be rebalanced
         * if so, it calls one of the functions: 
         * -> leftLeftCase(Node<T>* node) if node's balance factor is  
         *    equal to -2, and it's left child have bf less or equal to 0 
         * -> leftRightCase(Node<T>* node) if node's balance factor is  
         *    equal to -2, and it's left child have bf greater than 0 
         * -> rightLeftCase(Node<T>* node) if node's balance factor is 
         *    equal to 2, and it's right child have bf less or equal to 0
         * -> rightRightCase(Node<T>* node) if node's balance factor is 
         *    equal to 2, and it's right child have bf greater than 0
         * after operation node is balanced and method returns node that
         * should be placed in position of node that required rebalance.
         * - it returns node that should be in this place of the tree
         * \param node - current node
         */ 
        Node<T>* rebalance(Node<T>* node);

        /*! 
         * \brief Private method for LL case
         * 
         * Private method called by rebalance(Node<T>* node) private method
         * it represents operations that need to be done in order to rebalance
         * the node. In this case it rotates right.
         * - returns left node in place of parent with parent on right ptr
         * \param node - current node
         */
        Node<T>* leftLeftCase(Node<T>* node);

        /*! 
         * \brief Private method for LR case
         * 
         * Private method called by rebalance(Node<T>* node) private method 
         * it represents operations that need to be done in order to rebalance 
         * the node. In this case it rotates right. 
         * - returns left node in place of parent with old parent on right ptr 
         * \param node - current node
         */
        Node<T>* leftRightCase(Node<T>* node);

        /*! 
         * \brief Private method for RL case
         * 
         * Private method called by rebalance(Node<T>* node) private method 
         * it represents operations that need to be done in order to rebalance
         * the node. In this case it's right child rotates right, and then it calls
         * rightRightCase(Node<T>* node) on return
         * - returns rightRightCase(Node<T>* node) result 
         * \param node - current node
         */
        Node<T>* rightLeftCase(Node<T>* node);

        /*! 
         * \brief Private method for RR case
         * 
         * Private method called by rebalance(Node<T>* node) private method 
         * it represents operations that need to be done in order to rebalance 
         * the node. In this case it rotates left. 
         * - returns right node in place of parent with parent on left ptr 
         * \param node - current node
         */
        Node<T>* rightRightCase(Node<T>* node);

        /*! 
         * \brief Private method that rotates tree to the right
         * 
         * Private method called by methods that handle rebalance cases. 
         * It replaces parent node with it's left node, then new parent's 
         * right child node becomes left node of the old parent and at the 
         * end old parent becomes right child of new parent node. After that 
         * new child and parent nodes are both updated with new height and  
         * balance factor values 
         * - returns new parent node  
         * \param node - current node
         */
        Node<T>* rightRotation(Node<T>* node);

        /*! 
         * \brief Private method that rotates tree to the left
         * 
         * Private method called by methods that handle rebalance cases. 
         * It replaces parent node with it's right node, then new parent's 
         * left child node becomes right node of the old parent and at the 
         * end old parent becomes left child of new parent node. After that 
         * new child and parent nodes are both updated with new height and  
         * balance factor values 
         * - returns new parent node 
         * \param node - current node
         */
        Node<T>* leftRotation(Node<T>* node);

        /*! 
         * \brief Private method that deletes node from the tree
         * 
         * Private method called first by deleteValue(T value) public method 
         * is used to delete existing nodes and then rearange AVL_Tree back 
         * to balance by using private methods update(node) and rebalance(node) 
         * which updates height and balancefactor of every node affected by 
         * removal of selected value. 
         * - returns root of the tree 
         * \param node - current node
         * \param value - value to delete
         */
        Node<T>* deleteValue(Node<T>* node, T value);
        

        /*!
         * \brief Private method to print tree pre order
         * 
         * Private method called by printTreePreOrder() public method is used
         * to "print" tree to console in chosen order.
         * - returns true if printed correctly
         * - returns false if node is null
         * \param node - current node
         */ 
        bool printTreePreOrder(Node<T>* node);

        /*!
         * \brief Private method to print tree in order
         * 
         * Private method called by printTreeInOrder() public method is used
         * to "print" tree to console in chosen order.
         * - returns true if printed correctly
         * - returns false if node is null
         * \param node - current node
         */ 
        bool printTreeInOrder(Node<T>* node);

        /*!
         * \brief Private method to print tree post order
         * 
         * Private method called by printTreePostOrder() public method is used
         * to "print" tree to console in chosen order.
         * - returns true if printed correctly
         * - returns false if node is null
         * \param node - current node
         */ 
        bool printTreePostOrder(Node<T>* node);

    public:

        /*! Constructor creates new AVL_Tree with it's root set to null */
        AVL_Tree(std::string logFileName = "defaultLogsFile.txt"): root(NULL), logger(logFileName), nodeCount(0) {}

        /*! Destructor for AVL Tree - it destructs all of the nodes by recursion */
        ~AVL_Tree(){ delete root; }

        /*! Method for test purposes, it returns height of the tree */
        int height();

        /*! Method for test purposes, it returns size of the tree */
        int size();

        /*! Public method calls contains(Node<T>* node, T value) private method 
         * in order to always start searching for a value in root node: 
         * - if value doesn't exist in the tree it returns false 
         * - if value already exists in the tree returns true 
         * \param value - value that program will search in the tree
         */
        bool contains(T value);

        /*! Public method that inserts value to the AVL tree. First it validate 
         * if given value already exists in the tree. If not method calls 
         * private method insert(Node<T>* node, T value) and increments nodeCount:
         * - if value already exists in the tree, or value is null it returns false 
         * - if value doesn't exist in the tree it returns true 
         * \param value - value that program inserts
         */
        bool insert(T value);

        /*! Public method that removes node with selected value. First it validate if 
         * value which has to be removed is not null, then it validates if value exists 
         * in the tree. If value exists, then private method deleteValue(Node<T> node, T value) 
         * is called and it decrements nodeCount value: 
         * - if value does not exists in the tree, or value is null it returns false 
         * - if value exist in the tree it returns true once value is removed 
         * \param value - value to delete
         */
        bool deleteValue(T value);

        /*! 
         * \brief Public method that shows tree structure 
         * 
         * Public method that calls private method printTreeOrder(Node<T>* node)
         * if root exists.
         * - returns false if root is null
         * - returns status of called method (true or false)
         */
        bool printTreePreOrder();

        /*! 
         * \brief Public method that shows tree structure 
         * 
         * Public method that calls private method printTreeOrder(Node<T>* node)
         * if root exists.
         * - returns false if root is null
         * - returns status of called method (true or false)
         */
        bool printTreeInOrder();

        /*! 
         * \brief Public method that shows tree structure 
         * 
         * Public method that calls private method printTreeOrder(Node<T>* node)
         * if root exists.
         * - returns false if root is null
         * - returns status of called method (true or false)
         */
        bool printTreePostOrder();

};

template <class T>
int AVL_Tree<T>::height(){

    if(root == NULL)
        return 0;

    return root->height;

}

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

}

template <>
bool AVL_Tree<std::string>::contains(Node<std::string>* node, std::string value){

    if(node == NULL)
        return false;

    std::string tempV = value;
    std::string tempND = node->data;

    std::transform(tempV.begin(), tempV.end(), tempV.begin(), ::tolower);
    std::transform(tempND.begin(), tempND.end(), tempND.begin(), ::tolower);    

    if(tempV < tempND)
        return contains(node->left, value);

    if(tempV > tempND)
        return contains(node->right, value);

    return true;
}

template <class T>
bool AVL_Tree<T>::contains(T value){

    return contains(root, value);

}

template <class T>
Node<T>* AVL_Tree<T>::insert(Node<T>* node, T value){

    if(node == NULL)
        return new Node<T>(value);

    auto comparable = value - node->data;

    if(comparable < 0)
        node->left = insert(node->left, value);

    else
        node->right = insert(node->right, value);

    update(node);
    return rebalance(node);

}

template<>
Node<std::string>* AVL_Tree<std::string>::insert(Node<std::string>* node, std::string value){

    if(node == NULL)
        return new Node<std::string>(value);

    std::string tempV = value;
    std::string tempND = node->data;

    std::transform(tempV.begin(), tempV.end(), tempV.begin(), ::tolower);
    std::transform(tempND.begin(), tempND.end(), tempND.begin(), ::tolower);    

    if(tempV < tempND)
        node->left = insert(node->left, value);

    else
        node->right = insert(node->right, value);

    update(node);
    return rebalance(node);

}

template <class T>
bool AVL_Tree<T>::insert(T value){

    if(value == NULL){

        logger.logToFile("insert -> Passed value == null.");
        return false;

    }

    if(!contains(root, value)){
        root = insert(root, value);
        nodeCount++;
        return true;
    }

    logger.logToFile("insert -> Passed value already exist in the tree.");
    return false;

}

template <>
bool AVL_Tree<std::string>::insert(std::string value){

    if(value.empty()){

        logger.logToFile("insert -> Passed string is empty.");
        return false;

    }

    if(!contains(root, value)){
        root = insert(root, value);
        nodeCount++;
        return true;
    }

    logger.logToFile("insert -> Passed string already exist in the tree.");
    return false;

}

template <class T>
void AVL_Tree<T>::update(Node<T>* node){

    int leftNodeHeight = (node->left == NULL) ? 0 : node->left->height;
    int rightNodeHeight = (node->right == NULL) ? 0 : node->right->height;
    int higher = (leftNodeHeight > rightNodeHeight) ? leftNodeHeight : rightNodeHeight;

    node->height = 1 + higher;

    node->bf = rightNodeHeight - leftNodeHeight;

}

template <class T>
Node<T>* AVL_Tree<T>::rebalance(Node<T>* node){

    if(node->bf == -2){

        if(node->left->bf <= 0)
            return leftLeftCase(node);

        else
            return leftRightCase(node);

    }
    if(node->bf == 2){

        if(node->right->bf <= 0)
            return rightLeftCase(node);

        else
            return rightRightCase(node);

    }

    return node;

}

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

    node->right = rightRotation(node->right);
    return rightRightCase(node);

}

template <class T>
Node<T>* AVL_Tree<T>::rightRightCase(Node<T>* node){

    return leftRotation(node);

}

template <class T>
Node<T>* AVL_Tree<T>::rightRotation(Node<T>* node){

    Node<T>* newParent = node->left;
    node->left = newParent->right;
    newParent->right = node;
    update(node);
    update(newParent);
    return newParent;

}

template <class T>
Node<T>* AVL_Tree<T>::leftRotation(Node<T>* node){

    Node<T>* newParent = node->right;
    node->right = newParent->left;
    newParent->left = node;
    update(node);
    update(newParent);
    return newParent;    

}

template <class T>
Node<T>* AVL_Tree<T>::deleteValue(Node<T>* node, T value){

    if(node == NULL)
        return NULL;

    auto comparable = value - node->data;

    if(comparable < 0)
        node->left = deleteValue(node->left, value);

    else if(comparable > 0)
        node->right = deleteValue(node->right, value);

    else{

        if(node->left == NULL && node->right == NULL){

            delete node;
            return NULL;

        }

        if(node->bf >= 0){
            
            Node<T>* temporaryNodePtr = node->right;
            T replacedNodeData = temporaryNodePtr->data;

            while(temporaryNodePtr->left != NULL){

                temporaryNodePtr = temporaryNodePtr->left;
                replacedNodeData = temporaryNodePtr->data;

            }

            node->right = deleteValue(node->right, replacedNodeData);

        } else {

            Node<T>* temporaryNodePtr = node->left;
            T replacedNodeData = temporaryNodePtr->data;

            while(temporaryNodePtr->right != NULL){

                temporaryNodePtr = temporaryNodePtr->right;
                replacedNodeData = temporaryNodePtr->data;

            }

            node->left = deleteValue(node->left, replacedNodeData);

        }

    }

    update(node);

    return rebalance(node);

}

template <>
Node<std::string>* AVL_Tree<std::string>::deleteValue(Node<std::string>* node, std::string value){

    if(node == NULL)
        return NULL;

    std::string tempV = value;
    std::string tempND = node->data;

    std::transform(tempV.begin(), tempV.end(), tempV.begin(), ::tolower);
    std::transform(tempND.begin(), tempND.end(), tempND.begin(), ::tolower);    

    if(tempV < tempND)
        node->left = deleteValue(node->left, value);

    else if(tempV > tempND)
        node->right = deleteValue(node->right, value);

    else{
        
        if(node->left == NULL && node->right == NULL){

            delete node;
            return NULL;

        }

        if(node->bf >= 0){
            
            Node<std::string>* temporaryNodePtr = node->right;
            std::string replacedNodeData = temporaryNodePtr->data;

            while(temporaryNodePtr->left != NULL){

                temporaryNodePtr = temporaryNodePtr->left;
                replacedNodeData = temporaryNodePtr->data;

            }

            node->right = deleteValue(node->right, replacedNodeData);

        } else {

            Node<std::string>* temporaryNodePtr = node->left;
            std::string replacedNodeData = temporaryNodePtr->data;

            while(temporaryNodePtr->right != NULL){

                temporaryNodePtr = temporaryNodePtr->right;
                replacedNodeData = temporaryNodePtr->data;

            }

            node->left = deleteValue(node->left, replacedNodeData);

        }

    }

    update(node);

    return rebalance(node);

}

template <class T>
bool AVL_Tree<T>::deleteValue(T value){

    if(value == NULL){

        logger.logToFile("deleteValue -> Passed value == null.");
        return false;

    }

    if(contains(root, value)){
        root = deleteValue(root, value);
        nodeCount--;
        return true;
    }
    
    logger.logToFile("deleteValue -> Passed value does not exist in the tree.");
    return false;
    
}

template <>
bool AVL_Tree<std::string>::deleteValue(std::string value){

    if(value.empty()){

        logger.logToFile("deleteValue -> Passed string is empty.");
        return false;

    }

    if(contains(root, value)){
        root = deleteValue(root, value);
        nodeCount--;
        return true;
    }
    
    logger.logToFile("deleteValue -> Passed string does not exist in the tree.");
    return false;
    
}

template <class T>
bool AVL_Tree<T>::printTreePreOrder(){

    if(root == NULL)
        return false;

    return printTreePreOrder(root);

}

template <class T>
bool AVL_Tree<T>::printTreePreOrder(Node<T>* node){

    if(node == NULL)
        return false;

    for(int i = 0; i < node->height; i++){
        std::cout << "   ";
    }
    std::cout << node->data << std::endl;

    printTreePreOrder(node->left);
    printTreePreOrder(node->right);

    return true;

}

template <class T>
bool AVL_Tree<T>::printTreeInOrder(){

    if(root == NULL)
        return false;

    return printTreeInOrder(root);

}

template <class T>
bool AVL_Tree<T>::printTreeInOrder(Node<T>* node){

    if(node == NULL)
        return false;

    printTreeInOrder(node->left);

    for(int i = 0; i < node->height; i++){
        std::cout << "   ";
    }
    std::cout << node->data << std::endl;

    printTreeInOrder(node->right);

    return true;

}

template <class T>
bool AVL_Tree<T>::printTreePostOrder(){

    if(root == NULL)
        return false;

    return printTreePostOrder(root);

}

template <class T>
bool AVL_Tree<T>::printTreePostOrder(Node<T>* node){

    if(node == NULL)
        return false;

    printTreePostOrder(node->left);
    printTreePostOrder(node->right);

    for(int i = 0; i < node->height; i++){
        std::cout << "   ";
    }
    std::cout << node->data << std::endl;

    return true;

}

#endif