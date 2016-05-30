#pragma once
#include <iostream>
#include <queue>
#include <stdexcept>

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
    protected:
        B_Node<T>* root;

    private:
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

        int size_util(B_Node<T>* n) {
            if(n != NULL)
                return 1 + size_util((n -> left)) +
                    size_util((n -> right));
            return 0;
        }

        int util_max_depth(B_Node<T>* n) {
            //get the maximum distance between n and a farthest leaf
            if(n != NULL) {
                return 1 + std::max(util_max_depth(n-> left),
                        util_max_depth(n->right));
            }
            return 0;
        }

        void util_print_post_order(B_Node<T>* n) {
            if(n != NULL) {
                util_print_post_order((n -> left));
                util_print_post_order((n -> right));
                std::cout << n -> data << " ";
            }
        }

        bool util_has_path_sum(B_Node<T>* n, const T& sum) {
            if(n == NULL)
                return (sum == 0);
            T required_sum = sum - (n -> data);
            return util_has_path_sum((n -> left), required_sum)
                || util_has_path_sum((n -> right), required_sum);
        }

    public:
        B_Tree() {
            root = NULL;
        }

        void print_in_order() {
            std::cout << "(";
            print_in_order_util(root);
            std::cout << ")" << std::endl;
        }

        void print_post_order() {
            std::cout << "(";
            util_print_post_order(root);
            std::cout << ")" << std::endl;
        }

        void print_level_order() {
            print_level_order_util(root);
            std::cout << std::endl;
        }

        int size() {
            return size_util(root);
        }

        int max_depth() {
            return util_max_depth(root);
        }

        bool has_path_sum(const T& sum) {
            return util_has_path_sum(root, sum);
        }
};


template <class T>
class B_Search_Tree : public B_Tree<T> {
    private:
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

        bool lookup_util(B_Node<T>* n, const T& t) {
            if(n != NULL) {
                if((n -> data) == t)
                    return true;
                else if ((n -> data) < t)
                    return lookup_util((n -> left), t);
                else
                    return lookup_util((n -> right), t);
            }
            return false;
        }

        T& util_min_value(B_Node<T>* n) {
            //get the minimum value in a non empty binary search tree
            //in case of empty throw a domain error
            if(n == NULL)
                throw std::domain_error("Cannot find minimum value of empty tree");

            B_Node<T>* curr_node = n;
            while( (curr_node->left) != NULL)
                curr_node = (curr_node -> left);
            return (curr_node -> data);
        }


    public:
        void insert(const T& t) {
            B_Tree<T>::root = insert_util(B_Tree<T>::root, t);
        }

        bool lookup(const T& t) {
            return lookup_util(B_Tree<T>::root, t);
        }

        T& min_value() {
            return util_min_value(B_Tree<T>::root);
        }
};
