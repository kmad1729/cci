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
        void insert_node(const T&);
        void delete_node(const T&);

        LinkedList() {
            head = NULL;
            tail = NULL;
        }

        void print_list() const;
        T get_nth_last(int);
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
            std::cout << "NULL";
        curr_node = (curr_node -> next);
    }
    std::cout << std::endl;
}


template <class T>
void LinkedList<T>::delete_node(const T& t)
{
#if (_DEBUG > 0)
    std::cout << "deleting data (" << t << ")" << std::endl;
#endif
    LL_Node<T>* prev = NULL;
    LL_Node<T>* tmp_node = NULL;
    if(head == NULL)
        return;

    if((head -> data) == t) {
        tmp_node = head;
        if(head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            head = (head -> next);
        }
    } else {
        prev = head;
        LL_Node<T>* curr_node = (prev -> next);
        while(curr_node != NULL && (curr_node -> data) != t) {
            prev = curr_node;
            curr_node = (curr_node -> next);
        }

        //found node to delete

        if(curr_node == NULL) {
#if (_DEBUG > 0)
            std::cout << "data (" << t << ") not in linked list!!" << std::endl;
#endif
            return;
        }

        if(tail == curr_node)
            tail = prev;
        tmp_node = curr_node;
        (prev -> next) = (curr_node -> next);
    }
    delete tmp_node;
#if (_DEBUG > 0)
    print_list();
#endif
}
