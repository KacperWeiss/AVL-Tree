#ifndef ADDITIONAL_FUNCTIONS
#define ADDITIONAL_FUNCTIONS

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AVL_Tree.hpp"

void showMenu(){

    using namespace std;

    cout    << endl
            << "s - check size of the tree" << endl
            << "h - check height of the tree" << endl
            << "c - check if tree contains value" << endl
            << "i - insert new value" << endl
            << "d - delete value" << endl
            << "t - quick test of AVL_Tree" << endl
            << "m - show menu" << endl
            << "q - quit program" << endl
            << endl;
    
}

void quickTempTreeTest(){

    AVL_Tree<int> tempAVLTreeOfIntegers;

    srand(time(0));
    int randomisedInput;

    for(int i = 0; i < 100; i++){

        randomisedInput = (rand() % 100) + 1;

        if(!tempAVLTreeOfIntegers.insert(randomisedInput))
            std::cout << "Error while inserting value: " << randomisedInput << ". Value already exists in the tree, or value is null" << std::endl;

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
            std::cout << "Error while deleting value: " << randomisedInput << ". Value doesn't exist in the tree, or value to delete is null" << std::endl;

    }

}

#endif