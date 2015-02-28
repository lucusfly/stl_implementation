all:stringTest heapTest

stringTest:../string.h ../string.cpp stringTest.cpp
	g++ -Wall -lgtest -lgtest_main -o stringTest stringTest.cpp ../string.cpp

heapTest:heapTest.cpp ../heap.h
	g++ -Wall -lgtest -lgtest_main -o heapTest heapTest.cpp
