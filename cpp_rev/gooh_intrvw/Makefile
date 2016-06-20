CC=g++
CC_Flags = -Wall -g -std=c++11

_ALL = intrvw1a intrvw2

all: $(_ALL)

intrvw1a: intrvw1a.cc
	$(CC) -o $@ $(CC_Flags) $^

intrvw2: intrvw2.cc
	$(CC) -o $@ $(CC_Flags) $^

clean:
	rm -r $(_ALL)
