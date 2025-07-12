#include <bits/stdc++.h>
using namespace std;

// Step 1: Perform DFS and push nodes onto stack by finish time
void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, vis, adj, st);
        }
    }
    st.push(node); // Finished processing, add to stack
}

// Step 3: DFS on transposed graph
void dfs3(int node, vector<int>& vis, vector<int> adjT[]) {
    vis[node] = 1;
    for (auto it : adjT[node]) {
        if (!vis[it]) {
            dfs3(it, vis, adjT);
        }
    }
}

// Kosaraju's Algorithm to find number of Strongly Connected Components (SCCs)
int kosaraju(int V, vector<int> adj[]) {
    vector<int>vis(V, 0);
    stack<int> st;

    // Step 1: Do a DFS and store nodes in stack by finish time
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }

    // Step 2: Transpose the graph
    vector<int> adjT[V];
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            adjT[it].push_back(i); // reverse the edge direction
        }
    }

    // Step 3: DFS on transposed graph in stack order
    fill(vis.begin(), vis.end(), 0); // Reset visited array
    int scc = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            scc++; // New strongly connected component found
            dfs3(node, vis, adjT);
        }
    }

    return scc;
}

// Driver code
int main() {
    int V = 5; // Number of vertices
    vector<int> adj[V];

    // Example graph (directed)
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);

    cout << "Number of Strongly Connected Components: " << kosaraju(V, adj) << "\n";

    return 0;
}
