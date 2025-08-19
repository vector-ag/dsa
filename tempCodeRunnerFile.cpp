#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>> n >> m;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    vector<vector<long long>>dist(n+1,vector<long long>(2,1e18));
    dist[1][0] = 0;
    priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>>pq;
    pq.push({{0,1},0});
    while(!pq.empty()){
        int dis = pq.top().first.first;
        int node = pq.top().first.second;
        int used = pq.top().second;
        if(dis > dist[node][used])continue;
        for(auto it : adj[node]){
            int adjnode = it.first;
            int edw = it.second;
            if(dis + edw < dist[adjnode][used]){
                dist[adjnode][used] = dis + edw;
                pq.push({{dist[adjnode][used],adjnode},used});
            }
            if(used == 0){
                long long newdis = dis + edw/2;
                if(dis + edw/2 < dist[adjnode][1]){
                    dist[adjnode][1] = newdis;
                    pq.push({{dist[adjnode][1],adjnode},1});
                }
            }
        }
    }
    long long ans = min(dist[n][1],dist[n][0]);
    cout << ans << endl;
}