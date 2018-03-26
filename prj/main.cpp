#include <cstring>
#include "inc/node.hpp"
#include "inc/AVL_Tree.hpp"
#include "inc/additionalFunctions.hpp"

int main(){

    char selector = '\0';
    while(selector != 'q'){

        std::cout << " \"i\" - int, \"s\" - string, \"t\" - run test of AVL tree \"q\" - exit program \n";
        std::cout << "Choose type of data: _\b";
        std::cin >> selector;

        if(selector == 't'){

            quickTempTreeTest();
            selector = 'q';
            break;

        } else if(selector == 'i'){

            int tempVal = 0;
            program(tempVal);
            selector = 'q';
            break;

        } else if(selector == 's') {

            std::string tempString = " ";
            program(tempString);
            selector = 'q';
            break;

        }

    }

}