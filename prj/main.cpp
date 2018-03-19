#include <iostream>
#include "inc/node.hpp"
#include "inc/AVL_Tree.hpp"

void showMenu(){


    
}

int main(){

    AVL_Tree<int> avlTreeOfIntegers;

    for(int i = 0; i < 100; i++){

        if(!avlTreeOfIntegers.insert(i))
            std::cout << "Error while inserting value:" << i << std::endl;

    }

}