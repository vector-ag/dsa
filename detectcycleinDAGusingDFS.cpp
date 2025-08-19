#include<bits/stdc++.h>
using namespace std;
// Detect cycle in a directed graph using DFS
// if the graph is cyclic, it will return true, otherwise false
bool dfs(int node,int vis[],int pathvis[],vector<int>adj[]){
    vis[node] =1;
    pathvis[node] = 1;
    // trraverse all the adjacent nodes of the current node
    for(auto it : adj[node]){
        // when node is not visited
        if(vis[it] == 0){
            if(dfs(it,vis,pathvis,adj) == true){
                return true;
            }
        }
        //if node has previoiusly been visited and is in the current path
        // then it means there is a cycle
        else if(pathvis[it] == 1){
            return true;
        }
    }
    pathvis[node] = 0; // backtrack
    return false;
}


bool incycle(int n,vector<int>adj[]){// n = no. of vertices
    int vis[n] = {0};
    int pathvis[n] = {0};
    for(int i=0;i<n;i++){
        if(vis[i] == 0){
            if(dfs(i,vis,pathvis,adj)== true)return true;
        }
    }
    return false;
}