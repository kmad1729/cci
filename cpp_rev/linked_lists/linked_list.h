#pragma once
#include <iostream>
#include <stdexcept>

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

    int count(const T& t) {
        //return the count of t in the list
        int result = 0;
        for(LLNode<T>* i = head; i != NULL; i = (i -> next))
            if ((i -> data) == t)
                result++;
        return result;
    }

    T get_nth(int n) {
        // return nth element of the list '0' based
        // out_of_range exception otherwise
        if(n < 0)
            throw out_of_range("index out of range!");
        LLNode<T>* curr = head;
        for(int index = 0; index < n; index++) {
            if(curr == NULL)
                throw out_of_range("index out of range!");
            curr = (curr -> next);

        }

        if(curr == NULL)
            throw out_of_range("index out of range!");
        return (curr -> data);
    }

    //get length of the linked list
    int length() {
        int len = 0;
        for(LLNode<T>* i = head; i != NULL; i = (i -> next))
            len++;
        return len;
    }
};
