#include <bits/stdc++.h>
using namespace std;

// Prim's algorithm for MST
int spanningTree(int V, vector<vector<int>> adj[]) {
    // Min-heap priority queue to store {weight, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Vector to keep track of visited nodes (initially all 0 - unvisited)
    vector<int> vis(V, 0); // ✅ FIXED

    // Start from node 0 with weight 0
    pq.push({0, 0});
    int sum = 0; // Store total weight of MST

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second; // Current node
        int wt = it.first;    // Edge weight to reach this node

        // If already visited, skip
        if (vis[node] == 1) continue;

        vis[node] = 1;     // Mark node as visited
        sum += wt;         // Add edge weight to MST sum

        // Traverse all adjacent nodes
        for (auto it : adj[node]) {
            int adjNode = it[0]; // Adjacent node
            int edW = it[1];     // Edge weight to adjacent node

            if (!vis[adjNode]) {
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adj[V];

    // Adding undirected edges to adjacency list
    // Format: adj[u].push_back({v, weight});
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    // Compute MST weight
    int mstWeight = spanningTree(V, adj);
    cout << "Total weight of MST: " << mstWeight << endl;

    return 0;
}
