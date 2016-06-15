#pragma once
#include <iostream>

using namespace std;

template <class T>
struct LLNode {
    T data;
    LLNode* next;

    LLNode(const T& d) {
        data = d;
        next = NULL;
    }
};

template <class T>
struct LinkedList {
    LLNode<T>* head;
    LLNode<T>* tail;

    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insert_data(const T& t) {
        if(tail == NULL) {
            tail = new LLNode<T>(t);
            head = tail;
        } else {
            (tail -> next) = new LLNode<T>(t);
            tail = (tail -> next);
        }
    }

    void print_list() {
        for(LLNode<T>* i = head; i != NULL; i = (i -> next)) {
            cout << (i -> data) << " -> ";
        }
        cout << "NULL" << endl;
    }
};
