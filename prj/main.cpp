#include <iostream>
#include <cstdlib>
#include <ctime>
#include "inc/node.hpp"
#include "inc/AVL_Tree.hpp"

using namespace std;

void showMenu(){


    
}

int main(){

    AVL_Tree<int> avlTreeOfIntegers;

    srand(time(0));
    int randomisedInput;

    for(int i = 0; i < 100; i++){

        randomisedInput = (rand() % 100) + 1;

        if(!avlTreeOfIntegers.insert(randomisedInput))
            cout << "Error while inserting value: " << randomisedInput << ". Value already exists in the tree, or value is null" << endl;

    }

    for(int i = 0; i < 100; i++){

        randomisedInput = (rand() % 100) + 1;

        if(!avlTreeOfIntegers.deleteValue(randomisedInput))
            cout << "Error while deleting value: " << randomisedInput << ". Value doesn't exist in the tree, or value to delete is null" << endl;

    }

}