#include<iostream>
#include "binary_tree.h"
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    B_Tree<int> bt;
    string delim = '\n' + string(20, '#') + '\n';

    int ints_to_insert[] = {42, 17, 96, 5, 36, 78, 102, 84, -1, 10};
    int sz_ints_to_insert = sizeof(ints_to_insert) / sizeof(ints_to_insert[0]);
    for(int i = 0; i < sz_ints_to_insert; i++) 
        bt.insert(ints_to_insert[i]);
    

    cout << "created a btree with ints -->" << endl;
    copy(ints_to_insert, ints_to_insert + sz_ints_to_insert, 
            ostream_iterator<int>(cout, " "));

    cout << delim;
    cout << "binary tree ---> " << endl;
    bt.print_in_order();

    cout << "-1 5 10 17 36 42 78 84 96 102 is expected " << endl;
}

