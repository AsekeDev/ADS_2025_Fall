#include <iostream>
#include <vector>
#include <queue>
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

int main() {
    int n;
    cin >> n; 
    vector<Node*> nodes(n + 1, NULL);


    for (int i = 1; i <= n; i++) {
        nodes[i] = new Node(i);
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0) nodes[x]->left = nodes[y];  
        else         nodes[x]->right = nodes[y];
    }

    Node* root = nodes[1]; 

    queue<Node*> q;
    q.push(root);
    int maxWidth = 0;

    while (!q.empty()) {
        int levelSize = q.size();          
        maxWidth = max(maxWidth, levelSize); 


        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();

            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
        }
    }

    cout << maxWidth << endl;
    return 0;
}
