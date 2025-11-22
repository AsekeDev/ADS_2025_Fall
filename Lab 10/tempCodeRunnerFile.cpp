#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool BFS(int s, int f, vector<vector<int>>& adj){
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while(q.empty()){
        int v = q.front();
        q.pop();

        if(v == f){
            return true;
        }
        for(int i = 0; i < adj[v].size(); i++){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return false;
}

int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int s, f;
    cin >> s >> f;

    if(BFS(s,f, adj)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}