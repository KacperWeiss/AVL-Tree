#include <cstring>
#include "inc/node.hpp"
#include "inc/AVL_Tree.hpp"
#include "inc/additionalFunctions.hpp"

int main(){

    char selector;

    showMenu();

    while(selector != 'q'){

        std::cout   << "Select action (m - show menu) > _\b";
        std::cin    >> selector;

        if(strchr("tmq", selector)){

            if(selector == 't')
                quickTempTreeTest();

            else if(selector == 'm')
                showMenu();

            else if(selector == 'q')
                std::cout << "Exiting program" << std::endl;

        }

    }

}