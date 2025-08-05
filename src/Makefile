
CXX = g++
CXXFLAGS = -g -O0 -fPIC -std=gnu++20 -Wall -Wextra -pedantic-errors -Wno-unused-parameter

all: compiler

compiler: main.o scanner.o
	$(CXX) $(CXXFLAGS) -o compiler main.o scanner.o

main.o: main.cpp scanner.h
	$(CXX) $(CXXFLAGS) -c main.cpp

scanner.o: scanner.cpp scanner.h
	$(CXX) $(CXXFLAGS) -c scanner.cpp

clean:
	rm -f *.o compiler