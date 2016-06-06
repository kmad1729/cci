#define _DEBUG 1

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

    char del = 'e';
    ll.delete_node(del);


    del = 'f';
    ll.delete_node(del);

    del = 'a';
    ll.delete_node(del);

}
