#INTRVW 4 -->
#write a function to convert nested list to a single empty list if the list has 1 elem
#e.g [ ] -> [ ]
#[ [ ] ] -> [ ]
#[ [ [ ] ], [ ] ] -> [ [ ], [ ] ]
#[ [ [ ] ] ] -> [ ]

# given a boolean array where true represend a square is filled and `false` otherwise
# find all the independent filled squares i.e filled squares which are the only filled
# squares  for a given row and col. If 2 or more squares are in a single row and col, they are 
# not considered independent
# e.g {
#        { F T F F F }
#        { F F F T F }
#        { F F T F F }
#        { F F T F T }
#        { T F F F F }
#    }
# returns { (0, 1), (1, 3), (4, 0) }


#INTRVW 1 -->
#what does the following code do?
# bool fun(unsigned int n) {
#   return !(n & (n - 1));
#}

# write a program to get the overlapping interval in 2 lists
# l1 = [(1, 5), (11, 16)]
# l2 = [(2, 6), (12, 15)]
# fun(l1, l2) -> [(2, 5), (11, 16)]

#INTRVW 2 -->
#given a binary tree find the sum of all the leaves at the max depth
#    1
#  /   \        -> 5
# 2     3   
#
# 1         -> 1
# -1        -> -1


#INTRVW 3 -->
#write a program to calculate the number of possible solutions to N queens problem on 8 x 8 chess board


