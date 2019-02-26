CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb -O3 -fopt-info

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main

RESOURCE	:= words.tgz

all: $(BIN)/$(EXECUTABLE)

run: clean all extract
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*

extract:
	tar xvf $(RESOURCE)
