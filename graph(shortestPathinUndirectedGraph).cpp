// Shortest path in an undirected graph using 

#include<bits/stdc++.h>
using namespace std;

vector<int>shortestPath(vector<vector<int>>& edges,int N,int M,int src){
    vector<int>adj[N];
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]); // Since the graph is undirected
    }
    vector<int>dist(N, INT_MAX);
    dist[src] = 0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    vector<int>result(N, -1);
    for(int i = 0; i < N; i++){
        if(dist[i] != INT_MAX){
            result[i] = dist[i];
        }
    }
    return result;    

} 
int main() {
    int N = 5; // Number of vertices
    int M = 6; // Number of edges
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 4}
    };
    int src = 0; // Starting node

    vector<int> result = shortestPath(edges, N, M, src);

    cout << "Shortest path distances from source node " << src << ": ";
    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}