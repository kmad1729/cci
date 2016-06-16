CC=g++
CC_Flags= -Wall -g

_ALL= catly 

all: $(_ALL)

catly: catly.cc
	$(CC) -o $@ $(CC_Flags) $^

.PHONY: clean
clean:
	rm -rf $(_ALL)

