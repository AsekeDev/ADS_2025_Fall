#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* right;
    Node* left;
    Node(int data){
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

class BST{
public:
    Node* root;
    int diameter;
    BST(){
        root = NULL;
        diameter = 0;
    }

    Node* insert(Node* node, int data){
        if(node == NULL){
            node = new Node(data);
            return node;
        }
        if(data <= node->data){
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    int d(Node* root){
        if(root == NULL) return 0;
        int left_height = d(root->left);
        int right_height = d(root->right);
        diameter = max(diameter, left_height + right_height);

        return max(left_height, right_height) + 1;
    }
};

int main(){
    BST tree;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int el;
        cin >> el;
        tree.root = tree.insert(tree.root, el);
    }
    tree.d(tree.root);
    cout << tree.diameter + 1;
    return 0;
}
