#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Node {
    int key;
    int priority;
    Node* left;
    Node* right;
    
    Node(int k) : key(k), left(nullptr), right(nullptr) {
        this->priority = rand()%1000;
    }
};

Node* rotate_right(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    return x;
}

Node* rotate_left(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

Node* TREAP_INSERT(Node* root, int key) {
    if (!root) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = TREAP_INSERT(root->left, key);
        if (root->left->priority > root->priority) {
            root = rotate_right(root);
        }
    } else {
        root->right = TREAP_INSERT(root->right, key);
        if (root->right->priority > root->priority) {
            root = rotate_left(root);
        }
    }

    return root;
}

