//implement an algo to get nth to last elem of singly linked list
//get_nth_last({1, 2, 3}, 0) -> 3
//get_nth_last({1, 2, 3}, 1) -> 2
//get_nth_last({1, 2, 3}, 3) -> out_of_range exception
//get_nth_last({}, 0) -> out_of_range exception
//get_nth_last({1}, 1) -> out_of_range exception
//get_nth_last({1}, 0) -> 1

#include <iostream>
#include "linked_list.h"
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

template <class T>
T LinkedList<T>::get_nth_last(int n)
{
    LL_Node<T>* forward = head;
    LL_Node<T>* back = head;
    ostringstream oss;
    oss << "length of list less than n(" << n << ")";
    for(int counter = 0; counter < n; counter++) {
        if(forward == NULL)
            throw out_of_range(oss.str());
        forward = (forward -> next);
    }
    if(forward == NULL)
        throw out_of_range(oss.str());
    while((forward -> next) != NULL) {
        forward = (forward -> next);
        back = (back -> next);
    }
    return (back -> data);
}

int main()
{
    LinkedList<int> nums;
    string delim = string(20, '#') + '\n';

    int n = 0;
    cout << "empty list --> " << endl;
    nums.print_list();

    try {
        cout << "trying to fetch " << n << "th last " <<
            "elem of list --> " << endl;
        cout << nums.get_nth_last(n) << endl;
    } catch (out_of_range e) {
        cerr << "caught exception --> " << e.what() << endl;
    }

    cout << delim;
    
    nums.insert_node(1);
    nums.insert_node(2);
    nums.insert_node(3);


    cout << "list --> " << endl;
    nums.print_list();


    cout << n << "th last elem of list --> (" << 
        nums.get_nth_last(n) << ")" << endl;
    cout << "expected --> 3" << endl;

    n = 1;
    cout << n << "st last elem of list --> (" << 
        nums.get_nth_last(n) << ")" << endl;
    cout << delim;

    n = 2;
    cout << n << "nd last elem of list --> (" << 
        nums.get_nth_last(n) << ")" << endl;
    cout << delim;

    n = 3;
    try {
        cout << "trying to fetch " << n << "rd last " <<
            "elem of list --> " << endl;
        cout << nums.get_nth_last(n) << endl;
    } catch (out_of_range e) {
        cerr << "caught exception --> " << e.what() << endl;
    }
    cout << delim;
    cout << delim;

    LinkedList<string> new_list;
    new_list.insert_node("kashyap");

    cout << "new list --> " << endl;
    new_list.print_list();
    n = 1;

    try {
        cout << "trying to fetch " << n << "st last " <<
            "elem of list --> " << endl;
        cout << new_list.get_nth_last(n) << endl;
    } catch (out_of_range e) {
        cerr << "caught exception --> " << e.what() << endl;
    }

    cout << delim;
    n = 0;
    cout << n << "th last elem of list --> (" << 
        new_list.get_nth_last(n) << ")" << endl;
    cout << delim;

}
