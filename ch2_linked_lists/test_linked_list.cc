#include "linked_list.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string delim = string(20, '#') + '\n';
    LinkedList<char> ll;
    ll.insert_node('s');
    ll.insert_node('t');
    ll.insert_node('a');
    ll.insert_node('r');
    ll.insert_node('e');
    cout << "linked list --> " << endl;
    ll.print_list();
    cout << delim;
}
