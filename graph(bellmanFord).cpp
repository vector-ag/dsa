#include <bits/stdc++.h>
using namespace std;

// Function to run Bellman-Ford algorithm from source S
vector<int> bellman(int V, vector<vector<int>>& edges, int S) {
    // Step A: Initialize distance array
    vector<int> dist(V, 1e8);
    dist[S] = 0;

    // Step B: Relax all edges V - 1 times
    for (int i = 0; i < V - 1; i++) {
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            // Step C: Relaxation condition
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Step D: Check for negative weight cycles
    for (auto& it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            // Step E: Return special value to indicate negative cycle
            return { -1 };
        }
    }

    // Step F: Return shortest distances
    return dist;
}

// Main function to test Bellman-Ford
int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int source = 0;

    vector<int> result = bellman(V, edges, source);

    if (result.size() == 1 && result[0] == -1) {
        cout << "Negative weight cycle detected.\n";
    } else {
        cout << "Shortest distances from source node " << source << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "Node " << i << " -> " << result[i] << "\n";
        }
    }

    return 0;
}
