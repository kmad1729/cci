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
    cout << "double of the btree -->" << endl;
    bt.double_tree();
    bt.print_in_order();
    cout << "(-1 -1 5 5 10 10 17 17 36 36 42 42 42 42 78 78 84 84 96 96 102 102"
        << " ) <-- expected" << endl;

}
