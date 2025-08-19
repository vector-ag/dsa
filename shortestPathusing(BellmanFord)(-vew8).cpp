#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<pair<int,int>, long long>> edges;  // (u,v), weight

    for (int i = 0; i < m; i++) {
        int a, b;
        long long x;
        cin >> a >> b >> x;
        edges.push_back({{a, b}, -x});  // negate weight for longest path
    }

    vector<long long> dist(n+1, INF);
    dist[1] = 0;

    // Bellman-Ford relaxations
    for (int i = 1; i <= n-1; i++) {
        for (auto &e : edges) {
            int u = e.first.first;
            int v = e.first.second;
            long long w = e.second;
            if (dist[u] < INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Detect negative cycles
    vector<int> affected(n+1, 0);
    for (auto &e : edges) {
        int u = e.first.first;
        int v = e.first.second;
        long long w = e.second;
        if (dist[u] < INF && dist[u] + w < dist[v]) {
            affected[v] = 1;  // node influenced by cycle
        }
    }

    // Propagate cycle influence
    queue<int> q;
    vector<int> vis(n+1, 0);
    for (int i = 1; i <= n; i++) {
        if (affected[i]==1) {// if node is affected by a negative cycle
            q.push(i);
            vis[i] = 1;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &e : edges) {
            if (e.first.first == u && !vis[e.first.second]) {
                vis[e.first.second] = 1;
                q.push(e.first.second);
            }
        }
    }

    if (vis[n]==1) {//remove this line if you want to print -1 for infinite max score
        // If node n is reachable from a negative cycle
        cout << -1 << "\n";  // infinite max score
    } else {
        cout << -dist[n] << "\n";  // negate back
    }

    return 0;
}
