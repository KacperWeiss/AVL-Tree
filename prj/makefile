CPP = g++ -Wall -pedantic -std=c++11 -c -g -Iinc

__start__: AVL-Tree
	./AVL-Tree

AVL-Tree: obj obj/main.o obj/node.o
	g++ obj/main.o obj/node.o -o AVL-Tree

obj:
	mkdir obj

obj/main.o: main.cpp
	${CPP} main.cpp -o obj/main.o

obj/node.o: inc/node.hpp src/node.cpp
	${CPP} src/node.cpp -o obj/node.o

clear:
	rm -rf obj
