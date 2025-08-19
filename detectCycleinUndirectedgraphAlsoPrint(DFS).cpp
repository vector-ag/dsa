#include <iostream>
#include <vector>
using namespace std;

// Function to run DFS and detect a cycle
bool dfs(int current, int parent,
         vector<vector<int>>& adj,
         vector<int>& parentNode,
         vector<bool>& visited,
         vector<int>& cycle) 
{
    visited[current] = true;
    parentNode[current] = parent;

    for (int neighbor : adj[current]) {
        if (neighbor == parent) continue; // ignore edge back to parent

        if (visited[neighbor]) {
            // Found a cycle (back edge)
            cycle.push_back(current);

            // Walk back from current to neighbor using parent array
            int node = current;
            while (node != neighbor) {
                node = parentNode[node];
                cycle.push_back(node);
            }

            cycle.push_back(current); // close the cycle
            return true;
        } 
        else {
            if (dfs(neighbor, current, adj, parentNode, visited, cycle))
                return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    // adjacency list
    vector<vector<int>> adj(n + 1);

    // read edges
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<int> parentNode(n + 1, -1);
    vector<int> cycle;

    // Try DFS from every node (in case the graph is disconnected)
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, parentNode, visited, cycle)) {
                cout << cycle.size() << "\n";
                for (int node : cycle) {
                    cout << node << " ";
                }
                cout << "\n";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
