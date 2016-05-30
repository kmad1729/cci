CC=c++
CC_Flags= -Wall -g

_ALL=test_binary_tree part2_test_binary_tree

all: $(_ALL)

test_binary_tree: test_binary_tree.cc
	$(CC) -o $@ $(CC_Flags) $^

part2_test_binary_tree: part2_test_binary_tree.cc
	$(CC) -o $@ $(CC_Flags) $^

clean:
	rm -rf $(_ALL)
