#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;
    int diameter;
    BST() {
        root = NULL;
        diameter = 0;
    }

    Node* insert(Node* node, int data) {
        if (node == NULL) return new Node(data);
        if (data < node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);
        return node;
    }

    int height(Node* node) {
        if (!node) return 0;
        int left = height(node->left);
        int right = height(node->right);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }

    int getDiameter() {
        diameter = 0;
        int h = height(root);
        return diameter + 1;
    }
};

int main() {
    BST tree;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int el;
        cin >> el;
        tree.root = tree.insert(tree.root, el);
    }
    cout << tree.getDiameter();
    return 0;
}
