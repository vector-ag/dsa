#include <bits/stdc++.h>
using namespace std;

// Function to find the median of a stream of numbers
void printmedians(int arr[], int n) {
    priority_queue<int> s; // Max-heap for the lower half
    priority_queue<int, vector<int>, greater<int>> g; // Min-heap for the upper half

    s.push(arr[0]);
    cout << "Median after 1 element: " << arr[0] << endl;

    for (int i = 1; i < n; i++) {
        int x = arr[i];

        if (s.size() > g.size()) {
            if (x < s.top()) {
                g.push(s.top());
                s.pop();
                s.push(x);
            } else {
                g.push(x);
            }
            cout << "Median after " << i + 1 << " elements: " 
                 << (s.top() + g.top()) / 2.0 << endl;
        } else {
            if (x <= g.top()) {
                s.push(x);
            } else {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            cout << "Median after " << i + 1 << " elements: " << s.top() << endl;
        }
    }
}

int main() {
    int arr[] = {25, 7, 10, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    printmedians(arr, n);
    return 0;
}
