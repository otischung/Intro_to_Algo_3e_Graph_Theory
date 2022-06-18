CXX=g++
CFLAGS=-g -Wall -fsanitize=leak -fsanitize=address -fsanitize=undefined

all: main

main: main.cpp graph.cpp floyd_warshall.cpp
	$(CXX) $(CFLAGS) $^ -o $@

clean:
	rm -f main
