#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], stack<int>& st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis, st);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(int V, vector<int> adj[]) {
    int vis[V] = {0};
    stack<int> st;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }
    vector<int> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    return result;
}
int main() {
    int V = 6; // number of vertices
    vector<int> adj[V];

    // Add directed edges
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    // Run topological sort
    vector<int> result = topologicalSort(V, adj);

    // Print topological sort order
    cout << "Topological Sort: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
// This code implements a topological sort using DFS in a directed graph.