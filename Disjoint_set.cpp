#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (DSU) / Union-Find Data Structure
class DisjointSet {
    vector<int> rank, parent,size;

public:
    // Constructor initializes the DSU for 'n' elements
    DisjointSet(int n) {
        rank.resize(n + 1, 0);   // rank stores the depth of trees
        parent.resize(n + 1);    // parent[i] is the representative of the set containing i
        for (int i = 0; i <= n; i++) {
            parent[i] = i;       // initially, every element is its own parent (singleton set)
        }
    }

    // Find the ultimate parent of a node with path compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        // Path compression: flattening the tree structure for efficiency
        return parent[node] = findUPar(parent[node]);
    }

    // Union two sets by their rank (depth)
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); // Find ultimate parent of u
        int ulp_v = findUPar(v); // Find ultimate parent of v

        if (ulp_u == ulp_v) return; // They are already in the same set

        // Union by rank: attach smaller depth tree under bigger depth tree
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++; // Increase rank since both trees had same rank
        }
    }
    // Union two sets by size (number of nodes)
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        // Attach smaller set under the larger one
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// Driver code to demonstrate DSU functionality
int main() {
    DisjointSet ds(7); // Create DSU with 7 nodes: 1 through 7

    // Union some sets
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // Check if 3 and 7 are in the same set
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "3 and 7 are in the same set\n";
    } else {
        cout << "3 and 7 are in different sets\n";
    }

    // Union sets containing 3 and 7
    ds.unionByRank(3, 7);

    // Now check again
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Now 3 and 7 are in the same set\n";
    } else {
        cout << "Still in different sets\n";
    }

    return 0;
}
