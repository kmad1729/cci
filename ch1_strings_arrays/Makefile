CC=g++
CC_Flags= -g -Wall

_ALL= prb1_5 prb1_4

all: $(_ALL)

prb1_5: prb1_5.cc
	$(CC) -o $@ $(CC_Flags) $^

prb1_4: prb1_4.cc
	$(CC) -o $@ $(CC_Flags) $^

clean:
	rm -rf $(_ALL)
