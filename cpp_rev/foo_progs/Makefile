CC=g++
CC_Flags = -Wall -g

_ALL=test_class_stack_arr path_finding 

all: $(_ALL)

test_class_stack_arr: test_class_stack_arr.cc
	$(CC) -o $@ $(CC_Flags) $^

path_finding: path_finding.cc
	$(CC) -o $@ $(CC_Flags) $^

clean:
	rm -rf $(_ALL)
