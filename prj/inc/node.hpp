#ifndef NODE_HPP
#define NODE_HPP

/*!
 * \file node.hpp
 * 
 * This file contains template class Node, it's constructor and destructor + it's properties
 */

#include <iostream>

/*!
 * \brief AVL Node class
 * 
 * Class that represents Node of AVL Tree. It contains 2 pointers left and right
 * to another nodes, it's balance factor (bf), height and data that depends on
 * given data type (has to be compatrable). For now all data is public for simplicity.
 */
template <class T>
class Node{
    
    public:

        /*! 
         * \brief
         * Public constructor for creating new nodes
         * It assigns value to new node and sets pointers to NUll, bf to 0 and height to 1 
         * \param value - comparable value that node will contain.
         */
        Node(T value): data(value), left(NULL), right(NULL), bf(0), height(1) {}

        /*! To avoid memory leaks, destructor deletes object's left and right nodes */
        ~Node(){ delete left; delete right; }

        /*! Comparable data contained in this node */
        T data;

        /*! Pointers for left and right nodes */
        Node* left;
        Node* right;

        /*! Balance factor */
        int bf;

        /*! Height of this node in the tree */
        int height;

};

#endif