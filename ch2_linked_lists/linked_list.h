#pragma once
#include <iostream>

template<class T>
class LL_Node {
    public:
        T data;
        LL_Node<T>* next;

        LL_Node(const T& elem) {
            data = elem;
            next = NULL;
        }
};

template<class T>
class LinkedList {
    public:
        void insert_node(const T& elem);

        void delete_node(const T& elem);

        LinkedList() {
            head = NULL;
            tail = NULL;
        }

        void print_list() const;
    private:
        LL_Node<T>* head;
        LL_Node<T>* tail;
};

template <class T>
void LinkedList<T>::insert_node(const T& elem)
{
    LL_Node<T>* new_node = new LL_Node<T>(elem);
    if(tail == NULL) {
        tail = new_node;
        head = tail;
    } else {
        (tail -> next) = new_node;
        tail = (tail -> next);
    }
}

template <class T>
void LinkedList<T>::print_list() const {
    LL_Node<T>* curr_node = head;
    while(curr_node != NULL) {
        std::cout << (curr_node -> data) << " -> ";
        if(curr_node == tail)
            std::cout << "/";
        curr_node = (curr_node -> next);
    }
    std::cout << std::endl;
}
