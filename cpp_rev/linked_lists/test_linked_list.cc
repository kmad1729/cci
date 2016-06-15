#include "linked_list.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

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

    int i = 0;

    cout << i << "th elem = " << ll.get_nth(i) << endl;
    i = 2;
    cout << i << "nd elem = " << ll.get_nth(i) << endl;
    i = 3;
    try {
        cout << i << "rd elem = " << ll.get_nth(i) << endl;
    } catch (out_of_range e) {
        cout << "caught exception " << e.what() << " while trying to find "
            << i << "rd elem" << endl;
    }
    cout << delim;
}
