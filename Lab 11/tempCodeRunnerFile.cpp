#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank;

    DSU(int n) : parent(n), rank(n,0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int v){
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;

        if(rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if(rank[a] == rank[b]) rank[a]++;

        return true;
    }
};

int main(){
   int n, m;
   cin >> n >> m;

   vector<vector<int>> adj(n);

   for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
   }

   DSU dsu(n);

   vector<bool> added(n, false);

   vector<int> result(n);

   int components = 0;

   for(int i = n - 1; i >= 0; i--){
    added[i] = true;
    components++;

    for(int neighbor : adj[i]){
        if(added[neighbor]){
            if(dsu.unite(i, neighbor)){
                components--;
                }
            }
        
        }
        result[i] = components;
    }
    for (int i = 0; i < n; i++) {
        cout << result[i] << "\n";
    }
    return 0;
}