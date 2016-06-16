CC=g++
CC_Flags= -g -Wall -std=c++11

_ALL=test_min_heap

all: $(_ALL)


test_min_heap: test_min_heap.cc
	$(CC) -o $@ $^ $(CC_Flags)

clean:
	rm -rf $(_ALL)
