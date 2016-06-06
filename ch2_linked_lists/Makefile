CC=g++
CC_Flags = -g -Wall -std=c++11

_ALL= test_linked_list prb1_2

all: $(_ALL)

test_linked_list: test_linked_list.cc
	$(CC) -o $@ $^ $(CC_Flags)

prb1_2: prb1_2.cc
	$(CC) -o $@ $^ $(CC_Flags)

clean:
	rm -rf $(_ALL)
