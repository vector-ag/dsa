// Kahns Algorithm for Topological Sorting using bfs

#include<bits/stdc++.h>
using namespace std;

vector<int> kahnsAlgorithm(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    return topoOrder;
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

    // Run Kahn's algorithm for topological sorting
    vector<int> result = kahnsAlgorithm(V, adj);

    // Print topological sort order
    cout << "Topological Sort using Kahn's Algorithm: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
