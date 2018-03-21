#ifndef ADDITIONAL_FUNCTIONS
#define ADDITIONAL_FUNCTIONS

/*!
 * \file additionalFunctions.hpp
 * 
 * This file contains functions for main program
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AVL_Tree.hpp"

/*!
 * \brief Function that shows menu
 * 
 * Function that shows menu to an user, within itself it uses
 * std namespace.
 */
void showMenu(){

    using namespace std;

    cout    << endl
            << "s - check size of the tree" << endl
            << "h - check height of the tree" << endl
            << "c - check if tree contains value" << endl
            << "i - insert new value" << endl
            << "d - delete value" << endl
            << "p - print tree" << endl << endl
            << "t - quick test of AVL_Tree" << endl
            << "m - show menu" << endl
            << "q - quit program" << endl
            << endl;
    
}

/*!
 * \brief Function that do quick test of AVL Tree
 * 
 * This function does basic test of AVL Tree methods using random integers
 */
void quickTempTreeTest(){

    AVL_Tree<int> tempAVLTreeOfIntegers;

    srand(time(0));
    int randomisedInput;

    for(int i = 0; i < 100; i++){

        randomisedInput = (rand() % 100) + 1;

        if(!tempAVLTreeOfIntegers.insert(randomisedInput))
            std::cout << "Value not inserted: " << randomisedInput << ". Value already exists in the tree, or value is null" << std::endl;

    }

    std::cout << "Tree printed \"pre order\":" << std::endl;
    tempAVLTreeOfIntegers.printTreePreOrder();

    std::cout << "Tree printed \"in order\":" << std::endl;
    tempAVLTreeOfIntegers.printTreeInOrder();

    std::cout << "Tree printed \"post order\":" << std::endl;
    tempAVLTreeOfIntegers.printTreePostOrder();

    for(int i = 0; i < 100; i++){

        randomisedInput = (rand() % 100) + 1;

        if(!tempAVLTreeOfIntegers.deleteValue(randomisedInput))
            std::cout << "Value not deleted: " << randomisedInput << ". Value doesn't exist in the tree, or value to delete is null" << std::endl;

    }

}

#endif