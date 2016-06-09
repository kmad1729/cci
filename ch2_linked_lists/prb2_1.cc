//write a function to remove duplicates from a linked list
//remove_duplicates({a,a,b,b,c,d,e,e}) -> {a,b,c,d,e}
//remove_duplicates({a,b,c}) -> {a,b,c}
//remove_duplicates({a,a,a,a}) -> {a}
//remove_duplicates({a}) -> {a}
//remove_duplicates({}) -> {}

#include <iostream>
#include "linked_list.h"
#include <stdexcept>
#include <string>
#include <sstream>
#include <set>

using namespace std;

template<class T>
void LinkedList<T>::remove_duplicates() {
    set<T> s;
    LL_Node<T>* temp_ref = NULL;
    LL_Node<T>* prev = NULL;
    LL_Node<T>* i = head;

    while(i != NULL) {
        if(s.count(i -> data) != 0) {
            temp_ref = i;
            (prev -> next) = (i -> next);
            i = (i -> next);
            delete temp_ref;
        } else {
            prev = i;
            s.insert(i -> data);
            i = (i -> next);
        }
    }
    tail = prev;
}

int main()
{
    string delim = string(20, '#') + '\n';
    LinkedList<char> ll;
    ll.insert_node('a');
    ll.insert_node('a');
    ll.insert_node('b');
    ll.insert_node('b');
    ll.insert_node('c');
    ll.insert_node('d');
    ll.insert_node('e');
    ll.insert_node('e');

    cout << "ll -> " << endl;
    ll.print_list();
    ll.remove_duplicates();
    cout << "after remove duplicates. -->" << endl;
    ll.print_list();

    cout << delim;

    LinkedList<char> ll2;
    ll2.insert_node('a');
    ll2.insert_node('b');
    ll2.insert_node('c');
    cout << "ll2 -> " << endl;
    ll2.print_list();
    ll2.remove_duplicates();
    cout << "after remove duplicates. -->" << endl;
    ll2.print_list();

    cout << delim;

    LinkedList<char> ll3;
    ll3.insert_node('a');
    ll3.insert_node('a');
    ll3.insert_node('a');
    ll3.insert_node('a');
    ll3.insert_node('a');
    cout << "ll3 -> " << endl;
    ll3.print_list();
    ll3.remove_duplicates();
    cout << "after remove duplicates. -->" << endl;
    ll3.print_list();

    cout << delim;

    LinkedList<char> ll4;
    ll4.insert_node('a');
    cout << "ll4 -> " << endl;
    ll4.print_list();
    ll4.remove_duplicates();
    cout << "after remove duplicates. -->" << endl;
    ll4.print_list();

    cout << delim;

    LinkedList<char> ll5;
    cout << "ll5 -> " << endl;
    ll5.print_list();
    ll5.remove_duplicates();
    cout << "after remove duplicates. -->" << endl;
    ll5.print_list();

    cout << delim;
}


