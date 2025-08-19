#include<bits/stdc++.h>
using namespace std;
// use this code to detect cycle in a directed graph using BFS
// if the graph is cyclic, it will return the elements in the cycle
vector<int>cycle(int V,vector<int>adj[]){
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int>elementincycle;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    for(int i=0;i<V;i++){
        if(indegree[i] != 0){
            elementincycle.push_back(i);
        }
    }
    return elementincycle;
}