//write a program to calculate the sum of bottom-most leaves in a binary tree
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        left = NULL;
        right = NULL;
        data = d;
    }
};


Node *get_BTree1() {
    Node* root = new Node(1);
    (root -> left) = new Node(2);
    (root -> right) = new Node(8);
    return root;
}

void util_get_bottom_most(Node *n, int curr_lvl, int depth, int& result) {
    if(n == NULL) return;
    if(curr_lvl == depth) {
        result += (n -> data);
        return;
    }
    util_get_bottom_most(n -> left, curr_lvl + 1, depth, result);
    util_get_bottom_most(n -> right, curr_lvl + 1, depth, result);
}

int get_depth(Node* n) {
    if(n != NULL) {
        return 1 + max(get_depth(n -> left), get_depth(n -> right));
    }
    return 0;
}

int get_bottom_most_sum(Node *n) {
    int result = 0;
    int depth = get_depth(n);
    if(n == NULL) return 0;
    util_get_bottom_most(n, 1, depth, result);
    return result;
}

int main()
{
    string delim = string(20, '#') + '\n';
    Node* b1 = get_BTree1();
    cout << "sume of bottom most leaves = " << get_bottom_most_sum(b1) << endl;
    cout << delim;
}
