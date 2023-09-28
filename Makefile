# Makefile for a C++ project using g++

# Targets and rules
all: g++ -o matMul matMul.cpp

clean:
	rm matMul

.PHONY: all clean
