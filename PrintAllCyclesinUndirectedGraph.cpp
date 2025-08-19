// C++ program to find all the 
// cycles in an undirected graph
#include <bits/stdc++.h>
using namespace std;

// Function to check if a node is 
// visited in the current path
bool visited(int node, const vector<int> &path) {
    return find(path.begin(), path.end(), node) != path.end();
}

// Function to rotate a cycle such that 
// it starts with the smallest node
vector<int> rotateToSmallest(vector<int> path) {
    auto minIt = min_element(path.begin(), path.end());
    rotate(path.begin(), minIt, path.end());
    return path;
}

// Function to invert the cycle order
vector<int> invert(vector<int> path) {
    reverse(path.begin(), path.end());
    return rotateToSmallest(path);
}

// Function to check if a cycle is new
bool isNew(const vector<int> &path, 
            vector<vector<int>> &cycles) {
    return find(cycles.begin(), 
            cycles.end(), path) == cycles.end();
}

// Function to find new cycles in the graph
void findNewCycles(vector<int> path, 
    vector<vector<int>> &graph, vector<vector<int>> &cycles) {
    int startNode = path[0];
    int nextNode;
    vector<int> sub;

    // Visit each edge and node of each edge
    for (auto &edge : graph) {
        int node1 = edge[0], node2 = edge[1];

        if (startNode == node1 || startNode == node2) {
            nextNode = (node1 == startNode) ? node2 : node1;

            if (!visited(nextNode, path)) {
                // Neighbor node not on path yet
                sub = {nextNode};
                sub.insert(sub.end(), path.begin(), path.end());
                // Explore extended path
                findNewCycles(sub, graph, cycles);
            } 
            else if (path.size() > 2 && nextNode == path.back()) {
                // Cycle found
                vector<int> p = rotateToSmallest(path);
                vector<int> inv = invert(p);

                if (isNew(p, cycles) && isNew(inv, cycles)) {
                    cycles.push_back(p);
                }
            }
        }
    }
}

// Main function to initiate cycle detection
vector<vector<int>> findCycles(vector<vector<int>> &graph) {

    vector<vector<int>> cycles;

    for (auto &edge : graph) {
        for (int node : edge) {
            findNewCycles({node}, graph, cycles);
        }
    }

    return cycles;
}

int main() {
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {3, 5}, {3, 4}, 
    {4, 7}, {7, 8}, {4, 6}, {6, 5}, {5, 9}, {9, 10}, 
    {10, 6}, {10, 11}, {11, 12}, {12, 13}, {11, 13}};
    vector<vector<int>> cycles = findCycles(graph);
    for (auto &cy : cycles) {
        for (size_t i = 0; i < cy.size(); i++) {
            cout << cy[i];
            if (i != cy.size() - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}