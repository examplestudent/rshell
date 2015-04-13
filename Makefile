CC=g++
CFLAGS=-Wall -Werror -ansi -pedantic -std=c++11

all: src/main.cpp
	@mkdir -p bin
	$(CC) $(CFLAGS) src/main.cpp -o bin/rshell
