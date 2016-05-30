#pragma once
#include <iostream>
#include <queue>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <stack>
#include <utility>
#include <list>

using namespace std;

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

        bool is_leaf() {
            return left == NULL && right == NULL;
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

        void util_print_paths(B_Node<T>* n, T arr[], int len) {
            if(n == NULL) {
                std::cout << "()" << std::endl;
                return;
            }
            if(n -> is_leaf()) {
                std::cout << "(";
                std::copy(arr, arr + len, 
                        std::ostream_iterator<T>(std::cout, " "));
                std::cout << (n -> data);
                std::cout << ")" << std::endl;
                return;
            }
            arr[len] = (n -> data);
            if((n -> left) != NULL) 
                util_print_paths((n -> left), arr, len + 1);
            if((n -> right) != NULL) 
                util_print_paths((n -> right), arr, len + 1);
        }

        void kmad_util_print_paths(B_Node<T>* n) {
            if(n == NULL) cout << "()" << endl;

            //typedef B_Node<T>* b_node_ptr;
            typedef list<B_Node<T>* > b_node_list;
            typedef pair<B_Node<T>* , b_node_list > pp_pair;

            b_node_list l;
            stack<pp_pair> s;

            l.push_back(n);
            s.push(pp_pair(n, l));

            while(!s.empty()) {
                pp_pair top = s.top();
                s.pop();

                B_Node<T>*  curr_node = top.first;
                b_node_list curr_list = top.second;

                if(curr_node -> is_leaf()) {
                    cout << "(";
                    for(typename b_node_list::const_iterator i = curr_list.begin();
                            i != curr_list.end(); i++) {
                        cout << ((*i) -> data) << " ";
                    }
                    cout << ")" << endl;
                    continue;
                }

                if((curr_node -> left) != NULL) {
                    b_node_list left_list(curr_list);
                    left_list.push_back((curr_node -> left));
                    s.push(pp_pair((curr_node -> left), left_list));
                }

                if((curr_node -> right) != NULL) {
                    b_node_list right_list(curr_list);
                    right_list.push_back((curr_node -> right));
                    s.push(pp_pair((curr_node -> right), right_list));
                }
            }

        }

        void util_mirror(B_Node<T>* n) {
            if(n != NULL) {
                swap(n -> left, n -> right);
                util_mirror(n -> left);
                util_mirror(n -> right);
            }
        }

        void util_double_tree(B_Node<T>* n) {
            if(n != NULL) {
                B_Node<T>* new_node = new B_Node<T>(n -> data);
                (new_node -> left) = (n -> left);
                (n -> left) = new_node;
                util_double_tree(new_node -> left);
                util_double_tree(n -> right);
            }
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

        void print_paths() {
            int max_depth = B_Tree::max_depth();
            T* arr = new T[max_depth];
            util_print_paths(root, arr, 0);
            delete[] arr;
        }

        void print_paths2() {
            kmad_util_print_paths(root);
        }

        void mirror() {
            util_mirror(root);
        }

        void double_tree() {
            util_double_tree(root);
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
