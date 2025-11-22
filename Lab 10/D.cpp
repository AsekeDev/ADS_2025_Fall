#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(vector<vector<int>>& adj, int vert, vector<bool>& isred) {
    int n = adj.size();

    vector<bool> visited(n, false);
    vector<int> distance(n, -1);

    queue<int> q;
    q.push(vert);
    visited[vert] = true;
    distance[vert] = 0;
    
    if (isred[vert]) {
        return 0;
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < adj[v].size(); i++) {
            int el = adj[v][i];
            
            if (isred[el]) {
                return distance[v] + 1;
            }
            
            if (!visited[el]) {
                visited[el] = true;
                distance[el] = distance[v] + 1;
                q.push(el);
            }
        }
    }
    return -1;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<vector<int>> adj(n + 1);
    vector<bool> isred(n + 1, false);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for (int i = 0; i < q; i++) {
        int qu;
        cin >> qu;
        if (qu == 2) {
            int vert;
            cin >> vert;
            cout << BFS(adj, vert, isred) << endl;
        } else if (qu == 1) {
            int vert;
            cin >> vert;
            isred[vert] = true;
        }
    }
    return 0;
}