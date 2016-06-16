CC = g++
CC_Flags = -Wall -g

_ALL = boggle_solver

all: $(_ALL)

boggle_solver: boggle_solver.cc
	$(CC) -o $@ $(CC_Flags) $^

clean:
	rm -rf $(_ALL)
