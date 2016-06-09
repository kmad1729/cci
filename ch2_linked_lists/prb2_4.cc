//implement an algo to add 2 linked lists of digits
//sum_linked_list({9, 9}, {9, 9}) -> {8, 9, 1}
//sum_linked_list({0}, {0}) -> {0}
//sum_linked_list({0}, {5,0, 6}) -> {5, 0, 6}
//sum_linked_list({9}, {9, 9, 9, 9}) -> {8, 0, 0, 0, 1}

#include <iostream>
#include "linked_list.h"
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

LinkedList<short> sum_linked_list(const LinkedList<short>& l1,
        const LinkedList<short>& l2)
{
    LinkedList<short> result;
    short carry_over = 0;
    short temp_var = 0;
    LL_Node<short>* p1 = l1.head;
    LL_Node<short>* p2 = l2.head;
    while(p1 != NULL && p2 != NULL) {
        temp_var = (p1 -> data) + (p2 -> data) + carry_over;
        result.insert_node(temp_var % 10);
        carry_over = temp_var / 10;
        p1 = (p1 -> next);
        p2 = (p2 -> next);
    }
    if(p1 != NULL || p2 != NULL) {
        if(p1 != NULL) {
            while(p1 != NULL) {
                temp_var = (p1 -> data) + carry_over;
                result.insert_node(temp_var % 10);
                carry_over = temp_var / 10;
                p1 = (p1 -> next);
            }
        } else {
            while(p2 != NULL) {
                temp_var = (p2 -> data) + carry_over;
                result.insert_node(temp_var % 10);
                carry_over = temp_var / 10;
                p2 = (p2 -> next);
            }
        }
    }
    if(carry_over > 0)
        result.insert_node(carry_over);
    return result;
}

int main()
{
    string delim = string(20, '#') + '\n';
    LinkedList<short> l1;
    l1.insert_node(9);
    l1.insert_node(9);
    cout << "l1 --> " << endl;
    l1.print_list();

    LinkedList<short> l2;
    l2.insert_node(5);
    l2.insert_node(0);
    l2.insert_node(6);
    cout << "l2 --> " << endl;
    l2.print_list();


    LinkedList<short> l3;
    l3.insert_node(0);
    cout << "l3 --> " << endl;
    l3.print_list();

    LinkedList<short> l4;
    l4.insert_node(9);
    l4.insert_node(9);
    l4.insert_node(9);
    l4.insert_node(9);
    cout << "l4 --> " << endl;
    l4.print_list();

    LinkedList<short> l5;
    l5.insert_node(3);
    l5.insert_node(1);
    l5.insert_node(5);
    cout << "l5 --> " << endl;
    l5.print_list();

    LinkedList<short> l6;
    l6.insert_node(5);
    l6.insert_node(9);
    l6.insert_node(2);
    cout << "l6 --> " << endl;
    l6.print_list();

    LinkedList<short> l7;
    cout << "l7 --> " << endl;
    l7.print_list();


    cout << delim;
    cout << "l1 + l1 --> " << endl;
    sum_linked_list(l1, l1).print_list();

    cout << delim;
    cout << "l3 + l3 --> " << endl;
    sum_linked_list(l3, l3).print_list();

    cout << delim;
    cout << "l3 + l2 --> " << endl;
    sum_linked_list(l3, l2).print_list();

    cout << delim;
    cout << "l2 + l3 --> " << endl;
    sum_linked_list(l2, l3).print_list();

    cout << delim;
    cout << "l1 + l4 --> " << endl;
    sum_linked_list(l1, l4).print_list();

    cout << delim;
    cout << "l4 + l1 --> " << endl;
    sum_linked_list(l4, l1).print_list();

    cout << delim;
    cout << "l5 + l6 --> " << endl;
    sum_linked_list(l5, l6).print_list();

    cout << delim;
    cout << "l7 + l7 --> " << endl;
    sum_linked_list(l7, l7).print_list();


}
