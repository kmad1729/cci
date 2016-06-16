CC=g++
CC_Flags= -Wall -g

_ALL=escape foo

all: $(_ALL)

escape: escape.cc
	$(CC) -o $@ $^ $(CC_Flags)

foo: foo.cc
	$(CC) -o $@ $^ $(CC_Flags)

clean:
	rm -rf $(_ALL)
