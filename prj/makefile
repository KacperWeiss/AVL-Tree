CPP = g++ -Wall -pedantic -std=c++11 -c -g -Iinc

__start__: AVL-Tree
	./AVL-Tree

AVL-Tree: obj obj/main.o 
	g++ main.o -o AVL-Tree

obj:
	mkdir obj

obj/main.o: main.cpp
	${CPP} main.cpp -o obj/main.o

clear:
	rm -rf obj
