# compiler settings
CPP = g++ -Wall -pedantic -std=c++17 -c -g -Iinc

# __start__: clear AVL-Tree
# 	./AVL-Tree

AVL-Tree: prj/obj prj/obj/main.o 
	g++ prj/obj/main.o -o AVL-Tree

prj/obj:
	mkdir prj/obj

prj/obj/main.o: prj/main.cpp prj/inc/node.hpp prj/inc/AVL_Tree.hpp prj/inc/additionalFunctions.hpp
	${CPP} prj/main.cpp -o prj/obj/main.o

clear:
	rm -rf prj/obj
