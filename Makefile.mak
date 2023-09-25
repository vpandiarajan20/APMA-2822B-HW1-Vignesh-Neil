# Makefile for a C++ project using g++

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall


# Targets and rules
all: $(CXX) matMul.cpp

clean:
	rm a.out

.PHONY: all clean
