#include <bits/stdc++.h>
using namespace std;

// Function to perform Dijkstra's algorithm
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    // Min-heap priority queue: (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Distance array to store shortest distances from source to all vertices
    vector<int> dist(V, 1e9);

    // Step 1: Initialize distance of source to itself as 0
    dist[S] = 0;

    // Step 2: Push the source node into the priority queue
    pq.push({0, S});

    // Step 3: Loop until priority queue is empty
    while (!pq.empty()) {
        // Step 4: Extract node with minimum distance
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Step 5: Traverse all adjacent nodes of current node
        for (auto it : adj[node]) {
            int adjNode = it[0];
            int edgeWeight = it[1];

            // Step 6: If a shorter path is found
            if (dis + edgeWeight < dist[adjNode]) {
                // Step 7: Update distance
                dist[adjNode] = dis + edgeWeight;

                // Step 8: Push updated distance into the priority queue
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    // Step 9: Return the final distances from source
    return dist;
}

// Main function to drive the program
int main() {
    int V = 5; // Step A: Number of vertices

    // Step B: Create adjacency list
    vector<vector<int>> adj[V];

    // Step C: Add undirected edges with weights (u <-> v, weight)
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

    int source = 0; // Step D: Define the source node

    // Step E: Call Dijkstra function
    vector<int> distances = dijkstra(V, adj, source);

    // Step F: Print the shortest distances from source
    cout << "Shortest distances from source node " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << " -> " << distances[i] << "\n";
    }

    return 0;
}
