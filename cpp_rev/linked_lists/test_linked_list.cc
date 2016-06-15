#include "linked_list.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    string delim = string(20, '#') + '\n';
    LinkedList<int> ll;
    ll.insert_data(1);
    ll.insert_data(2);
    ll.insert_data(3);

    cout << "ll --> " << endl;
    ll.print_list();
    cout << delim;

    int n = 2;
    cout << "count of " << n << " = " << ll.count(n) << endl;
    n = 5;
    cout << "count of " << n << " = " << ll.count(n) << endl;
    cout << delim;

}
