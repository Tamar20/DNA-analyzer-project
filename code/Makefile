CC=g++

INC_FLAGS=-I../include
CFLAGS= -g -pedantic -Wall -Werror -Wconversion -ansi -std=c++11 $(INC_FLAGS)
CXXFLAGS=$(CFLAGS)
LDFLAGS=-g

TARGET=main
SOURCES=$(wildcard *.cpp)
OBJS=$(SOURCES:.cpp=.o)

$(TARGET): $(OBJS)

.PHONY: clean run gdb

include .depends

.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends
clean:
	rm -f $(OBJS) $(TARGET) .depends
run: $(TARGET)
	./$(TARGET)
valgrind: $(TARGET)
	valgrind ./$(TARGET)
gdb: $(TARGET)
	gdb -q ./$(TARGET)

