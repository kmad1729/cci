CC=g++
CC_Flags= -Wall -g

_ALL=test_stack

all: $(_ALL)

test_stack: test_stack.cc
	$(CC) -o $@ $(CC_Flags) $^

.PHONY: clean

clean:
	rm -rf $(_ALL)

