#pragma once
#include <iostream>
#include <queue>

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

        void print_in_order_util(B_Node<T>* n) {
            if(n != NULL) {
                print_in_order_util((n -> left));
                std::cout << (n -> data) << " ";
                print_in_order_util((n -> right));
            }
        }

        void print_level_order_util(B_Node<T>* n) {
            //print level order traversal of the tree
            std::cout << "(";
            if(n != NULL) {
                std::queue<B_Node<T>*> q;
                q.push(n);
                while(!q.empty()) {
                    B_Node<T>* front = q.front();
                    q.pop();

                    std::cout << (front->data) << " ";
                    if((front -> left) != NULL)
                        q.push((front -> left));
                    if((front -> right) != NULL)
                        q.push((front -> right));

                }

            }
            std::cout << ")";
        }

    public:
        B_Tree() {
            root = NULL;
        }

        void insert(const T& t) {
            root = insert_util(root, t);
        }

        void print_in_order() {
            std::cout << "(";
            print_in_order_util(root);
            std::cout << ")" << std::endl;
        }


        void print_level_order() {
            print_level_order_util(root);
            std::cout << std::endl;
        }

};
