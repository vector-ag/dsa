#include <bits/stdc++.h>
using namespace std;

// Dijkstra's algorithm using set instead of priority queue
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    // Set to store (distance, node) sorted by distance
    set<pair<int, int>> st;

    // Distance array to hold shortest distances from source
    vector<int> dist(V, 1e9);

    // Step 1: Initialize source
    dist[S] = 0;
    st.insert({0, S});

    // Step 2: Process nodes from set
    while (!st.empty()) {
        // Step 3: Get the node with minimum distance
        auto it = *(st.begin());
        int node = it.second; 
        int dis = it.first;
        st.erase(it);

        // Step 4: Visit all adjacent nodes
        for (auto edge : adj[node]) {
            int adjNode = edge[0];
            int edgeW = edge[1];

            // Step 5: If a shorter path is found
            if (dis + edgeW < dist[adjNode]) {
                // Step 6: Remove old entry if it exists
                if (dist[adjNode] != 1e9) {
                    st.erase({dist[adjNode], adjNode});
                }
                // Step 7: Update distance and insert new pair
                dist[adjNode] = dis + edgeW;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }

    // Step 8: Return all shortest distances from source
    return dist;
}

// Main function to test the implementation
int main() {
    int V = 5; // Number of vertices

    // Step A: Adjacency list of vector of {adjNode, weight}
    vector<vector<int>> adj[V];

    // Step B: Add undirected edges
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({2, 4});
    adj[2].push_back({0, 4});

    adj[1].push_back({2, 1});
    adj[2].push_back({1, 1});

    adj[1].push_back({3, 7});
    adj[3].push_back({1, 7});

    adj[2].push_back({4, 3});
    adj[4].push_back({2, 3});

    int source = 0;

    // Step C: Call the Dijkstra function
    vector<int> distances = dijkstra(V, adj, source);

    // Step D: Print results
    cout << "Shortest distances from source node " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << " -> " << distances[i] << "\n";
    }

    return 0;
}
