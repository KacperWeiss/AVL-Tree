# compiler settings
CPP = g++ -Wall -pedantic -std=c++17 -c -g -Iinc
BOOST = -lboost_system -lboost_filesystem

# __start__: clear AVL-Tree
# 	./AVL-Tree

AVL-Tree: prj/obj prj/obj/main.o prj/obj/logger.o
	g++ prj/obj/logger.o prj/obj/main.o -o AVL-Tree ${BOOST}

prj/obj:
	mkdir prj/obj

prj/obj/main.o: prj/main.cpp prj/inc/node.hpp prj/inc/AVL_Tree.hpp prj/inc/additionalFunctions.hpp
	${CPP} prj/main.cpp -o prj/obj/main.o

prj/obj/logger.o: prj/src/logger.cpp prj/inc/logger.hpp
	${CPP} prj/src/logger.cpp -o prj/obj/logger.o ${BOOST}

clear:
	rm -rf prj/obj logs

clearObj:
	rm -rf prj/obj

clearLogs:
	rm -rf logs
