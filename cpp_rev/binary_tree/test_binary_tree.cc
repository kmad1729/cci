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
    
    cout << "printing out empty binary search tree" << endl;
    bt.print_in_order();
    cout << "() <--expected" << endl;
    cout << "printing out empty binary search tree in level order" << endl;
    bt.print_level_order();
    cout << "() <--expected" << endl;
    cout << delim;
    cout << "checking for 42 in the tree" << endl;
    cout << "42 in tree? " << bt.lookup(42) << endl;
    cout << "expected    0" << endl;
    cout << delim;
    cout << "size of empty tree = " << bt.size() << endl;
    cout << "expected             0" << endl;
    cout << delim;
    cout << "max depth of empty tree = " << bt.max_depth() << endl;
    cout << "expected                  0" << endl;
    cout << delim;
    cout << "trying to find min value of empty bst -->" << endl;
    try {
        bt.min_value();
    } catch (domain_error e) {
        cerr << "caught domain_error --> " << e.what() << endl;
    }




    int ints_to_insert[] = {42, 17, 96, 5, 36, 78, 102, 84, -1, 42, 10 };
    int sz_ints_to_insert = sizeof(ints_to_insert) / sizeof(ints_to_insert[0]);
    for(int i = 0; i < sz_ints_to_insert; i++) 
        bt.insert(ints_to_insert[i]);
    

    cout << "created a btree with ints -->" << endl;
    copy(ints_to_insert, ints_to_insert + sz_ints_to_insert, 
            ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << delim;
    cout << "binary search tree ---> " << endl;
    bt.print_in_order();

    cout << "(-1 5 10 17 36 42 42 78 84 96 102 ) is expected " << endl;

    cout << delim;
    cout << "printing the binary search tree in level order -->" << endl;
    bt.print_level_order();
    cout << "(42 17 96 5 36 78 102 -1 10 42 84 ) is expected" << endl;

    cout << delim;
    cout << "doing lookup tests" << endl;
    for(int i = 0; i < sz_ints_to_insert; i++) {
        int curr_int = ints_to_insert[i];
        cout << curr_int << " in tree? " << bt.lookup(curr_int) << endl;
        cout <<             "expected  1" << endl;
    }

    cout << delim;
    cout << "size of tree = " << bt.size() << endl;
    cout << "expected       " << sz_ints_to_insert << endl;
    cout << delim;
    cout << "max depth of tree = " << bt.max_depth() << endl;
    cout << "expected       " << 4 << endl;
    cout << delim;
    cout << "Min value of tree = " << bt.min_value() << endl;
    cout << "expected           -1" << endl;
}

