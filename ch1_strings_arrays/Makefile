CC=g++
CC_Flags= -g -Wall -std=c++11

_ALL= prb1_5 prb1_4 prb1_6 prb1_7 prb1_2 \
	  prb1_1 prb1_8

all: $(_ALL)

tests: test_str_utils

prb1_6: prb1_6.cc
	$(CC) -o $@ $(CC_Flags) $^

prb1_5: prb1_5.cc
	$(CC) -o $@ $(CC_Flags) $^

prb1_4: prb1_4.cc
	$(CC) -o $@ $(CC_Flags) $^

prb1_7: prb1_7.cc
	$(CC) -o $@ $(CC_Flags) $^

prb1_2: prb1_2.cc
	$(CC) -o $@ $(CC_Flags) $^

prb1_1: prb1_1.cc
	$(CC) -o $@ $(CC_Flags) $^

prb1_8: prb1_8.cc
	$(CC) -o $@ $(CC_Flags) $^

test_str_utils: test_str_utils.cc
	$(CC) -o $@ $(CC_Flags) $^

clean:
	rm -rf $(_ALL)
