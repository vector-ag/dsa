#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(0, graph, path, res);
        return res;
    }

private:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& res) {
        path.push_back(node);

        if (node == graph.size() - 1) { // reached target
            res.push_back(path);
        } else {
            for (int next : graph[node]) {
                dfs(next, graph, path, res);
            }
        }

        path.pop_back(); // backtrack
    }
};

int main() {
    Solution s;
    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    vector<vector<int>> result = s.allPathsSourceTarget(graph);

    for (auto &p : result) {
        for (int node : p) cout << node << " ";
        cout << "\n";
    }
}
