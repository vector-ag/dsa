#include <bits/stdc++.h>
using namespace std;

// Function to find the shortest path from node 1 to node n
vector<int> shortest(int n, int m, vector<vector<int>>& edges) {
    // Step A: Create adjacency list with n+1 nodes (1-indexed)
    vector<pair<int, int>> adj[n + 1];

    // Step B: Build the graph from edge list
    for (auto& it : edges) {
        int u = it[0], v = it[1], w = it[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Step C: Priority queue for Dijkstra (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Step D: Distance and parent arrays
    vector<int> dist(n + 1, 1e9), parent(n + 1);

    // Step E: Initialize distances and parents
    for (int i = 1; i <= n; i++) parent[i] = i;
    dist[1] = 0;

    // Step F: Push the source node
    pq.push({0, 1});

    // Step G: Dijkstra's algorithm
    while (!pq.empty()) {
        auto [dis, node] = pq.top();
        pq.pop();

        // Step H: Check all adjacent nodes
        for (auto& it : adj[node]) {
            int adjNode = it.first;
            int edgeW = it.second;

            // Step I: Relaxation step
            if (dis + edgeW < dist[adjNode]) {
                dist[adjNode] = dis + edgeW;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }

    // Step J: If node n is unreachable
    if (dist[n] == 1e9) return {-1};

    // Step K: Reconstruct the path from n to 1 using parent[]
    vector<int> path;
    int node = n;
    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1); // Add the source
    reverse(path.begin(), path.end());

    return path;
}

// Main function for testing
int main() {
    int n = 5; // number of nodes
    int m = 6; // number of edges

    // Edge format: {u, v, weight}
    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 3, 4},
        {2, 3, 1},
        {2, 4, 7},
        {3, 5, 3},
        {4, 5, 1}
    };

    vector<int> path = shortest(n, m, edges);

    if (path.size() == 1 && path[0] == -1) {
        cout << "No path exists from 1 to " << n << endl;
    } else {
        cout << "Shortest path from 1 to " << n << ":\n";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
