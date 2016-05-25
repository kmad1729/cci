#pragma once
#include <iostream>

template <class T>
class B_Node {
    public:
        T data;
        B_Node* left;
        B_Node* right;

        B_Node(const T& t) {
            data = T(t);
            left = NULL;
            right = NULL;
        }
};

template <class T>
class B_Tree {
    private:
        B_Node<T>* root;
        B_Node<T>* insert_util(B_Node<T>* n, const T& t) {
            if(n == NULL) {
                n = new B_Node<T>(t);
            } else {
                if(t <= (n -> data)) {
                    (n -> left) = insert_util((n -> left), t);
                } else {
                    (n -> right) = insert_util((n -> right), t);
                }
            }

            return n;
        }

        void print_inOrder(B_Node<T>* n) {
            if(n != NULL) {
                print_inOrder((n -> left));
                std::cout << (n -> data) << " ";
                print_inOrder((n -> right));
            }
        }

    public:
        B_Tree() {
            root = NULL;
        }

        void insert(const T& t) {
            root = insert_util(root, t);
        }

        void print_in_order() {
            print_inOrder(root);
            std::cout << std::endl;
        }

};
