#include "binary_tree.h"
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <stdexcept>

using namespace std;

int main()
{
    B_Search_Tree<int> bt1;
    B_Search_Tree<int> bt2;
    B_Search_Tree<int> bt3;
    string delim = string(20, '#') + '\n';
    
    int ints_to_insert1[] = {42, 17, 96, 5, 36, 78, 102, 84, -1, 42, 10 };
    int ints_to_insert2[] = {42, 17, 5, -1, 10, 36, 96, 42, 78, 102, 84};
    int ints_to_insert3[] = {42, 42, 17, 96, 5, 36, 78, 102, 84, -1, 10 };

    int sz_ints_to_insert = sizeof(ints_to_insert1) / sizeof(ints_to_insert1[0]);
    for(int i = 0; i < sz_ints_to_insert; i++) 
        bt1.insert(ints_to_insert1[i]);
    
    for(int i = 0; i < sz_ints_to_insert; i++) 
        bt2.insert(ints_to_insert2[i]);

    for(int i = 0; i < sz_ints_to_insert; i++) 
        bt3.insert(ints_to_insert3[i]);

    cout << "created a btree bt1 -->" << endl;
    bt1.print_post_order();
    cout << endl;

    cout << "created a btree bt2 -->" << endl;
    bt2.print_post_order();
    cout << endl;

    cout << "created a btree bt3 -->" << endl;
    bt3.print_post_order();
    cout << endl;

    cout << "bt1 same as bt2? " << bt1.same_tree(bt2) << endl;
    cout << "expected -->     1" << endl;

    cout << "bt1 same as bt3? " << bt1.same_tree(bt3) << endl;
    cout << "expected -->     0" << endl;

}
