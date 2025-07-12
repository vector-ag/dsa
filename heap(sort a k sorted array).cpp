// k closest elements 
#include<bits/stdc++.h>
using namespace std;

// naive approach
// time complexity: O(n*k)
// space complexity: O(n)
void printkclosest(int arr[], int n, int k, int x) {
    bool visited[n] = {false};
    for(int i=0;i<k;i++){
        int min_diff = INT_MAX;
        int min_index = -1;
        for(int j=0;j<n;j++){
            if(visited[j] == false && abs(arr[j] - x) < min_diff) {
                min_diff = abs(arr[j] - x);
                min_index = j;
            }
        }
        cout << arr[min_index] << " ";
        visited[min_index] = true;
    }
}
// efficient approach
// time complexity: O(n + k*logn)
// Efficient approach
// Time complexity: O(n log k)
class mypair {
public:
    int diff;
    int val;
    mypair(int d, int v) {
        diff = d;
        val = v;
    }
};

// Max heap: Keep k elements with smallest differences
struct compare {
    bool operator()(const mypair &a, const mypair &b) {
        return a.diff < b.diff; // Max heap: larger diff has higher priority
    }
};

void printkclosestEfficient(int arr[], int n, int k, int x) {
    priority_queue<mypair, vector<mypair>, compare> pq;

    for(int i = 0; i < n; i++) {
        int diff = abs(arr[i] - x);
        pq.push(mypair(diff, arr[i]));
        if(pq.size() > k) {
            pq.pop(); // Remove element with largest difference
        }
    }

    // Output k closest elements (order may differ)
    while(!pq.empty()) {
        cout << pq.top().val << " ";
        pq.pop();
    }
}

// main function
int main() {
    int arr[] = {10, 5, 3, 9, 2, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int x = 7;

    cout << "K closest elements (naive): ";
    printkclosest(arr, n, k, x);
    cout << endl;

    cout << "K closest elements (efficient): ";
    printkclosestEfficient(arr, n, k, x);
    cout << endl;

    return 0;
}
