//write a function to delete a node in the middle of the list
//to test write a helper function to delete at an index
//delete_node_at_index({a, b, c, d, e}, 0)
//  --> {b, c, d, e}
//delete_node_at_index({b, c, d, e}, 2)
//  --> {b, c, e}
//delete_node_at_index({b, c, e}, 2)
//  --> {b, c}
//delete_node_at_index({b, c}, 2)
//  --> out_of_range exception

#include "linked_list.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

template <class T>
void LinkedList<T>::delete_with_node_ref(LL_Node<T>* node_ref)
{
    LL_Node<T>* curr_node = node_ref;
    LL_Node<T>* prev = NULL;
    if(curr_node == NULL)
        throw domain_error("invalid node ref");

    while((curr_node -> next) != NULL) {
        prev = curr_node;
        (curr_node -> data) = ((curr_node -> next) -> data);
        curr_node = (curr_node -> next);
    }

    if(prev != NULL) {
        (prev -> next) = NULL;
        tail = prev;
    } 
    delete curr_node;
}

template <class T>
void LinkedList<T>::delete_node_at_index(int ind)
{
    LL_Node<T>* curr_node = head;
    stringstream ss;
    ss << "invalid index " << ind;
    for(int counter = 0; counter < ind; counter++) {
        if(curr_node == NULL)
            throw out_of_range(ss.str());
        curr_node = (curr_node -> next);
    }

    if(curr_node == NULL)
        throw domain_error(ss.str());

    if(curr_node == tail) {
        LL_Node<T>* new_tail = NULL;
        for(new_tail = head; (new_tail -> next) != tail; 
                new_tail = (new_tail -> next));
        tail = new_tail;
        (tail -> next) = NULL;
        delete curr_node;
    }
    else
        delete_with_node_ref(curr_node);
    //update the tail pointer;

}

int main()
{
    LinkedList<char> ll;
    ll.insert_node('a');
    ll.insert_node('b');
    ll.insert_node('c');
    ll.insert_node('d');
    ll.insert_node('e');

    string delim = string(20, '#') + '\n';
    cout << "linked list --> " << endl;
    ll.print_list();
    cout << delim;

    int n = 0;
    cout << "deleting node at index " << n << endl;
    ll.delete_node_at_index(n);
    cout << "linked list --> " << endl;
    ll.print_list();
    cout << delim;

    n = 2;
    cout << "deleting node at index " << n << endl;
    ll.delete_node_at_index(n);
    cout << "linked list --> " << endl;
    ll.print_list();
    cout << delim;

    n = 2;
    cout << "deleting node at index " << n << endl;
    ll.delete_node_at_index(n);
    cout << "linked list --> " << endl;
    ll.print_list();
    cout << delim;

    n = 2;
    cout << "trying to delete node at index " << n << endl;
    try {
        ll.delete_node_at_index(n);
    } catch(domain_error e) {
        cerr << "caught domain error --> (" << e.what() << ")" << endl;
    }
    cout << "linked list --> " << endl;
    ll.print_list();
    cout << delim;

    n = 3;
    cout << "trying to delete node at index " << n << endl;
    try {
        ll.delete_node_at_index(n);
    } catch(out_of_range e) {
        cerr << "caught domain error --> (" << e.what() << ")" << endl;
    }
    cout << "linked list --> " << endl;
    ll.print_list();
    cout << delim;
}
