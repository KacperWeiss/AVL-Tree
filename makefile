CPP = g++ -Wall -pedantic -std=c++17 -c -g -Iinc

__start__: AVL-Tree
	./AVL-Tree

AVL-Tree: prj/obj prj/obj/main.o prj/obj/node.o
	g++ prj/obj/main.o prj/obj/node.o -o AVL-Tree

prj/obj:
	mkdir prj/obj

prj/obj/main.o: prj/main.cpp
	${CPP} prj/main.cpp -o prj/obj/main.o

prj/obj/node.o: prj/inc/node.hpp prj/src/node.cpp
	${CPP} prj/src/node.cpp -o prj/obj/node.o

clear:
	rm -rf prj/obj
