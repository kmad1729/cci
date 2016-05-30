#include "binary_tree.h"
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <stdexcept>

using namespace std;

int main()
{
    B_Search_Tree<int> bt;
    string delim = string(20, '#') + '\n';
    
    int ints_to_insert[] = {42, 17, 96, 5, 36, 78, 102, 84, -1, 42, 10 };
    int sz_ints_to_insert = sizeof(ints_to_insert) / sizeof(ints_to_insert[0]);
    for(int i = 0; i < sz_ints_to_insert; i++) 
        bt.insert(ints_to_insert[i]);
    

    cout << "created a btree with ints -->" << endl;
    copy(ints_to_insert, ints_to_insert + sz_ints_to_insert, 
            ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << delim;
    cout << "mirror of the btree -->" << endl;
    bt.mirror();
    bt.print_in_order();
    cout << "(102 96 84 78 42 42 36 17 10 5 -1 ) <-- expected" << endl;
}
