#include <bits/stdc++.h>
using namespace std;

// Disjoint Set (Union-Find) with Union by Rank only
class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find with path compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Union by rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

// Kruskal's Algorithm
int kruskal(int V, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
        return a[2] < b[2]; // Sort edges by weight
    });

    DisjointSet ds(V);
    int mstWeight = 0;

    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], wt = edge[2];

        if (ds.findUPar(u) != ds.findUPar(v)) {
            mstWeight += wt;
            ds.unionByRank(u, v);
            cout << "Edge added to MST: " << u << " - " << v << " with weight " << wt << '\n';
        }
    }

    return mstWeight;
}

// Driver code
int main() {
    int V = 6; // Number of vertices (1-based indexing assumed)
    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 3, 4},
        {2, 3, 1},
        {2, 4, 7},
        {3, 5, 3},
        {4, 6, 1},
        {5, 4, 2},
        {5, 6, 5}
    };

    cout << "Kruskal's MST using Union By Rank:\n";
    int mstWeight = kruskal(V, edges);
    cout << "Total Weight of MST: " << mstWeight << "\n";

    return 0;
}
