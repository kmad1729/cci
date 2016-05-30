CC=c++
CC_Flags= -Wall -g

_ALL=test_binary_tree mirror_btree_test doubletree_btree_test

all: $(_ALL)

test_binary_tree: test_binary_tree.cc
	$(CC) -o $@ $(CC_Flags) $^

mirror_btree_test: mirror_btree_test.cc
	$(CC) -o $@ $(CC_Flags) $^

doubletree_btree_test: doubletree_btree_test.cc
	$(CC) -o $@ $(CC_Flags) $^

clean:
	rm -rf $(_ALL)
