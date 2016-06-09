CC=g++
CC_Flags = -g -Wall -std=c++11

_ALL= test_linked_list prb1_2 prb1_3 prb2_4

all: $(_ALL)

test_linked_list: test_linked_list.cc
	$(CC) -o $@ $^ $(CC_Flags)

prb1_2: prb1_2.cc
	$(CC) -o $@ $^ $(CC_Flags)

prb1_3: prb1_3.cc
	$(CC) -o $@ $^ $(CC_Flags)

prb2_4: prb2_4.cc
	$(CC) -o $@ $^ $(CC_Flags)

clean:
	rm -rf $(_ALL)
