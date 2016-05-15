CC=g++
CC_Flags= -Wall -g -std=c++11

_ALL=client_vec

all: $(_ALL)

client_vec: client_vec.cc vec.cc
	$(CC) -o $@ $(CC_Flags)	$^

clean:
	rm -rf $(_ALL)
