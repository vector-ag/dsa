//shortest path in DAG
// Shortest path in a Directed Acyclic Graph (DAG) using Topological Sort


#include<bits/stdc++.h>
using namespace std;

void topologicalSortUtil(int node, vector<pair<int, int>> adj[], int vis[], stack<int>& st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it.first]) {
            topologicalSortUtil(it.first, adj, vis, st);
        }
    }
    st.push(node);
}


vector<int>ShortestPath(int n, int m, vector<int>edges[]){
    vector<pair<int, int>>adj[n];
    for(int i=0;i<n;i++){
        int u = edges[i][0];// Starting node of the edge
        int v = edges[i][1];// Ending node of the edge
        int w = edges[i][2];// Weight of the edge
        adj[u].push_back({v, w});
    }
    // find topological sort
    int vis[n] = {0};
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topologicalSortUtil(i, adj, vis, st);
        }
    }
    // step 2 dist thing

    vector<int>dist(n, INT_MAX);
    dist[0] = 0; // Assuming the source node is 0
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(dist[node] != INT_MAX){
            for(auto it : adj[node]){
                int v = it.first;
                int w = it.second;
                if(dist[node] + w < dist[v]){
                    dist[v] = dist[node] + w;
                }
            }
        }
    }
    vector<int>result(n, -1);
    for(int i = 0; i < n; i++){
        if(dist[i] != INT_MAX){
            result[i] = dist[i];
        }
    }
    return result;

}
int main() {
    int n = 5; // Number of vertices
    int m = 6; // Number of edges
    vector<int> edges[] = {
        {0, 1, 2},
        {0, 2, 3},
        {1, 3, 6},
        {2, 3, 1},
        {3, 4, 5},
        {2, 4, 4}
    };
    
    vector<int> result = ShortestPath(n, m, edges);
    
    cout << "Shortest path distances from source node 0: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}