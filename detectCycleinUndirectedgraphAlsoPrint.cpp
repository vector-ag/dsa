#include<bits/stdc++.h>
using namespace std;
vector<int> build(vector<int>& parent, int u, int v) {
    vector<int> path1, path2;

    // climb from u to root
    while (u != -1) {
        path1.push_back(u);
        u = parent[u];
    }

    // climb from v to root
    while (v != -1) {
        path2.push_back(v);
        v = parent[v];
    }

    // reverse to start from root
    reverse(path1.begin(), path1.end());
    reverse(path2.begin(), path2.end());

    // find LCA
    int i = 0;
    while (i < path1.size() && i < path2.size() && path1[i] == path2[i]) {
        i++;
    }
    i--; // index of LCA

    // build cycle: u -> ... -> LCA -> ... -> v -> u
    vector<int> cycle;
    for (int j = path1.size()-1; j >= i; j--) cycle.push_back(path1[j]);
    for (int j = i+1; j < path2.size(); j++) cycle.push_back(path2[j]);
    cycle.push_back(cycle[0]);

    return cycle;
}

vector<int>bfs(vector<vector<int>>&adj,int node,vector<int>&vis,vector<int>&parent){
    queue<int>q;
    q.push(node);
    vis[node] = 1;
    vector<int>ans;
    while(!q.empty()){
        int val = q.front();
        q.pop();
        for(auto it : adj[val]){
            if(vis[it] != 1){
                vis[it] = 1;
                parent[it] = val;
                q.push(it);
            }
            else if(parent[val] != it){
                ans = build(parent,val,it);
                return ans;
            }
        }
    }
    return {};
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>>adj(n+1);
    vector<int>indeg(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        indeg[a]++;
        indeg[b]++;
    }
    vector<int>vis(n+1,0);
    vector<int>ans;
    vector<int>parent(n+1,-1);
    for(int i=1;i<=n;i++){
        if(vis[i] == 0){
            ans = bfs(adj,i,vis,parent);
            if(!ans.empty())break;
        }
    }
    if(ans.size() == 0)cout << "IMPOSSIBLE" << endl;
    else {
        cout << ans.size() << endl;
        for(int i=0;i<(int)ans.size();i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}