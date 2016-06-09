//implement an algo that returns the beginning of loop in
//a circular linked list
//get_loop_beg({a,b,c,d,e,c}) -> &c (addr of node c)

#include <iostream>
#include "linked_list.h"
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

LL_Node<char>* get_loop_beg(const LinkedList<char>& ll)
{
    LL_Node<char>* slow_ptr = ll.head;
    LL_Node<char>* fast_ptr = ll.head;
    if(slow_ptr == NULL)
        return NULL;

    slow_ptr = (slow_ptr -> next);
    fast_ptr = ((fast_ptr -> next) -> next);

    while(slow_ptr != fast_ptr) {
        slow_ptr = (slow_ptr -> next);
        fast_ptr = ((fast_ptr -> next) -> next);
    }

    slow_ptr = ll.head;
    while(slow_ptr != fast_ptr) {
        slow_ptr = (slow_ptr -> next);
        fast_ptr = (fast_ptr -> next);
    }

    return slow_ptr;
}

int main()
{
    string delim = string(20, '#') + '\n';
    LinkedList<char> ll;
    ll.insert_node('a');
    ll.insert_node('b');
    ll.insert_node('c');
    LL_Node<char>* loop_beg = ll.tail;
    ll.insert_node('d');
    ll.insert_node('e');
    (ll.tail -> next) = loop_beg;

    cout << delim;
    cout << "linked list --> " << endl;

    LL_Node<char>* curr_node = ll.head;
    for(int i = 0; i < 15; i++) {
        cout << (curr_node -> data) << " -> ";
        curr_node = (curr_node -> next);
    }
    cout << endl;
    cout << delim;

    LL_Node<char>* calculated_loop_beg = get_loop_beg(ll);

    cout << "actual loop_beg --> " << loop_beg -> data << endl;
    cout << "calculated loop_beg --> " << calculated_loop_beg -> data << endl;
    cout << delim;

    cout << delim;
    cout << "Example 2" << endl;;
    LinkedList<char> ll2;
    ll2.insert_node('a');
    ll2.insert_node('b');
    ll2.insert_node('c');
    ll2.insert_node('d');

    loop_beg = ll2.tail;

    ll2.insert_node('e');
    ll2.insert_node('f');
    ll2.insert_node('g');
    ll2.insert_node('h');
    (ll2.tail -> next) = loop_beg;

    cout << "linked list --> " << endl;

    curr_node = ll2.head;
    for(int i = 0; i < 15; i++) {
        cout << (curr_node -> data) << " -> ";
        curr_node = (curr_node -> next);
    }

    cout << endl;
    calculated_loop_beg = get_loop_beg(ll2);

    cout << "actual loop_beg --> " << loop_beg -> data << endl;
    cout << "calculated loop_beg --> " << calculated_loop_beg -> data << endl;

}
