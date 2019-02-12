all:

run: project1
	./project1

project1: main.cpp node.h linkedList.h
	g++ -std=c++11 main.cpp -o project1

run_EC: project1_EC
	./project1_EC

project1_EC: main_EC.cpp node.h linkedList_EC.h
	g++ -std=c++11 main_EC.cpp -o project1_EC
