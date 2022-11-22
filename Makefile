main: main.o funcs.o 
	g++ -o main main.o funcs.o 

tests: tests.o funcs.o 
	g++ -o tests tests.o funcs.o


main.o: main.cpp

funcs.o: funcs.cpp

tests.o: tests.cpp
	g++ -c -std=c++11 tests.cpp

clean: 
	rm -f *.o tests main