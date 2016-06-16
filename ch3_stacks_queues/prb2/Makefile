CC=g++
CC_Flags=-Wall -g

_ALL=test_stack_with_min

all: $(_ALL)

test_stack_with_min: test_stack_with_min.cc
	$(CC) -o $@ $(CC_Flags) $^

clean:
	rm -rf $(_ALL)
