#include <bits/stdc++.h>
using namespace std;

void shortestPath(vector<vector<int>> &matrix) {
    int n = matrix.size();

    // Replace -1 with a large value (treated as infinity), and 0 for self-loops
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1)
                matrix[i][j] = 1e9;
            if (i == j)
                matrix[i][j] = 0;
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][k] < 1e9 && matrix[k][j] < 1e9) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    // Optional: Replace 1e9 back with -1 to indicate no path
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1e9)
                matrix[i][j] = -1;
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(n, -1));
    cout << "Enter edges in the format (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        matrix[u][v] = w; // For undirected graph, add matrix[v][u] = w as well
    }

    shortestPath(matrix);

    cout << "All pairs shortest path matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
