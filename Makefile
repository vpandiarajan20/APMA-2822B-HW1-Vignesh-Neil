# # Makefile for a C++ project using g++
CC = g++
CFLAGS = -std=c++11 -Wall

SRCS = matMul.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = matMul

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)