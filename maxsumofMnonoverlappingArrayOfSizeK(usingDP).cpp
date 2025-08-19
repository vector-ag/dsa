// Approach: DP with memoization
// Language: C++

#include <bits/stdc++.h>
using namespace std;

// Recursive function to find the maximum sum of M non-overlapping subarrays
int solve(vector<int> &arr, int n, int m, int k, int idx, vector<vector<int>> &memo) {
    // Base case: If we have selected M subarrays, return 0
    if (m == 0) {
        return 0;
    }
    
    // If the index is beyond the valid range, return a minimum value
    if (idx > n - k) {
        return INT_MIN;
    }
    
    // If the result is already computed, return it from memo
    if (memo[idx][m] != -1) {
        return memo[idx][m];
    }
    
    // Calculate sum of the current subarray of size K
    int sum = accumulate(arr.begin() + idx, arr.begin() + idx + k, 0);
    
    // Option 1: Take the current subarray and move to the next non-overlapping subarray
    int take = sum + solve(arr, n, m - 1, k, idx + k, memo);
    
    // Option 2: Skip the current element and check the next index
    int skip = solve(arr, n, m, k, idx + 1, memo);
    
    // Store the maximum of both choices in memo and return it
    return memo[idx][m] = max(take, skip);
}

// Function to initialize memoization table and call the recursive function
int maxSumMSubarrays(vector<int> &arr, int n, int m, int k) {
    vector<vector<int>> memo(n, vector<int>(m + 1, -1)); // Initialize memo table with -1
    return solve(arr, n, m, k, 0, memo);
}

int main() {
    vector<int> arr = {2, 10, 7, 18, 5, 33, 0}; // Input array
    int n = arr.size(), m = 3, k = 1; // Define number of subarrays and their size
    cout << maxSumMSubarrays(arr, n, m, k) << endl; // Output the result
    return 0;
}