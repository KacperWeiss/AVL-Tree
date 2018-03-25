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

/*!
 * \brief This function is main function of whole program.
 * 
 * Given temporary value this function decides which type of data will it use
 * and then run AVL Tree based on that.
 */

template <class T>
void program(T givenValue){

    char selector;

    T value = givenValue;
    AVL_Tree<T> avlTree;

    showMenu();

    while(selector != 'q'){

        std::cout   << "Select action (m - show menu) > _\b";
        std::cin    >> selector;

        if(strchr("schidpmq", selector)){

            if(selector == 's')
                std::cout << "Current tree size is: " << avlTree.size() << std::endl;

            else if(selector == 'c'){

                std::cout << "Please, give me value that you want to check in the tree\nValue: ";
                std::cin >> value;

                if(avlTree.contains(value))
                    std::cout << "Current tree contains value: " << value << std::endl;
                else
                    std::cout << "Current tree does not contains value: " << value << std::endl;                

            }
            
            else if(selector == 'h')
                std::cout << "Current tree height is: " << avlTree.height() << std::endl;

            else if(selector == 'i'){

                std::cout << "Please, give me value that you want to add to the tree\nValue: ";
                std::cin >> value;

                if(!avlTree.insert(value))
                    std::cout << "Error while inserting value: " << value << ". Value already exists in the tree, or value is null" << std::endl;

            }

            else if(selector == 'd'){

                std::cout << "Please, give me value that you want to delete from the tree\nValue: ";
                std::cin >> value;

                if(!avlTree.deleteValue(value))
                    std::cout << "Error while deleting value: " << value << ". Value doesn't exist in the tree, or value to delete is null" << std::endl;

            }

            else if(selector == 'p'){

                std::cout   << "Which kind of order do you want to print your tree?" << std::endl
                            << "Select 1 for \"pre order \"\n"
                            << "Select 2 for \"in order \"\n"
                            << "Select 3 for \"post order \"\n"
                            << "Your choice: _\b";
                std::cin    >> selector;

                if(strchr("123", selector)){

                    if(selector == '1')
                        avlTree.printTreePreOrder();

                    else if(selector == '2')
                        avlTree.printTreeInOrder();

                    else if(selector == '3')
                        avlTree.printTreePostOrder();

                }

                else
                    std::cout   << "Given selection is not correct" << std::endl;
                
                selector = ' ';

            }

            else if(selector == 'm')
                showMenu();

            else if(selector == 'q')
                std::cout << "Exiting program" << std::endl;

        } else {

            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cerr << "Nieporawne polecenie\n";
            selector = ' ';
            showMenu();

        }

    }

}

#endif