#!/usr/bin/env python3


import unittest
#write a function to convert nested list to a single empty list if the list has 1 elem
#e.g    [ ] -> [ ]
#       [ [ ] ] -> [ ]
#       [ [ [ ] ], [ ] ] -> [ [ ], [ ] ]
#       [ [ [ ] ] ] -> [ ]

def eliminate_1_len_brackets(lst = []):
    if len(lst) != 1:
        for i, elem in enumerate(lst):
            lst[i] = eliminate_1_len_brackets(elem)
    else:
        lst = eliminate_1_len_brackets(lst[0])
    return lst


class Test_Eliminate_1_len_bracket(unittest.TestCase):
    def test_1(self):
        l = [ ]
        self.assertEquals([ ], eliminate_1_len_brackets(l))

    def test_2(self):
        l = [ [ [ ] ] ]
        self.assertEquals([ ], eliminate_1_len_brackets(l))

    def test_3(self):
        l = [ [ [ ] ], [ ] ] 
        self.assertEquals([ [ ], [ ] ], eliminate_1_len_brackets(l))

    def test_4(self):
        l = [ [ [ [ ], [ ], [ ] ] ] ]
        self.assertEquals([ [ ], [ ], [ ] ], eliminate_1_len_brackets(l))

    def test_4(self):
        l = [ [ [ [ ], [ ], [ ] ], [ ] ] ]
        self.assertEquals( [ [ [ ], [ ], [ ] ], [ ] ], eliminate_1_len_brackets(l))

if __name__ == '__main__':
    unittest.main()
