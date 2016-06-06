CC=g++
CC_Flags = -g -Wall

_ALL= test_linked_list

all: $(_ALL)

test_linked_list: test_linked_list.cc
	$(CC) -o $@ $^ $(CC_Flags)

clean:
	rm -rf $(_ALL)
