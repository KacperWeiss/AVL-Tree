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
            cout << "Error while inserting value: " << randomisedInput << endl;

    }

}