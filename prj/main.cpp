#include <cstring>
#include "inc/node.hpp"
#include "inc/AVL_Tree.hpp"
#include "inc/additionalFunctions.hpp"

int main(){

    AVL_Tree<int> avlTreeOfIntegers;

    int value;
    char selector;

    showMenu();

    while(selector != 'q'){

        std::cout   << "Select action (m - show menu) > _\b";
        std::cin    >> selector;

        if(strchr("schidtmq", selector)){

            if(selector == 's')
                std::cout << "Current tree size is: " << avlTreeOfIntegers.size() << std::endl;

            else if(selector == 'c'){

                std::cout << "Please, give me value that you want to check in the tree\nValue: ";
                std::cin >> value;

                if(avlTreeOfIntegers.contains(value))
                    std::cout << "Current tree contains value: " << value << std::endl;
                else
                    std::cout << "Current tree does not contains value: " << value << std::endl;                

            }
            
            else if(selector == 'h')
                std::cout << "Current tree height is: " << avlTreeOfIntegers.height() << std::endl;

            else if(selector == 'i'){

                std::cout << "Please, give me value that you want to add to the tree\nValue: ";
                std::cin >> value;

                if(!avlTreeOfIntegers.insert(value))
                    std::cout << "Error while inserting value: " << value << ". Value already exists in the tree, or value is null" << std::endl;

            }

            else if(selector == 'd'){

                std::cout << "Please, give me value that you want to delete from the tree\nValue: ";
                std::cin >> value;

                if(!avlTreeOfIntegers.deleteValue(value))
                    std::cout << "Error while deleting value: " << value << ". Value doesn't exist in the tree, or value to delete is null" << std::endl;

            }

            else if(selector == 't')
                quickTempTreeTest();

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