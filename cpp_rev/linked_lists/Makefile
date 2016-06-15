CC=g++
CC_Flags= -Wall -g -std=c++11

_ALL = test_linked_list

all: $(_ALL)

test_linked_list: test_linked_list.cc
	$(CC) -o $@ $^ $(CC_Flags)

clean:
	rm -rf $(_ALL)
