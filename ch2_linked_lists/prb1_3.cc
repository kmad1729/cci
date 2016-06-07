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
    delete_with_node_ref(curr_node);
    //update the tail pointer;
    for(curr_node = head; (curr_node -> next) != NULL; 
            curr_node = (curr_node -> next));
    tail = curr_node;
    (tail -> next) = NULL;
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
    int n = 0;
    cout << delim;
    cout << "deleting node at index " << n << endl;
    ll.delete_node_at_index(n);
    cout << "linked list --> " << endl;
    ll.print_list();
    cout << delim;
}
