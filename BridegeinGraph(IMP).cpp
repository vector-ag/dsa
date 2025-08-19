#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer;
    
    // DFS function for Tarjan's algorithm
    void dfs(int node, int parent, vector<int>& vis, vector<int> adj[], vector<int>& tin, vector<int>& low, vector<vector<int>>& bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        
        for (auto it : adj[node]) {
            if (it == parent) continue; // Skip the edge leading back to parent
            
            if (vis[it] == 0) {
                
                dfs(it, node, vis, adj, tin, low, bridges);
                
                low[node] = min(low[node], low[it]);
                
                // Condition for bridge
                if (low[it] > tin[node]) {
                    bridges.push_back({node, it});  // bridge found
                }
            } else {
                // Back edge case (to already visited node)
                low[node] = min(low[node], tin[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        
        // Building adjacency list
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n, 0), tin(n, 0), low(n, 0);
        vector<vector<int>> bridges;
        timer = 1;
        
        // DFS from all components (handles disconnected graph too)
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i, -1, vis, adj, tin, low, bridges);
        }
        
        return bridges;
    }
};
int main() {
    Solution sol;
    int n = 5; // Number of nodes
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};
    
    vector<vector<int>> result = sol.criticalConnections(n, connections);
    
    cout << "Critical Connections (Bridges):" << endl;
    for (auto& bridge : result) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }
    
    return 0;
}